#include "GraphicsManager.h"

GraphicsManager::GraphicsManager(InputEvents *inputEvents, Simulation *simulation) {
    this->simulation = simulation;
    display = new Display(inputEvents);
    textureManager = new TextureManager();
    // Scenes
    gameplayScene = new Scene(GAMEPLAY_SCENE, simulation->getWorld(), display, simulation->getWorldLoadingPosition(), inputEvents, textureManager);
    mainmenuScene = new Scene(MAINMENU_SCENE, simulation->getWorld(), display, simulation->getWorldLoadingPosition(), inputEvents, textureManager);
    currentScene = gameplayScene; // TODO: P�niej ma by� tu main menu
}

Scene *GraphicsManager::getCurrentGameplayScene() {
    return gameplayScene;
}
