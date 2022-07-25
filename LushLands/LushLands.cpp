#include "LushLands.h"

void init() {
    if (!al_init()) {
        UI::abortStart("Could not init Allegro.\n");
    }
    Events::init();
    Display::init();
    Logger::init();
    Input::init();
    UI::running = true;
}

void main_loop() {
    Events::mainLoop();
}

void log_key(int key) {
    Logger::logKey("Key", key, 0, 0);
}

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    init();

    Input::assignActionToKeyDown(23, log_key);

    //Logger::logPrintf("FPS: % f", Display::getCurrentFPS());

    main_loop();

    return 0;
}
