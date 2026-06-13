#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <cstdarg>

namespace ColorCmd {
    void Init(){
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD dwMode = 0;
        GetConsoleMode(hOut, &dwMode);
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);
    }
    void Fore(int r, int g, int b){std::cout<<"\x1b[38;2;"<<r<<";"<<g<<";"<<b<<"m";}
    void Fore(int rgb){std::cout<<"\x1b[38;2;"<<((rgb&0xff0000)>>16)<<";"<<((rgb&0x00ff00)>>8)<<";"<<(rgb&0x0000ff)<<"m";}
    void Back(int r, int g, int b){std::cout<<"\x1b[48;2;"<<r<<";"<<g<<";"<<b<<"m";}
    void Back(int rgb){std::cout<<"\x1b[48;2;"<<((rgb&0xff0000)>>16)<<";"<<((rgb&0x00ff00)>>8)<<";"<<(rgb&0x0000ff)<<"m";}
    void Printf(int r, int g, int b, const char* format, ...){
        Fore(r, g, b);
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
    }
    void Printf(int rgb, const char* format, ...){
        Fore(rgb);
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
    }
    void Reset(){std::cout<<"\x1b[0m";}
}
