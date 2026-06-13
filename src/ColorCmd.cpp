#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <cstdarg>

#define CCMD_FORE 0
#define CCMD_BACK 1

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
    void Printf(int type, int rgb, const char* format, ...){
        if (type==CCMD_FORE) Fore(rgb);
        if (type==CCMD_BACK) Back(rgb);
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
    }
    void Printf(int type, int rgb, const char* format, va_list args){
        if (type==CCMD_FORE) Fore(rgb);
        if (type==CCMD_BACK) Back(rgb);
        vprintf(format, args);
    }
    void Printf(int r, int g, int b, const char* format, ...){ va_list args; va_start(args, format);
        Printf(CCMD_FORE, (((r*255*255)|(g*255))|b), format, args); va_end(args);}
    void Printf(int rgb, const char* format, ...){ va_list args; va_start(args, format);
        Printf(CCMD_FORE, rgb, format, args); va_end(args); }
    void Printf(int type, int r, int g, int b, const char* format, ...){ va_list args; va_start(args, format);
        Printf(type, (((r*256*256)|g*256)|b), format, args); va_end(args); }
    void PrintfBoth(int FORErgb, int BACKrgb, const char* format, ...){ va_list args; va_start(args, format);
        Fore(FORErgb);
        Back(BACKrgb);
        vprintf(format, args); va_end(args); }
    void PrintfBoth(int FOREr, int FOREg, int FOREb, int BACKr, int BACKg, int BACKb, const char* format, ...){ va_list args; va_start(args, format);
        Fore((((FOREr*256*256)|FOREg*256)|FOREb));
        Back((((BACKr*256*256)|BACKg*256)|BACKb));
        vprintf(format, args); va_end(args); }
    void Reset(){std::cout<<"\x1b[0m";}
}
