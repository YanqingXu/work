#ifndef _GUILD_LUA_H_INCLUDED
#define _GUILD_LUA_H_INCLUDED

#include "Guild.h"
#include "common/lua.h"

namespace lua
{
	void openguild(lua_State *L);
	void push(lua_State *L, Guild *guild);
	Guild *toguild(lua_State *L, int index);
}

#endif	//_GUILD_LUA_H_INCLUDED
