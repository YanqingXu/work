
#ifndef _UTIL_H_INCLUDED
#define _UTIL_H_INCLUDED

#include "types.h"

#include <string>

//取当前时间(单位秒)
int COMMON_API get_time();

//取当前日期(单位秒)
int COMMON_API get_day();

unsigned long long COMMON_API get_tick_count();

//设置consol窗口为UTF8编码
void COMMON_API set_console_utf8();

int COMMON_API get_last_week();

//检测位置偏移是否在范围内
bool COMMON_API in_range(short dx, short dy, short range);

//检测位置偏移是否在范围外
bool COMMON_API out_of_range(short dx, short dy, short range);

//utf8转unicode
std::wstring COMMON_API utf8_to_unicode(const std::string &utf8_string);
//unicode转utf8
std::string COMMON_API unicode_to_utf8(const std::wstring &unicode_string);
//utf8转unicode的长度
int COMMON_API utf8_to_unicode_len(const std::string &utf8);

//求其最大公约数
int COMMON_API gcd(int x, int y);

//解密码
std::string COMMON_API decrypt_passwd(const char *s);

std::string COMMON_API resolve_host(const std::string &host);

std::string COMMON_API base64_encode(const std::string &s);
std::string COMMON_API md5(const std::string &s);

bool COMMON_API verify_token(int aid, const std::string &token);

bool COMMON_API check_program_singleton();

//[0, 0xffffffff]
unsigned int COMMON_API mtrand();
//[0, rmax]
unsigned int COMMON_API mtrand(unsigned int rmax);
//[rmin, rmax]
unsigned int COMMON_API mtrand(unsigned int rmin, unsigned int rmax);

#endif	//_UTIL_H_INCLUDED

