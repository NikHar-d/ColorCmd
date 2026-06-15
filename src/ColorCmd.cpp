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
    
    int _rgb_r(int rgb){return (rgb&0xff0000)>>16;}
    int _rgb_g(int rgb){return (rgb&0x00ff00)>>8;}
    int _rgb_b(int rgb){return (rgb&0x0000ff);}
    int _rgb(int r, int g, int b){return ((r*256*256)|(g*256))|b;}

    void Fore(int r, int g, int b){
        std::cout<<"\x1b[38;2;"<<r<<";"<<g<<";"<<b<<"m";
    }
    void Fore(int rgb){
       std::cout<<"\x1b[38;2;"<<_rgb_r(rgb)<<";"<<_rgb_g(rgb)<<";"<<_rgb_b(rgb)<<"m";
    }
    void Back(int r, int g, int b){
       std::cout<<"\x1b[48;2;"<<r<<";"<<g<<";"<<b<<"m";
    }
    void Back(int rgb){
       std::cout<<"\x1b[48;2;"<<_rgb_r(rgb)<<";"<<_rgb_g(rgb)<<";"<<_rgb_b(rgb)<<"m";
    }
    void Reset(){
       std::cout<<"\x1b[0m";
    }

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

    void Printf(int r, int g, int b, const char* format, ...){
        va_list args;
        va_start(args, format);
        Printf(CCMD_FORE, _rgb(r,g,b), format, args);
        va_end(args);
    }
    void Printf(int rgb, const char* format, ...){
        va_list args;
        va_start(args, format);
        Printf(CCMD_FORE, rgb, format, args);
        va_end(args); 
    }
    void Printf(int type, int r, int g, int b, const char* format, ...){
        va_list args;
        va_start(args, format);
        Printf(type, _rgb(r,g,b), format, args);
        va_end(args); 
    }
    void PrintfBoth(int FORErgb, int BACKrgb, const char* format, ...){
        va_list args;
        va_start(args, format);
        Fore(FORErgb);
        Back(BACKrgb);
        vprintf(format, args);
        va_end(args);
    }
    void PrintfBoth(int FOREr, int FOREg, int FOREb, int BACKr, int BACKg, int BACKb, const char* format, ...){
        va_list args;
        va_start(args, format);
        Fore(_rgb(FOREr,FOREg,FOREb));
        Back(_rgb(BACKr,BACKg,BACKb));
        vprintf(format, args);
        va_end(args);
    }

    void Warn(const char* format, ...){
        va_list args;
        va_start(args, format);
        Reset();
        Back(0x333300);
        Printf(CCMD_FORE, 0xffff00, format, args);
        Reset();
        std::cout<<'\n';
        va_end(args);
    }
    void Err(const char* format, ...){
        va_list args;
        va_start(args, format);
        Reset();
        Printf(CCMD_BACK, 0xff0000, format, args);
        Reset();
        std::cout<<'\n';
        va_end(args);
    }
    void Good(const char* format, ...){
        va_list args;
        va_start(args, format);
        Reset();
        Printf(CCMD_FORE, 0x00cc00, format, args);
        Reset();
        std::cout<<'\n';
        va_end(args);
    }
}
