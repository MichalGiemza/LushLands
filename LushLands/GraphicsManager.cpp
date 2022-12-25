#include "GraphicsManager.h"

GraphicsManager::GraphicsManager(Controller *controller, Simulation *simulation) {
    this->simulation = simulation;
    display = new Display(controller->getInputEvents());
    textureManager = new TextureManager();
    // Scenes
    gameplayScene = new Scene(GAMEPLAY_SCENE, simulation->getWorld(), display, simulation->getWorldLoadingPosition(), controller->getInputEvents(), textureManager, controller->getFocus());
    mainmenuScene = new Scene(MAINMENU_SCENE, simulation->getWorld(), display, simulation->getWorldLoadingPosition(), controller->getInputEvents(), textureManager, controller->getFocus());
    currentScene = gameplayScene; // TODO: PóŸniej ma byæ tu main menu
}

Scene *GraphicsManager::getCurrentGameplayScene() {
    return gameplayScene;
}
