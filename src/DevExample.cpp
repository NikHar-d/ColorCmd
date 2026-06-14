#include "ColorCmd.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    if (argc<=1)
        ColorCmd::Init();
    ColorCmd::Fore(255, 0, 0);
    std::cout << "that's red" << std::endl;
    ColorCmd::Fore(0, 255, 0);
    std::cout << "that's green" << std::endl;
    ColorCmd::Fore(0, 0, 255);
    std::cout << "and that's blue" << std::endl;
    ColorCmd::Reset();
    std::cout << "default color" << std::endl;

    char* text = const_cast<char*>("many color here");
    int textLen = 15;
    for (int i = 0; i < textLen; i++){
        ColorCmd::Fore(i*15, 255-i*15, 50+i*15);
        ColorCmd::Back(i*15,i*15,i*15);
        std::cout << text[i];
    }
    ColorCmd::Printf(255,0,0,"Printf working here with color of R%i G%i B%i", 255, 0, 0);
    ColorCmd::Reset();
    std::cout << '\n';
    ColorCmd::Printf(0, 0xff0000, "hex red\n");
    ColorCmd::Printf(0, 0x00ff00, "hex green\n");
    ColorCmd::Printf(0, 0x0000ff, "hex blue\n");
    ColorCmd::Reset();

    ColorCmd::Printf(0, 200, 40, 100, "r g b %i\n", 123);
    ColorCmd::Printf(0, 0x123456, "rgb %i\n", 123);
    ColorCmd::Printf(CCMD_FORE, 255, 255, 0, "type r g b (fore) %i\n", 123);
    ColorCmd::Printf(CCMD_FORE, 0xff4000, "type rgb (fore) %i\n", 123);
    ColorCmd::Printf(CCMD_BACK, 35, 35, 35, "type r g b (back) %i\n", 123);
    ColorCmd::Printf(CCMD_BACK, 0x888888, "type rgb (back) %i\n", 123);
    ColorCmd::PrintfBoth(0xffffff, 0x0000ff, "both rgb rgb %i\n", 123);
    ColorCmd::PrintfBoth(255,255,255,255,0,0, "both r g b r g b %i\n", 123);

    ColorCmd::Warn("This is a warn message number %i", 1);
    ColorCmd::Warn("This is a warn message number %i", 2);

    ColorCmd::Reset();
}
