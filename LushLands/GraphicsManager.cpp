#include "stdafx.h"
#include "GraphicsManager.h"


GraphicsManager::GraphicsManager(Core *core, Controller *controller, Simulation *simulation) {
    this->simulation = simulation;
    display = new Display(controller->getInputEvents(), core);
    textureManager = new TextureManager();
    console = new Console(display, textureManager);
    // Scenes
    gameplayScene = new Scene(GAMEPLAY_SCENE, core, controller, simulation, display, textureManager, console);
    mainmenuScene = new Scene(MAINMENU_SCENE, core, controller, simulation, display, textureManager, console);
    currentScene = gameplayScene; // TODO: PóŸniej ma byæ tu main menu
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

