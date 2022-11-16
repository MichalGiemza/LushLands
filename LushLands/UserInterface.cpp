#include "UserInterface.h"


void UserInterface::abortStart(char const *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    exit(1);
}

void UserInterface::init() {
    Display::init();
    Controller::init();
}
