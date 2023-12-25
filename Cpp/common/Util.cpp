#include "Util.h"
#include <chrono>
#include <codecvt>
#include <locale>
#include <random>
#include <ctime>

// 获取当前时间戳（自1970年1月1日以来的秒数）
int get_time() {
    auto now = std::chrono::system_clock::now();
    auto now_sec = std::chrono::time_point_cast<std::chrono::seconds>(now);
    return now_sec.time_since_epoch().count();
}

// 获取当前日期（自1970年1月1日以来的天数）
int get_day() {
    auto now = std::chrono::system_clock::now();
    auto now_sec = std::chrono::time_point_cast<std::chrono::seconds>(now);
    auto epoch = now_sec.time_since_epoch();
    int days_since_epoch = epoch.count() / 86400; // 86400 seconds in a day
    return days_since_epoch;
}

#ifdef _WIN32
#include <Windows.h>

unsigned long long get_tick_count() {
    return GetTickCount64();
}
#endif

#ifdef __linux__
#include <sys/time.h>
unsigned long long get_tick_count() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}
#endif

#ifdef _WIN32
#include <Windows.h>

void set_console_utf8() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}
#endif


int get_last_week() {
    // 计算当前时间点的时间戳
    auto epoch_seconds = get_time();

    // 计算当前时间是一周中的哪一天（星期日为0，星期六为6）
    std::time_t current_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm *current_tm = std::localtime(&current_time_t);
    int weekday = current_tm->tm_wday;

    // 计算上周的开始（假设以星期一为每周开始）
    // 如果今天是星期一（1），则上周开始是7天前
    // 如果今天是星期日（0），则上周开始是13天前
    int days_to_subtract = weekday == 0 ? 13 : weekday + 6;
    int seconds_per_day = 86400;
    int last_week_start = epoch_seconds - days_to_subtract * seconds_per_day;

    return last_week_start;
}

std::wstring utf8_to_unicode(const std::string &utf8_string) {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.from_bytes(utf8_string);
}

std::string unicode_to_utf8(const std::wstring &unicode_string) {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.to_bytes(unicode_string);
}

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

unsigned int mtrand(unsigned int rmin, unsigned int rmax) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(rmin, rmax);
    return dis(gen);
}

