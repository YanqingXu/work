
#ifndef _LOGGER_H_INCLUDED
#define _LOGGER_H_INCLUDED

#include "types.h"

#include <string>

#pragma warning(push)
#pragma warning(disable:4251)

struct _RTL_CRITICAL_SECTION;
typedef _RTL_CRITICAL_SECTION RTL_CRITICAL_SECTION;
typedef RTL_CRITICAL_SECTION CRITICAL_SECTION;

class COMMON_API Logger
{
public:
	//日志等级
	enum
	{
		LEVEL_DEBUG,
		LEVEL_INFO,
		LEVEL_WARN,
		LEVEL_ERROR,
		LEVEL_FATAL,
	};

public:
	//构造函数
	Logger();

	//析构函数
	~Logger();

	//日志名称，作为日志文件名前缀
	//name_YYYY_MM_DD_HH_mm_SS_serial.log
	void set_name(std::string &name);

	void set_level(int level);
	void set_level(const char *level);
	void set_level(const std::string &level);

	//设置输出到终端的日志等级
	void set_tty_level(int level);
	void set_tty_level(const char *level);
	void set_tty_level(const std::string &level);

	//设置输出到文件的日志等级
	void set_file_level(int level);
	void set_file_level(const char *level);
	void set_file_level(const std::string &level);

	//输出日志
	void log(int level, const char *funcname, const char *filename, int line, const char *fmt, ...);

private:
	int get_level(const char *level, int value = LEVEL_INFO);

private:
	//日志目录
	std::string m_log_dir;

	//日志名前缀
	std::string m_name;

	//日志序列
	int m_serial;

	//输出到终端的日志等级
	int m_tty_level;

	//输出到文件的日志等级
	int m_file_level;

	//日志文件句柄
	int m_logfd;

	//创建和关闭文件的锁
	CRITICAL_SECTION *m_cs;
};

extern COMMON_API Logger *g_logger;

#define LOG_DEBUG(...) \
	if (g_logger != nullptr) g_logger->log(Logger::LEVEL_DEBUG, __FUNCTION__, __FILE__, __LINE__, ##__VA_ARGS__)

#define LOG_INFO(...) \
	if (g_logger != nullptr) g_logger->log(Logger::LEVEL_INFO, __FUNCTION__, __FILE__, __LINE__, ##__VA_ARGS__)

#define LOG_WARN(...) \
	if (g_logger != nullptr) g_logger->log(Logger::LEVEL_WARN, __FUNCTION__, __FILE__, __LINE__, ##__VA_ARGS__)

#define LOG_ERROR(...) \
	if (g_logger != nullptr) g_logger->log(Logger::LEVEL_ERROR, __FUNCTION__, __FILE__, __LINE__, ##__VA_ARGS__)

#define LOG_FATAL(...) \
	if (g_logger != nullptr) g_logger->log(Logger::LEVEL_FATAL, __FUNCTION__, __FILE__, __LINE__, ##__VA_ARGS__)


#pragma warning(pop)

#endif	//_LOGGER_H_INCLUDED
