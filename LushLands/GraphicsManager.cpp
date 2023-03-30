#include "GraphicsManager.h"

GraphicsManager::GraphicsManager(Controller *controller, Simulation *simulation) {
    this->simulation = simulation;
    display = new Display(controller->getInputEvents());
    textureManager = new TextureManager();
    console = new Console(display, textureManager);
    // Scenes
    gameplayScene = new Scene(GAMEPLAY_SCENE, simulation->getWorld(), display, simulation->getWorldLoadingPosition(), controller->getInputEvents(), textureManager, controller->getFocus(), console, simulation->getPlayer());
    mainmenuScene = new Scene(MAINMENU_SCENE, simulation->getWorld(), display, simulation->getWorldLoadingPosition(), controller->getInputEvents(), textureManager, controller->getFocus(), console, simulation->getPlayer());
    currentScene = gameplayScene; // TODO: P�niej ma by� tu main menu
}

Scene *GraphicsManager::getCurrentGameplayScene() {
    return gameplayScene;
}

TextureManager *GraphicsManager::getTextureManager() {
    return textureManager;
}

Display *GraphicsManager::getDisplay() {
    return display;
}

