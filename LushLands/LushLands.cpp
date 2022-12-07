#include "LushLands.h"

bool initialized = false;
bool running = false;
InputEvents *inputEvents;
Controller *controller;
GraphicsManager *graphicsManager;
Simulation *simulation;


void init() {
    // Controller
    if (!al_init())
        throw std::logic_error(could_not_init_allegro);
    ActionMap::init(); // TODO: Przenieść? 
    Logger::init();
    inputEvents = new InputEvents();
    controller = new Controller(inputEvents);
    // Model
    simulation = new Simulation(inputEvents);
    // View
    graphicsManager = new GraphicsManager(inputEvents, simulation);
    initialized = true;
}

void main_loop() {
    if (!initialized)
        throw std::logic_error(cannot_run_uninitialized);
    running = true;
    inputEvents->mainLoop(&running);
}

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    try {
        init();
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try {
        main_loop();
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
