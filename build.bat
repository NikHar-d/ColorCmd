REM -c do not link
g++ -c ColorCmd.cpp -o build/libColorCmd.o
REM archive the object to .dll object
ar -rcs build/libColorCmd.dll build/libColorCmd.o

REM copy header file into build folder
copy ColorCmd.h build\ColorCmd.h
