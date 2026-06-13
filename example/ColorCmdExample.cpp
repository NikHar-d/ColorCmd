#include <ColorCmd.h>
#include <iostream>

int main(){
    ColorCmd::Init();
    ColorCmd::Fore(255, 0, 0);
    std::cout << "that's red" << std::endl;
    ColorCmd::Fore(0, 255, 0);
    std::cout << "that's green" << std::endl;
    ColorCmd::Fore(0, 0, 255);
    std::cout << "and that's blue" << std::endl;
    ColorCmd::Reset();
}
