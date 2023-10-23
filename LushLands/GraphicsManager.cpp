#include "stdafx.h"
#include "GraphicsManager.h"


GraphicsManager::GraphicsManager(Core *core, Controller *controller, Simulation *simulation) {
    this->simulation = simulation;
    display = new Display(controller->getInputEvents(), core);
    console = new Console(display);
    // Scenes
    gameplayScene = new Scene(GAMEPLAY_SCENE, core, controller, simulation, display, console);
    mainmenuScene = new Scene(MAINMENU_SCENE, core, controller, simulation, display, console);
    currentScene = gameplayScene; // TODO: PóŸniej ma byæ tu main menu
}

Scene *GraphicsManager::getCurrentGameplayScene() {
    return gameplayScene;
}

Display *GraphicsManager::getDisplay() {
    return display;
}

