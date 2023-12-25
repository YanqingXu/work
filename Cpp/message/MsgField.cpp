
#include "MsgField.h"
#include "common/Logger.h"
//
//extern "C"
//{
//#include "lua.h"
//#include "lualib.h"
//#include "lauxlib.h"
//}

#include <string.h>
#include <stdarg.h>

#include <strstream>
#include <sstream>

FieldValue::FieldValue()
{
	m_type = TYPE_INT64;
	m_val.l = 0;
}

FieldValue::~FieldValue()
{
	clear();
}

void FieldValue::clear()
{
	if (m_type == TYPE_STRING)
	{
	}
	else if (m_type == TYPE_TABLE)
	{
	}

	m_type = TYPE_INT64;
	m_val.l = 0;
}


char FieldValue::getInt8() const
{
	return (m_type == TYPE_INT8) ? (char)m_val.l : 0;
}

short FieldValue::getInt16() const
{
	return (m_type == TYPE_INT16) ? (short)m_val.l : 0;
}

int FieldValue::getInt32() const
{
	return (m_type == TYPE_INT32) ? (int)m_val.l : 0;
}

long long FieldValue::getInt64() const
{
	return (m_type == TYPE_INT64) ? m_val.l : 0;
}

float FieldValue::getFloat() const
{
	return (m_type == TYPE_FLOAT) ? m_val.f : 0;
}

double FieldValue::getDouble() const
{
	return (m_type == TYPE_DOUBLE) ? m_val.d : 0;
}

const char *FieldValue::getString() const
{
	return ((m_type == TYPE_STRING) && (m_val.s != nullptr)) ? m_val.s : "";
}

void FieldValue::setInt8(char val)
{
	if ((m_type == TYPE_STRING) || (m_type == TYPE_TABLE))
	{
		clear();
	}

	m_type = TYPE_INT8;
	m_val.l = val;
}

void FieldValue::setInt16(short val)
{
	if ((m_type == TYPE_STRING) || (m_type == TYPE_TABLE))
	{
		clear();
	}

	m_type = TYPE_INT16;
	m_val.l = val;
}

void FieldValue::setInt32(int val)
{
	if ((m_type == TYPE_STRING) || (m_type == TYPE_TABLE))
	{
		clear();
	}

	m_type = TYPE_INT32;
	m_val.l = val;
}

void FieldValue::setInt64(long long val)
{
	if ((m_type == TYPE_STRING) || (m_type == TYPE_TABLE))
	{
		clear();
	}

	m_type = TYPE_INT64;
	m_val.l = val;
}

void FieldValue::setFloat(float val)
{
	if ((m_type == TYPE_STRING) || (m_type == TYPE_TABLE))
	{
		clear();
	}

	m_type = TYPE_FLOAT;
	m_val.f = val;
}

void FieldValue::setDouble(double val)
{
	if ((m_type == TYPE_STRING) || (m_type == TYPE_TABLE))
	{
		clear();
	}

	m_type = TYPE_DOUBLE;
	m_val.d = val;
}

void FieldValue::setString(const char *val)
{
	if ((m_type == TYPE_STRING) || (m_type == TYPE_TABLE))
	{
		clear();
	}


	size_t len = (val != nullptr) ? strlen(val) : 0;

	m_type = TYPE_STRING;
	m_val.s = new char[len + 1];
	if (len > 0)
	{
		memcpy(m_val.s, val, len);
	}
	m_val.s[len] = 0;
}

void FieldValue::setString(const std::string &val)
{
	setString(val.c_str());
}

//void FieldValue::setTable()
//{
//	if ((m_type == TYPE_STRING) || (m_type == TYPE_TABLE))
//	{
//		clear();
//	}
//
//	m_type = TYPE_TABLE;
//}

int FieldValue::getChildCount() const
{
	return (m_type == FieldValue::TYPE_TABLE) ? (int)m_childs.size() : 0;
}

void FieldValue::setChildCount(size_t count)
{
	if ((m_type == TYPE_STRING) || (m_type == TYPE_TABLE))
	{
		clear();
	}

	m_type = TYPE_TABLE;
	m_childs.resize(count);
}

FieldValue *FieldValue::getChild(size_t index)
{
	if (m_type != TYPE_TABLE)
	{
		return nullptr;
	}

	return (index < m_childs.size()) ? &m_childs[index] : nullptr;
}

const FieldValue *FieldValue::getChild(size_t index) const
{
	if (m_type != TYPE_TABLE)
	{
		return nullptr;
	}

	return (index < m_childs.size()) ? &m_childs[index] : nullptr;
}

int FieldValue::getChildType(int index) const
{
	const FieldValue *v = getChild(index);
	if (v == nullptr)
	{
		return TYPE_INT64;
	}

	return v->getType();
}

char FieldValue::getInt8(int index) const
{
	const FieldValue *v = getChild(index);
	if (v == nullptr)
	{
		return 0;
	}

	return v->getInt8();
}

short FieldValue::getInt16(int index) const
{
	const FieldValue *v = getChild(index);
	if (v == nullptr)
	{
		return 0;
	}

	return v->getInt16();
}

int FieldValue::getInt32(int index) const
{
	const FieldValue *v = getChild(index);
	if (v == nullptr)
	{
		return 0;
	}

	return v->getInt32();
}

float FieldValue::getFloat(int index) const
{
	const FieldValue *v = getChild(index);
	if (v == nullptr)
	{
		return 0.0f;
	}

	return v->getFloat();
}

double FieldValue::getDouble(int index) const
{
	const FieldValue *v = getChild(index);
	if (v == nullptr)
	{
		return 0.0;
	}

	return v->getDouble();
}

const char *FieldValue::getString(int index) const
{
	const FieldValue *v = getChild(index);
	if (v == nullptr)
	{
		return 0;
	}

	return v->getString();
}

void FieldValue::setInt8(int index, char val)
{
	FieldValue *v = getChild(index);
	if (v == nullptr)
	{
		return;
	}

	v->setInt8(val);
}

void FieldValue::setInt16(int index, short val)
{
	FieldValue *v = getChild(index);
	if (v == nullptr)
	{
		return;
	}

	v->setInt16(val);
}

void FieldValue::setInt32(int index, int val)
{
	FieldValue *v = getChild(index);
	if (v == nullptr)
	{
		return;
	}

	v->setInt32(val);
}

void FieldValue::setInt64(int index, long long val)
{
	FieldValue *v = getChild(index);
	if (v == nullptr)
	{
		return;
	}

	v->setInt64(val);
}

void FieldValue::setFloat(int index, float val)
{
	FieldValue *v = getChild(index);
	if (v == nullptr)
	{
		return;
	}

	v->setFloat(val);
}

void FieldValue::setDouble(int index, double val)
{
	FieldValue *v = getChild(index);
	if (v == nullptr)
	{
		return;
	}

	v->setDouble(val);
}

void FieldValue::setString(int index, const char *val)
{
	FieldValue *v = getChild(index);
	if (v == nullptr)
	{
		return;
	}

	v->setString(val);
}

void FieldValue::setString(int index, const std::string &val)
{
	FieldValue *v = getChild(index);
	if (v == nullptr)
	{
		return;
	}

	v->setString(val);
}
//
//void FieldValue::appendInt8(char val)
//{
//	FieldValue *v = new FieldValue;
//	v->setInt8(val);
//	m_childs.push_back(v);
//}
//
//void FieldValue::appendInt8(unsigned char val)
//{
//	FieldValue *v = new FieldValue;
//	v->setInt8(val);
//	m_childs.push_back(v);
//}
//
//void FieldValue::appendInt16(short val)
//{
//	FieldValue *v = new FieldValue;
//	v->setInt16(val);
//	m_childs.push_back(v);
//}
//
//void FieldValue::appendInt16(unsigned short val)
//{
//	FieldValue *v = new FieldValue;
//	v->setInt16(val);
//	m_childs.push_back(v);
//}
//
//void FieldValue::appendInt32(int val)
//{
//	FieldValue *v = new FieldValue;
//	v->setInt32(val);
//	m_childs.push_back(v);
//}
//
//void FieldValue::appendInt32(unsigned int val)
//{
//	FieldValue *v = new FieldValue;
//	v->setInt32(val);
//	m_childs.push_back(v);
//}
//
//void FieldValue::appendInt64(long long val)
//{
//	FieldValue *v = new FieldValue;
//	v->setInt64(val);
//	m_childs.push_back(v);
//}
//
//void FieldValue::appendInt64(unsigned long long val)
//{
//	FieldValue *v = new FieldValue;
//	v->setInt64(val);
//	m_childs.push_back(v);
//}
//
//void FieldValue::appendFloat(float val)
//{
//	FieldValue *v = new FieldValue;
//	v->setFloat(val);
//	m_childs.push_back(v);
//}
//
//void FieldValue::appendDouble(double val)
//{
//	FieldValue *v = new FieldValue;
//	v->setDouble(val);
//	m_childs.push_back(v);
//}
//
//void FieldValue::appendString(const char *val)
//{
//	FieldValue *v = new FieldValue;
//	v->setString(val);
//	m_childs.push_back(v);
//}
//
//void FieldValue::appendString(const std::string &val)
//{
//	FieldValue *v = new FieldValue;
//	v->setString(val);
//	m_childs.push_back(v);
//}
//
//void FieldValue::appendTable()
//{
//	FieldValue *v = new FieldValue;
//	v->setTable();
//	m_childs.push_back(v);
//}
//
//FieldValue &FieldValue::operator<<(char val)
//{
//	appendInt8(val);
//	return *this;
//}
//
//FieldValue &FieldValue::operator<<(unsigned char val)
//{
//	appendInt8(val);
//	return *this;
//}
//
//FieldValue &FieldValue::operator<<(short val)
//{
//	appendInt16(val);
//	return *this;
//}
//
//FieldValue &FieldValue::operator<<(unsigned short val)
//{
//	appendInt16(val);
//	return *this;
//}
//
//FieldValue &FieldValue::operator<<(int val)
//{
//	appendInt32(val);
//	return *this;
//}
//
//FieldValue &FieldValue::operator<<(unsigned int val)
//{
//	appendInt32(val);
//	return *this;
//}
//
//FieldValue &FieldValue::operator<<(long long val)
//{
//	appendInt64(val);
//	return *this;
//}
//
//FieldValue &FieldValue::operator<<(unsigned long long val)
//{
//	appendInt64(val);
//	return *this;
//}
//
//FieldValue &FieldValue::operator<<(float val)
//{
//	appendFloat(val);
//	return *this;
//}
//
//FieldValue &FieldValue::operator<<(double val)
//{
//	appendDouble(val);
//	return *this;
//}
//
//FieldValue &FieldValue::operator<<(const char *val)
//{
//	appendString(val);
//	return *this;
//}
//
//FieldValue &FieldValue::operator<<(const std::string &val)
//{
//	appendString(val.c_str());
//	return *this;
//}
