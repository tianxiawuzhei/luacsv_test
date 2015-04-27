rem adjust your Lua include and lib path accordingly; quote if they contain spaces
cl /nologo -c /O1 /Ic:/lua/include   csv.c
link /nologo csv.obj  /LIBPATH:c:/lua/lib  lua5.1.lib  /DLL /OUT:csv.dll