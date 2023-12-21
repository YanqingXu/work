
#ifndef _LUA_H_INCLUDED
#define _LUA_H_INCLUDED

#include "types.h"

#include <vector>
#include <map>
#include <string>

extern "C"
{
	typedef struct lua_State lua_State;
	typedef int (*lua_CFunction) (lua_State *L);
	typedef struct LuaReg
	{
		const char *name;
		lua_CFunction func;
	} LuaReg;
}

namespace lua
{
	extern COMMON_API lua_State *L;

	//创建lua线程并打开通用库, 如果lua::L==nullptr则同时赋值给lua::L
	COMMON_API lua_State *open();

	//关闭lua线程
	COMMON_API void close(lua_State *L);

	COMMON_API void registerlib(lua_State *L, const char *name, LuaReg *funcs);
	COMMON_API void registermetatable(lua_State *L, const char *name, LuaReg *funcs);

	//增加路径
	COMMON_API void addpath(lua_State *L, const char *path);

	//垃圾回收
	COMMON_API void gc(lua_State *L);

	//日志
	COMMON_API void log(lua_State *L, int level);

	//
	//堆栈相关
	//
	COMMON_API int gettop(lua_State *L);
	COMMON_API void settop(lua_State *L, int index);
	COMMON_API void pop(lua_State *L, int n);
	COMMON_API int ref(lua_State *L);
	COMMON_API void unref(lua_State *L, int ref);
	COMMON_API void getref(lua_State *L, int ref);

	COMMON_API const char *type(lua_State *L, int index);

	COMMON_API int checkint(lua_State *L, int index);
	COMMON_API int checkinteger(lua_State *L, int index);
	COMMON_API void *checkudata(lua_State *L, int index, const char *name);

	COMMON_API bool isnil(lua_State *L, int index);
	COMMON_API bool isboolean(lua_State *L, int index);
	COMMON_API bool isnumber(lua_State *L, int index);
	COMMON_API bool isstring(lua_State *L, int index);
	COMMON_API bool istable(lua_State *L, int index);
	COMMON_API bool isfunction(lua_State *L, int index);
	COMMON_API bool isuserdata(lua_State *L, int index);

	COMMON_API bool toboolean(lua_State *L, int index);
	COMMON_API int tointeger(lua_State *L, int index);
	COMMON_API double tonumber(lua_State *L, int index);
	COMMON_API const char *tostring(lua_State *L, int index);
	COMMON_API const char *tolstring(lua_State *L, int index, size_t *len);
	COMMON_API void *touserdata(lua_State *L, int index, char *name);
	COMMON_API std::vector<int> tointvector(lua_State *L, int index);

	//将值压入堆栈
	COMMON_API bool pushnil(lua_State *L);
	COMMON_API bool push(lua_State *L, bool val);
	COMMON_API bool push(lua_State *L, int val);
	COMMON_API bool push(lua_State *L, unsigned int val);
	COMMON_API bool push(lua_State *L, float val);
	COMMON_API void push(lua_State *L, double val);
	COMMON_API bool push(lua_State *L, const char *val);
	COMMON_API bool push(lua_State *L, const std::string &val);
	COMMON_API void push(lua_State *L, const char *metatable, void *ptr);
	COMMON_API void pushvalue(lua_State *L, int index);

	//
	//全局数据操作
	//
	//获取全局数据并压入栈顶
	COMMON_API void getglobal(lua_State *L, const char *name);
	//获取全局数据
	COMMON_API bool getglobal(lua_State *L, const char *name, bool &val);
	COMMON_API bool getglobal(lua_State *L, const char *name, int &val);
	COMMON_API bool getglobal(lua_State *L, const char *name, float &val);
	COMMON_API bool getglobal(lua_State *L, const char *name, std::string &val);
	//设置全局数据
	COMMON_API bool setglobal(lua_State *L, const char *name, bool val);
	COMMON_API bool setglobal(lua_State *L, const char *name, int val);
	COMMON_API bool setglobal(lua_State *L, const char *name, float val);
	COMMON_API bool setglobal(lua_State *L, const char *name, const std::string &val);
	COMMON_API bool setglobal(lua_State *L, const char *name, const char *fmt, ...);

	//
	//元表
	//
	COMMON_API int newmetatable(lua_State *L, const char *name);
	COMMON_API void getmetatable(lua_State *L, const char *name);
	COMMON_API int setmetatable(lua_State *L, int objindex);

	//
	//表操作
	//
	COMMON_API bool newtable(lua_State *L);

	COMMON_API bool gettable(lua_State *L, int index, int field);
	COMMON_API bool gettable(lua_State *L, int index, int field, bool &val);
	COMMON_API bool gettable(lua_State *L, int index, int field, int &val);
	COMMON_API bool gettable(lua_State *L, int index, int field, long long &val);
	COMMON_API bool gettable(lua_State *L, int index, int field, float &val);
	COMMON_API bool gettable(lua_State *L, int index, int field, double &val);
	COMMON_API bool gettable(lua_State *L, int index, int field, std::string &val);

	COMMON_API bool gettable(lua_State *L, int index, const char *field);
	COMMON_API bool gettable(lua_State *L, int index, const char *field, bool &val);
	COMMON_API bool gettable(lua_State *L, int index, const char *field, int &val);
	COMMON_API bool gettable(lua_State *L, int index, const char *field, float &val);
	COMMON_API bool gettable(lua_State *L, int index, const char *field, double &val);
	COMMON_API bool gettable(lua_State *L, int index, const char *field, long long &val);
	COMMON_API bool gettable(lua_State *L, int index, const char *field, std::string &val);

	//value		-1
	//field		-2
	//...
	//table		index
	COMMON_API void settable(lua_State *L, int index);

	//value		-1
	//...
	//table		index
	COMMON_API bool settable(lua_State *L, int index, const char *field);

	COMMON_API bool settable(lua_State *L, int index, int field, bool val);
	COMMON_API bool settable(lua_State *L, int index, int field, int val);
	COMMON_API bool settable(lua_State *L, int index, int field, long long val);
	COMMON_API bool settable(lua_State *L, int index, int field, float val);
	COMMON_API bool settable(lua_State *L, int index, int field, double val);
	COMMON_API bool settable(lua_State *L, int index, int field, const std::string &val);
	COMMON_API bool settable(lua_State *L, int index, int field, const char *fmt, ...);

	COMMON_API bool settable(lua_State *L, int index, const char *field, bool val);
	COMMON_API bool settable(lua_State *L, int index, const char *field, int val);
	COMMON_API bool settable(lua_State *L, int index, const char *field, long long val);
	COMMON_API bool settable(lua_State *L, int index, const char *field, float val);
	COMMON_API bool settable(lua_State *L, int index, const char *field, double val);
	COMMON_API bool settable(lua_State *L, int index, const char *field, const std::string &val);
	COMMON_API bool settable(lua_State *L, int index, const char *field, const char *fmt, ...);

	COMMON_API int next(lua_State *L, int index);
	COMMON_API int objlen(lua_State *L, int index);

	//
	//执行lua代码
	//
	COMMON_API bool dostring(lua_State *L, const char *code);

	//不要调用此函数, 请使用下面的call函数
	COMMON_API bool callex(lua_State *L, const char *func, int argc);

	inline bool call(lua_State *L, const char *func)
	{
		return callex(L, func, 0);
	}

	template<typename T1>
	bool call(lua_State *L, const char *func, T1 arg1)
	{
		lua::push(L, arg1);
		return callex(L, func, 1);
	}

	template<typename T1, typename T2>
	bool call(lua_State *L, const char *func, T1 arg1, T2 arg2)
	{
		lua::push(L, arg1);
		lua::push(L, arg2);
		return callex(L, func, 2);
	}

	template<typename T1, typename T2, typename T3>
	bool call(lua_State *L, const char *func, T1 arg1, T2 arg2, T3 arg3)
	{
		lua::push(L, arg1);
		lua::push(L, arg2);
		lua::push(L, arg3);
		return callex(L, func, 3);
	}

	template<typename T1, typename T2, typename T3, typename T4>
	bool call(lua_State *L, const char *func, T1 arg1, T2 arg2, T3 arg3, T4 arg4)
	{
		lua::push(L, arg1);
		lua::push(L, arg2);
		lua::push(L, arg3);
		lua::push(L, arg4);
		return callex(L, func, 4);
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5>
	bool call(lua_State *L, const char *func, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5)
	{
		lua::push(L, arg1);
		lua::push(L, arg2);
		lua::push(L, arg3);
		lua::push(L, arg4);
		lua::push(L, arg5);
		return callex(L, func, 5);
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	bool call(lua_State *L, const char *func, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6)
	{
		lua::push(L, arg1);
		lua::push(L, arg2);
		lua::push(L, arg3);
		lua::push(L, arg4);
		lua::push(L, arg5);
		lua::push(L, arg6);
		return callex(L, func, 6);
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
	bool call(lua_State *L, const char *func, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7)
	{
		lua::push(L, arg1);
		lua::push(L, arg2);
		lua::push(L, arg3);
		lua::push(L, arg4);
		lua::push(L, arg5);
		lua::push(L, arg6);
		lua::push(L, arg7);
		return callex(L, func, 7);
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
	bool call(lua_State *L, const char *func, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8)
	{
		lua::push(L, arg1);
		lua::push(L, arg2);
		lua::push(L, arg3);
		lua::push(L, arg4);
		lua::push(L, arg5);
		lua::push(L, arg6);
		lua::push(L, arg7);
		lua::push(L, arg8);
		return callex(L, func, 8);
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
	bool call(lua_State *L, const char *func, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9)
	{
		lua::push(L, arg1);
		lua::push(L, arg2);
		lua::push(L, arg3);
		lua::push(L, arg4);
		lua::push(L, arg5);
		lua::push(L, arg6);
		lua::push(L, arg7);
		lua::push(L, arg8);
		lua::push(L, arg9);
		return callex(L, func, 9);
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
	bool call(lua_State *L, const char *func, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10)
	{
		lua::push(L, arg1);
		lua::push(L, arg2);
		lua::push(L, arg3);
		lua::push(L, arg4);
		lua::push(L, arg5);
		lua::push(L, arg6);
		lua::push(L, arg7);
		lua::push(L, arg8);
		lua::push(L, arg9);
		lua::push(L, arg10);
		return callex(L, func, 10);
	}

	//
	//call函数返回的结果, index从1开始
	//
	COMMON_API bool getboolean(int index);
	COMMON_API int getinteger(int index);
	COMMON_API double getnumber(int index);
	COMMON_API const char *getstring(int index);
	COMMON_API std::vector<int> getvector(int index);
}

#endif	//!_LUA_H_INCLUDED

