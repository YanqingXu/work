
#ifndef _BYTE_STREAM_H_INCLUDED
#define _BYTE_STREAM_H_INCLUDED

#include "types.h"

#include <string>
#include <cstring>
#include <cstdint>

#define roundup(x, n) (((x) + ((n) - 1)) & (~((n) - 1)))

class COMMON_API ByteStream
{
public:
	const static size_t DEFAULT_SIZE = 4096;	//4KB

	ByteStream(size_t capacity = 0, bool expand = true);
	ByteStream(const void *buf, size_t len);
	ByteStream(void *buf, size_t len);
	ByteStream(const ByteStream &rhs);
	ByteStream &operator=(const ByteStream &rhs);

	virtual ~ByteStream();

	bool empty() const
	{
		return (m_rpos == m_wpos);
	}

	void clear()
	{
		m_rpos = m_wpos = 0;
	}

	size_t capacity() const
	{
		return m_capacity;
	}

	size_t rpos() const
	{
		return m_rpos;
	}

	size_t rpos(size_t rpos)
	{
		m_rpos = (rpos < m_capacity) ? rpos : m_capacity;
		return m_rpos;
	}

	void rfinish()
	{
		m_rpos = m_wpos;
	}

	size_t wpos() const
	{
		return m_wpos;
	}

	size_t wpos(size_t wpos_)
	{
		m_wpos = (wpos_ < m_capacity) ? wpos_ : m_capacity;
		return m_wpos;
	}

	//uint8_t *rdata()
	//{
	//	return (!m_storage.empty()) ? m_storage.data() + m_rpos : &m_invalid;
	//}

	//可读数据长度
	size_t rsize() const
	{
		return (m_wpos - m_rpos);
	}

	//可读数据指针
	const void *rdata() const
	{
		return (!empty()) ? m_buf + m_rpos : NULL;
	}

	//当前写数据内存
	void *wdata()
	{
		return (m_wpos < m_capacity) ? m_buf + m_wpos : NULL;
	}

	//uint8_t *wdata()
	//{
	//	return (!m_storage.empty()) ? m_storage.data() + m_wpos : &m_invalid;
	//}

	//const uint8_t *wdata() const
	//{
	//	return (!m_storage.empty()) ? m_storage.data() + m_wpos : &m_invalid;
	//}

	//bool append(const void *buf, size_t size)
	//{
	//	if (!buf || !size)
	//	{
	//		return false;
	//	}

	//	if (m_storage.size() < m_wpos + size)
	//	{
	//		m_storage.resize(m_wpos + size);
	//	}

	//	std::memcpy(&m_storage[m_wpos], buf, size);
	//	m_wpos += size;
	//	return true;
	//}

	//bool append(const ByteStream &buffer)
	//{
	//	if (buffer.wpos() == 0)
	//	{
	//		return true;
	//	}

	//	return append(buffer.contents(), buffer.wpos());
	//}

	//uint8_t &operator[](size_t pos)
	//{
	//	return (pos < m_capacity) ? m_buf[pos] : m_invalid;
	//}

	//const uint8_t &operator[](size_t pos) const
	//{
	//	return (pos < m_capacity) ? m_buf[pos] : m_invalid;
	//}

	bool read_skip(size_t skip);

	//读取数据
	bool read(void *buf, size_t len);

	//将读取位置向后移动
	bool unread(size_t len);

	void pack();

	//写入数据
	bool write(const void *buf, size_t len);

	bool write(const ByteStream &stream);

	bool read_bool();
	bool write_bool(bool value);

	int8_t read_int8();
	char read_char();
	bool write_int8(int8_t value);
	bool write_char(char value);

	uint8_t read_uint8();
	bool write_uint8(uint8_t value);

	int16_t read_int16();
	bool write_int16(int16_t value);
	uint16_t read_uint16();
	bool write_uint16(uint16_t value);

	int32_t read_int32();
	bool write_int32(int32_t value);

	uint32_t read_uint32();
	bool write_uint32(uint32_t value);

	int64_t read_int64();
	bool write_int64(int64_t value);

	uint64_t read_uint64();
	bool write_uint64(uint64_t value);

	float read_float();
	bool write_float(float value);

	double read_double();
	bool write_double(double value);

	std::string read_string();
	bool write_string(const std::string &s);
	bool write_string(const char *str);

	template<typename T>
	ByteStream &operator << (const T &val)
	{
		val.serialize(*this);
		return *this;
	}

	template<typename T>
	ByteStream &operator >> (T &val)
	{
		val.unserialize(*this);
		return *this;
	}

	ByteStream &operator<<(bool value)
	{
		write_bool(value);
		return *this;
	}

	ByteStream &operator<<(int8_t value)
	{
		write_int8(value);
		return *this;
	}

	ByteStream &operator<<(char value)
	{
		write_char(value);
		return *this;
	}

	ByteStream &operator<<(uint8_t value)
	{
		write_uint8(value);
		return *this;
	}

	ByteStream &operator<<(int16_t value)
	{
		write_int16(value);
		return *this;
	}

	ByteStream &operator<<(uint16_t value)
	{
		write_uint16(value);
		return *this;
	}

	ByteStream &operator<<(int32_t value)
	{
		write_int32(value);
		return *this;
	}

	ByteStream &operator<<(uint32_t value)
	{
		write_uint32(value);
		return *this;
	}

	ByteStream &operator<<(int64_t value)
	{
		write_int64(value);
		return *this;
	}

	ByteStream &operator<<(uint64_t value)
	{
		write_uint64(value);
		return *this;
	}

	ByteStream &operator<<(float value)
	{
		write_float(value);
		return *this;
	}

	ByteStream &operator<<(double value)
	{
		write_double(value);
		return *this;
	}

	ByteStream &operator<<(const char *value)
	{
		write_string(value);
		return *this;
	}

	ByteStream &operator<<(const std::string &value)
	{
		write_string(value);
		return *this;
	}

	ByteStream &operator>>(bool &value)
	{
		value = read_bool();
		return *this;
	}

	ByteStream &operator>>(int8_t &value)
	{
		value = read_int8();
		return *this;
	}

	ByteStream &operator>>(char &value)
	{
		value = read_char();
		return *this;
	}

	ByteStream &operator>>(uint8_t &value)
	{
		value = read_uint8();
		return *this;
	}

	ByteStream &operator>>(int16_t &value)
	{
		value = read_int16();
		return *this;
	}

	ByteStream &operator>>(uint16_t &value)
	{
		value = read_uint16();
		return *this;
	}

	ByteStream &operator>>(int32_t &value)
	{
		value = read_int32();
		return *this;
	}

	ByteStream &operator>>(uint32_t &value)
	{
		value = read_uint32();
		return *this;
	}

	ByteStream &operator>>(int64_t &value)
	{
		value = read_int64();
		return *this;
	}

	ByteStream &operator>>(uint64_t &value)
	{
		value = read_uint64();
		return *this;
	}

	ByteStream &operator>>(float &value)
	{
		value = read_float();
		return *this;
	}

	ByteStream &operator>>(double &value)
	{
		value = read_double();
		return *this;
	}

	ByteStream &operator>>(std::string &value)
	{
		value = read_string();
		return *this;
	}

private:
	bool expand(size_t need);

protected:
	bool m_read_only;		//缓冲区只读
	bool m_expand;			//缓冲区可扩展
	bool m_delete;			//析构时删除缓冲区

	char *m_buf;			//缓冲区
	size_t m_capacity;		//缓冲区容量
	size_t m_rpos;			//读取位置
	size_t m_wpos;			//写入位置
};

#endif	//_BYTE_STREAM_H_INCLUDED
