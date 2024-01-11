#include "Lua.h"

void registerlib(lua_State *L, const char *libname, LuaReg *funcs) {
    lua_newtable(L);  // 创建一个新表
    for (int i = 0; funcs[i].name != NULL; i++) {
        lua_pushstring(L, funcs[i].name); // 将函数名压栈
        lua_pushcfunction(L, funcs[i].func); // 将C函数压栈
        lua_settable(L, -3); // 设置为表的字段
    }
    lua_setglobal(L, libname); // 将表设置为全局变量
}

void registermetatable(lua_State *L, const char *typename, LuaReg *funcs) {
    luaL_newmetatable(L, typename); // 创建或获取元表
    for (int i = 0; funcs[i].name != NULL; i++) {
        lua_pushstring(L, funcs[i].name); // 将函数名压栈
        lua_pushcfunction(L, funcs[i].func); // 将C函数压栈
        lua_settable(L, -3); // 设置为元表的字段
    }
    lua_pop(L, 1); // 弹出元表
}

