#include "LushLands.h"

bool initialized = false;
bool running = false;

GraphicsManager *graphicsManager;
Simulation *simulation;
Controller_ *controller;

void init() {
    // Controller
    controller = new Controller_();
    // Model
    simulation = new Simulation(controller);
    // View
    graphicsManager = new GraphicsManager(controller, simulation);
    // Done
    initialized = true;
}

void main_loop() {
    if (!initialized)
        throw std::logic_error(cannot_run_uninitialized);
    running = true;
    controller->getInputEvents()->mainLoop(&running);
}

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    //try {
        init();
    //} catch (std::exception &e) {
    //    std::cout << "Exception: " << e.what() << std::endl;
    //}
    //try {
        main_loop();
    //} catch (std::exception &e) {
    //    std::cout << "Exception: " << e.what() << std::endl;
    //}
    return 0;
}
