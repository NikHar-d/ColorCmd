#include "ColorCmd.h"
#include <iostream>
#include <string>

int main(){
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
    ColorCmd::Printf(0xff0000, "hex red\n");
    ColorCmd::Printf(0x00ff00, "hex green\n");
    ColorCmd::Printf(0x0000ff, "hex blue\n");
    ColorCmd::Reset();
}
