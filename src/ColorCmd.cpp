#include <iostream>
#include <stdio.h>
#include <windows.h>
namespace ColorCmd {
    void Init(){
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD dwMode = 0;
        GetConsoleMode(hOut, &dwMode);
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);
    }
    void Fore(int r, int g, int b){std::cout<<"\x1b[38;2;"<<r<<";"<<g<<";"<<b<<"m";}
    void Back(int r, int g, int b){std::cout<<"\x1b[48;2;"<<r<<";"<<g<<";"<<b<<"m";}
    void Reset(){std::cout<<"\x1b[0m";}
}
