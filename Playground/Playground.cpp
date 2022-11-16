#include <windows.h>
#include <iostream>
#include <exception>

bool initialized = false;

void main_loop() {
    if (!initialized)
        throw std::exception("Cannot run main loop without initialization.");
    ;
}


int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    try {
        //init();
        main_loop();
    } catch (std::exception &e) {
        std::cout << "Unhandled exception: " << e.what() << std::endl;
    }
}