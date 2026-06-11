#include <iostream>
#include <windows.h>

void ColorEnable(){
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}
void ColorFront(int r, int g, int b){std::cout<<"\x1b[38;2;"<<r<<";"<<g<<";"<<b<<"m";}
void ColorBack (int r, int g, int b){std::cout<<"\x1b[48;2;"<<r<<";"<<g<<";"<<b<<"m";}
void ColorReset(){std::cout<<"\x1b[0m";}
