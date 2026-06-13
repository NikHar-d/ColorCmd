@set SOURCES=../ColorCmdExample.cpp
@set INCLUDES=-I../../build
@set LIBS=-L../../build
@set LINKS=-lColorCmd -lstdc++
@set OUT=out.exe
gcc %SOURCES% -o %OUT% %INCLUDES% %LIBS% %LINKS%

