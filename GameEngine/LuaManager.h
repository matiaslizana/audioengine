#pragma once

extern "C"
{
#include "Lua/lua.h"
#include "Lua/lualib.h"
#include "Lua/lauxlib.h"
}

class LuaManager
{
private:
	lua_State* l;

public:
	LuaManager();
	void Init();
	void DoFile(const char* luaFile);
	void GetGlobal(const char* variable);
};

