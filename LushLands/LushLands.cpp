#include "LushLands.h"

bool initialized = false;
bool running = false;

GraphicsManager *graphicsManager;
Simulation *simulation;
Controller *controller;

void init() {
    // Controller
    controller = new Controller();
    // Model
    simulation = new Simulation(controller);
    // View
    graphicsManager = new GraphicsManager(controller, simulation);
    // Done
    controller->postInit(graphicsManager->getTextureManager()->getTexture(CURSOR_TEXTURE_LOCALIZATION)); // FIXME
    graphicsManager->getDisplay()->setCursor(controller->getMouse()->getCursor());
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
