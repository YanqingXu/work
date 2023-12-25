
#ifndef _DUMP_BUFFER_H_INCLUDED
#define _DUMP_BUFFER_H_INCLUDED

#include "types.h"

#include <string>

class DumpBuffer
{
	static const size_t DUMP_BUFFER_MAX = 1024 * 1024 - 1;

public:
	DumpBuffer()
	{
		m_buf = new char[DUMP_BUFFER_MAX + 1];
		m_size = 0;
	}

	~DumpBuffer()
	{
		if (m_buf != NULL)
		{
			delete[] m_buf;
			m_buf = NULL;
		}
		m_size = 0;
	}

	DumpBuffer &operator<<(bool v)
	{
		append((v ? "true" : "false"));
		return *this;
	}

	DumpBuffer &operator<<(char v)
	{
		char buf[64] = { 0 };
		sprintf(buf, "%d", (int)v);
		append(buf);
		return *this;
	}

	DumpBuffer &operator<<(unsigned char v)
	{
		char buf[64] = { 0 };
		sprintf(buf, "%u", (unsigned int)v);
		append(buf);
		return *this;
	}

	DumpBuffer &operator<<(short v)
	{
		char buf[64] = { 0 };
		sprintf(buf, "%hd", (int)v);
		append(buf);
		return *this;
	}

	DumpBuffer &operator<<(unsigned short v)
	{
		char buf[64] = { 0 };
		sprintf(buf, "%hu", (unsigned int)v);
		append(buf);
		return *this;
	}

	DumpBuffer &operator<<(int v)
	{
		char buf[64] = { 0 };
		sprintf(buf, "%d", (int)v);
		append(buf);
		return *this;
	}

	DumpBuffer &operator<<(unsigned int v)
	{
		char buf[64] = { 0 };
		sprintf(buf, "%u", (unsigned int)v);
		append(buf);
		return *this;
	}

	DumpBuffer &operator<<(long long v)
	{
		char buf[64] = { 0 };
		sprintf(buf, "%lld", (int)v);
		append(buf);
		return *this;
	}

	DumpBuffer &operator<<(unsigned long long v)
	{
		char buf[64] = { 0 };
		sprintf(buf, "%llu", (unsigned int)v);
		append(buf);
		return *this;
	}

	DumpBuffer &operator<<(float v)
	{
		char buf[64] = { 0 };
		sprintf(buf, "%f", v);
		append(buf);
		return *this;
	}

	DumpBuffer &operator<<(double v)
	{
		char buf[64] = { 0 };
		sprintf(buf, "%f", v);
		append(buf);
		return *this;
	}

	DumpBuffer &operator<<(const char *v)
	{
		if ((v != NULL) && (*v != 0))
		{
			append(v);
		}
		return *this;
	}

	DumpBuffer &operator<<(const std::string &v)
	{
		if (v.size() > 0)
		{
			append(v.c_str());
		}
		return *this;
	}

	void clear()
	{
		m_buf[0] = 0;
		m_size = 0;
	}

	const char *c_str()
	{
		return m_buf;
	}

private:
	void append(const char *v)
	{
		if ((v != NULL) && (m_size < DUMP_BUFFER_MAX))
		{
			size_t left = DUMP_BUFFER_MAX - m_size;
			size_t len = strlen(v);
			size_t copy = (len < left) ? len : left;
			memcpy(m_buf + m_size, v, copy);
			m_size += copy;
			m_buf[m_size] = 0;
		}
	}

private:
	char *m_buf;
	size_t m_size;
};

#endif	//_DUMP_BUFFER_H_INCLUDED

