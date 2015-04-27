// Win32luaProject1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "luaconf.h"
#include "lauxlib.h"
}

#ifdef __cplusplus
extern "C" {
	int luaopen_csv(lua_State *L);
}
#endif

int _tmain(int argc, _TCHAR* argv[])
{
	lua_State *L = luaL_newstate(); 
	luaL_openlibs(L);
	luaopen_csv(L);


	luaL_dofile(L,"D:\\test-project\\luacsv\\Win32luaProject1\\Win32luaProject1\\test.lua");

	//const char *buf = "print('Hello World')";  
	//luaL_dostring(L,buf);  
	printf("ccccccccccccccccc");
	
	lua_close(L);  
	
	return 0;
}
