
#include "common/Message.h"
#include "common/Logger.h"
#include "common/ByteStream.h"
#include "MsgVersatility.h"
#include "MsgField.h"

std::map<std::string, std::vector<FieldDefine>> g_structdef_map;
std::map<int, std::vector<FieldDefine>> g_msgdef_map;

MsgVersatility::MsgVersatility() :
	Message(0, 0)
{
}

size_t MsgVersatility::getFieldLength(const FieldDefine &def, const FieldValue &val) const
{
	if (!def.vec)
	{
		switch (def.type)
		{
		case 'b':	return sizeof(char);		break;
		case 'h':	return sizeof(short);		break;
		case 'i':	return sizeof(int);			break;
		case 'l':	return sizeof(long long);	break;
		case 'f':	return sizeof(float);		break;
		case 'd':	return sizeof(double);		break;
		case 's':	return sizeof(unsigned short) + strlen(val.getString());	break;
		case 't':
			{
				size_t len = sizeof(unsigned short);
				for (size_t i = 0; i < def.childs.size(); ++i)
				{
					const FieldValue *child = val.getChild(i);
					if (child != nullptr)
					{
						len += getFieldLength(def.childs[i], *child);
					}
				}
				return len;
			}
			break;
		}
	}
	else
	{
		size_t len = sizeof(unsigned short);
		size_t count = val.getChildCount();
		if (count == 0)
		{
			return len;
		}

		switch (def.type)
		{
		case 'b':	return sizeof(char) * count;		break;
		case 'h':	return sizeof(short) * count;		break;
		case 'i':	return sizeof(int) * count;			break;
		case 'l':	return sizeof(long long) * count;	break;
		case 'f':	return sizeof(float) * count;		break;
		case 'd':	return sizeof(double) * count;		break;
		case 's':	return (sizeof(unsigned short) + strlen(val.getString())) * count;	break;
		case 't':
			{
				size_t len2 = sizeof(unsigned short);
				for (size_t i = 0; i < def.childs.size(); ++i)
				{
					const FieldValue *child = val.getChild(i);
					if (child != nullptr)
					{
						len2 += getFieldLength(def.childs[i], *child);
					}
				}
				len += len2 * count;
			}
			break;
		}
	}
	return 0;
}

size_t MsgVersatility::getLength() const
{
	size_t length = 0;

	std::vector<FieldDefine> fields;
	for (size_t i = 0; i < fields.size(); ++i)
	{
		if (i < m_vals.size())
		{
			length += getFieldLength(fields[i], m_vals[i]);
		}
	}

	return length + 6;
}

bool MsgVersatility::serializeField(ByteStream &s, const FieldDefine &def, const FieldValue &val) const
{
	if (!def.vec)
	{
		switch (def.type)
		{
		case 'b':	s << val.getInt8();		break;
		case 'h':	s << val.getInt16();	break;
		case 'i':	s << val.getInt32();	break;
		case 'l':	s << val.getInt64();	break;
		case 'f':	s << val.getFloat();	break;
		case 'd':	s << val.getDouble();	break;
		case 's':	s << val.getString();	break;
		case 't':
			for (size_t i = 0; i < def.childs.size() && i < val.getChildCount(); ++i)
			{
				serializeField(s, def.childs[i], *val.getChild(i));
			}
			break;
		}
	}
	else
	{
		unsigned short count = (unsigned short)val.getChildCount();
		s << count;
		for (int i = 0; i < count; ++i)
		{
			const FieldValue *child = val.getChild(i);
			if (NULL == child)
				continue;

			switch (def.type)
			{
			case 'b':	s << child->getInt8();		break;
			case 'h':	s << child->getInt16();		break;
			case 'i':	s << child->getInt32();		break;
			case 'l':	s << child->getInt64();		break;
			case 'f':	s << child->getFloat();		break;
			case 'd':	s << child->getDouble();	break;
			case 's':	s << child->getString();	break;
			case 't':
				for (size_t j = 0; j < def.childs.size() && j < val.getChildCount(); ++j)
				{
					serializeField(s, def.childs[j], *child->getChild(j));
				}
				break;
			}
		}
	}

	return true;
}

bool MsgVersatility::serialize(ByteStream &s) const
{
	auto it = g_msgdef_map.find((getCategory() << 16) | getID());
	if (it == g_msgdef_map.end())
	{
		return false;
	}

	std::vector<FieldDefine> &defs = it->second;
	for (size_t i = 0; i < defs.size() && i < m_vals.size(); ++i)
	{
		serializeField(s, defs[i], m_vals[i]);
	}

	return true;
}

bool MsgVersatility::unserializeField(ByteStream &s, const FieldDefine &def, FieldValue &val)
{
	if (!def.vec)
	{
		switch (def.type)
		{
		case 'b':	val.setInt8(s.read_char());			break;
		case 'h':	val.setInt16(s.read_int16());		break;
		case 'i':	val.setInt32(s.read_int32());		break;
		case 'l':	val.setInt64(s.read_int64());		break;
		case 'f':	val.setFloat(s.read_float());		break;
		case 'd':	val.setDouble(s.read_double());		break;
		case 's':	val.setString(s.read_string());		break;
		case 't':
			val.setChildCount(def.childs.size());
			for (size_t i = 0; i < def.childs.size(); ++i)
			{
				unserializeField(s, def.childs[i], *val.getChild(i));
			}
			break;
		}
	}
	else
	{
		unsigned short count = (unsigned short)s.read_int16();
		if (count == 0)
		{
			return true;
		}

		val.setChildCount(count);

		for (size_t i = 0; i < count; ++i)
		{
			FieldValue *child = val.getChild(i);
			switch (def.type)
			{
			case 'b':	child->setInt8(s.read_char());		break;
			case 'h':	child->setInt16(s.read_int16());	break;
			case 'i':	child->setInt32(s.read_int32());	break;
			case 'l':	child->setInt64(s.read_int64());	break;
			case 'f':	child->setFloat(s.read_float());	break;
			case 'd':	child->setDouble(s.read_double());	break;
			case 's':	child->setString(s.read_string());	break;
			case 't':
				child->setChildCount(def.childs.size());
				for (size_t i = 0; i < def.childs.size(); ++i)
				{
					unserializeField(s, def.childs[i], *child->getChild(i));
				}
				break;
			}
		}
	}

	return true;
}

bool MsgVersatility::unserialize(ByteStream &s)
{
	auto it = g_msgdef_map.find((getCategory() << 16) | getID());
	if (it == g_msgdef_map.end())
	{
		return false;
	}

	std::vector<FieldDefine> &defs = it->second;
	m_vals.clear();
	m_vals.resize(defs.size());
	for (size_t i = 0; i < defs.size(); ++i)
	{
		unserializeField(s, defs[i], m_vals[i]);
	}

	return true;
}

static void push(lua_State *L, int index, const FieldDefine &def, const FieldValue &val)
{
	if (!def.vec)
	{
		switch (def.type)
		{
		case 'b':	lua::settable(L, index, def.name.c_str(), val.getInt8());	break;
		case 'h':	lua::settable(L, index, def.name.c_str(), val.getInt16());	break;
		case 'i':	lua::settable(L, index, def.name.c_str(), val.getInt32());	break;
		case 'l':	lua::settable(L, index, def.name.c_str(), val.getInt64());	break;
		case 'f':	lua::settable(L, index, def.name.c_str(), val.getFloat());	break;
		case 'd':	lua::settable(L, index, def.name.c_str(), val.getDouble());	break;
		case 's':	lua::settable(L, index, def.name.c_str(), val.getString());	break;
		case 't':
			lua::newtable(L);
			for (size_t i = 0; i < def.childs.size() && i < val.getChildCount(); ++i)
			{
				push(L, -1, def.childs[i], *val.getChild(i));
			}
			lua::settable(L, (index > 0) ? index : index - 1, def.name.c_str());
			break;
		}
	}
	else
	{
		lua::newtable(L);
		unsigned short count = (unsigned short)val.getChildCount();
		//s << count;
		for (int i = 0; i < count; ++i)
		{
			const FieldValue *child = val.getChild(i);

			switch (def.type)
			{
			case 'b':	lua::settable(L, index, i +1, val.getInt8());		break;
			case 'h':	lua::settable(L, index, i +1, val.getInt16());		break;
			case 'i':	lua::settable(L, index, i +1, val.getInt32());		break;
			case 'l':	lua::settable(L, index, i +1, val.getInt64());		break;
			case 'f':	lua::settable(L, index, i +1, val.getFloat());		break;
			case 'd':	lua::settable(L, index, i +1, val.getDouble());		break;
			case 's':	lua::settable(L, index, i +1, val.getString());		break;
			case 't':
				lua::newtable(L);
				for (size_t j = 0; j < def.childs.size() && j < val.getChildCount(); ++j)
				{
					push(L, -1, def.childs[j], *child->getChild(j));
				}
				lua::settable(L, (index > 0) ? index : index - 2, def.name.c_str());
				break;
			}
		}
		lua::settable(L, (index > 0) ? index : index - 1, def.name.c_str());
	}
}


void MsgVersatility::push(lua_State *L)
{
	int msgcat = getCategory();
	int msgid = getID();

	auto it = g_msgdef_map.find((msgcat << 16) | msgid);
	if (it == g_msgdef_map.end())
	{
		lua::pushnil(L);
		return;
	}

	lua::newtable(L);

	std::vector<FieldDefine> &defs = it->second;
	for (size_t i = 0; i < defs.size() && i < m_vals.size(); ++i)
	{
		::push(L, -1, defs[i], m_vals[i]);
	}
}
