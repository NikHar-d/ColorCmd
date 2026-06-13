@echo off
@set SOURCES=DevExample.cpp ColorCmd.cpp ColorCmd.h
@set INCLUDES=
@set LIBS=
@set LINKS=
@set OUT=out.exe
g++ %SOURCES% -o %OUT% %INCLUDES% %LIBS% %LINKS%
out.exe
