#include "LushLands.h"
#include "Simulation.h"

bool initialized = false;
bool running = false;

void init() {
    if (!al_init()) {
        UI::abortStart("Could not init Allegro.\n");
    }
    Events::init();
    DataMappers::init();
    UI::init();
    Logger::init();
    Simulation::init();
    initialized = true;
}

void main_loop() {
    if (!initialized)
        throw std::exception("Cannot run main loop without initialization.");
    running = true;
    Events::mainLoop(&running);
}

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    try {
        init();
        main_loop();
    } catch (std::exception &e) {
        std::cout << "Unhandled exception: " << e.what() << std::endl;
    }
    return 0;
}
