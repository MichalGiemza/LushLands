#include "LushLands.h"
#include "ActionMap.h"

void init() {
    if (!al_init()) {
        UI::abortStart("Could not init Allegro.\n");
    }
    Events::init();
    Display::init();
    Logger::init();
    ActionMap::init();
    Controller::init();

    UI::initialized = true;
}

void main_loop() {
    UI::running = true;
    Events::mainLoop();
}

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    init();

    //Logger::logPrintf("FPS: % f", Display::getCurrentFPS());

    main_loop();

    return 0;
}
