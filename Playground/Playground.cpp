#include "Playground.h"
#include <iostream>

int main() {
    Rectangle r = Rectangle(1, 2, 3, 4, false);
    std::cout << r.left() << std::endl;
}