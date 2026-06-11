#include "./ColorCmd.h"
#include <iostream>

int main(){
    ColorEnable();
    ColorFront(255, 0, 0);
    std::cout << "that's red" << std::endl;
    ColorFront(0, 255, 0);
    std::cout << "that's green" << std::endl;
    ColorFront(0, 0, 255);
    std::cout << "and that's blue" << std::endl;
    ColorReset();
}
