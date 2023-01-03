#include "GraphicsManager.h"

GraphicsManager::GraphicsManager(Controller *controller, Simulation *simulation) {
    this->simulation = simulation;
    display = new Display(controller->getInputEvents());
    textureManager = new TextureManager();
    console = new Console(display, textureManager);
    // Scenes
    gameplayScene = new Scene(GAMEPLAY_SCENE, simulation->getWorld(), display, simulation->getWorldLoadingPosition(), controller->getInputEvents(), textureManager, controller->getFocus(), console);
    mainmenuScene = new Scene(MAINMENU_SCENE, simulation->getWorld(), display, simulation->getWorldLoadingPosition(), controller->getInputEvents(), textureManager, controller->getFocus(), console);
    currentScene = gameplayScene; // TODO: PóŸniej ma byæ tu main menu
}

Scene *GraphicsManager::getCurrentGameplayScene() {
    return gameplayScene;
}
