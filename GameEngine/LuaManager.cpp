#include "LuaManager.h"

LuaManager::LuaManager() : l{}
{
}

void LuaManager::Init()
{
	l = luaL_newstate();
}

void LuaManager::DoFile(const char* luaFile)
{
	luaL_dofile(l, luaFile);
}

void LuaManager::GetGlobal(const char* variable)
{
	lua_getglobal(l, variable);
	/**/
}
