@set SOURCES=../ColorCmdExample.cpp
@set INCLUDES=-I../../build
@set LIBS=-L../../build
@set LINKS=-lColorCmd
@set OUT=out.exe
g++ %SOURCES% -o %OUT% %INCLUDES% %LIBS% %LINKS%
