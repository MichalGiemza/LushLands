#include "GraphicsManager.h"

GraphicsManager::GraphicsManager(InputEvents *inputEvents, Simulation *simulation) {
    this->simulation = simulation;
    display = new Display(inputEvents);
    textureManager = new TextureManager();
    // Scenes
    gameplayScene = new Scene(GAMEPLAY_SCENE, simulation->getWorld(), display, simulation->getWorldLoadingPosition());
    mainmenuScene = new Scene(MAINMENU_SCENE, simulation->getWorld(), display, simulation->getWorldLoadingPosition());
    currentScene = gameplayScene; // TODO: PóŸniej ma byæ tu main menu
}

Scene *GraphicsManager::getCurrentGameplayScene() {
    return gameplayScene;
}
