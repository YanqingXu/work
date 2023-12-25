
#ifndef _MSG_FIELD_H_INCLUDED
#define _MSG_FIELD_H_INCLUDED

#include <vector>
#include <map>
#include <string>

struct FieldDefine
{
	std::string name;
	//b,h,i,l,f,s,t
	int type;
	std::vector<FieldDefine> childs;
	bool vec;
};

class FieldValue
{
public:
	enum
	{
		TYPE_INT8,
		TYPE_INT16,
		TYPE_INT32,
		TYPE_INT64,
		TYPE_FLOAT,
		TYPE_DOUBLE,
		TYPE_STRING,
		TYPE_TABLE,			//表
	};

public:
	FieldValue();
	~FieldValue();

	int getType() const { return m_type; }

	//////////////////////////////////////////////////////////////////////////
	//基础类型
	//////////////////////////////////////////////////////////////////////////

	char getInt8() const;
	short getInt16() const;
	int getInt32() const;
	long long getInt64() const;
	float getFloat() const;
	double getDouble() const;
	const char *getString() const;

	void setInt8(char val);
	void setInt16(short val);
	void setInt32(int val);
	void setInt64(long long val);
	void setFloat(float val);
	void setDouble(double val);
	void setString(const char *val);
	void setString(const std::string &val);

	//////////////////////////////////////////////////////////////////////////
	//子值
	//////////////////////////////////////////////////////////////////////////

	int getChildCount() const;
	void setChildCount(size_t count);

	FieldValue *getChild(size_t index);
	const FieldValue *getChild(size_t index) const;

	int getChildType(int index) const;

	char getInt8(int index) const;
	short getInt16(int index) const;
	int getInt32(int index) const;
	long long getInt64(int index) const;
	float getFloat(int index) const;
	double getDouble(int index) const;
	const char *getString(int index) const;

	void setInt8(int index, char val);
	void setInt16(int index, short val);
	void setInt32(int index, int val);
	void setInt64(int index, long long val);
	void setFloat(int index, float val);
	void setDouble(int index, double val);
	void setString(int index, const char *val);
	void setString(int index, const std::string &val);

private:
	void clear();

private:
	int m_type;			//类型

	union
	{
		long long l;	//整数
		float f;		//单精度浮点数
		double d;		//双精度浮点数
		char *s;		//字符串
	} m_val;

	std::vector<FieldValue> m_childs;
};

#endif	//!_MSG_FIELD_H_INCLUDED

