
#ifndef _MSG_VERSATILITY_H_INCLUDED
#define _MSG_VERSATILITY_H_INCLUDED

#include "common/Message.h"
#include "common/Logger.h"
#include "common/ByteStream.h"

#include "MsgField.h"

class MsgVersatility : public Message
{
public:
	MsgVersatility();

	virtual const char *getName() const
	{
		return "MsgVersatility";
	}

	virtual size_t getLength() const;

	virtual bool serialize(ByteStream &s) const;

	virtual bool unserialize(ByteStream &s);

	virtual void push(lua_State *L);

	virtual void dump(DumpBuffer &buffer)
	{
	}

private:
	size_t getFieldLength(const FieldDefine &def, const FieldValue &val) const;

	bool serializeField(ByteStream &s, const FieldDefine &def, const FieldValue &val) const;

	bool unserializeField(ByteStream &s, const FieldDefine &def, FieldValue &val);

public:
	std::vector<FieldValue> m_vals;
};

extern std::map<std::string, std::vector<FieldDefine>> g_structdef_map;
extern std::map<int, std::vector<FieldDefine>> g_msgdef_map;

#endif	//_MSG_VERSATILITY_H_INCLUDED
