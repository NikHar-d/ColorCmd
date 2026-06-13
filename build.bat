@echo off

echo building .o
REM -c do not link
g++ -c src/ColorCmd.cpp -o build/libColorCmd.o

echo archiving .dll
REM archive the object to .dll object
ar -rcs build/libColorCmd.dll build/libColorCmd.o

echo copying header
REM copy header file into build folder
copy src\ColorCmd.h build\ColorCmd.h >NUL

echo removing .o
REM remove temporary .o file
del build\libColorCmd.o

echo done
