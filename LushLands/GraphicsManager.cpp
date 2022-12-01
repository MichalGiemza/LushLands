#include "GraphicsManager.h"

Scene *GraphicsManager::gameplayScene = 0;
Scene *GraphicsManager::mainmenuScene = 0;


void GraphicsManager::init() {
    TextureManager::init();
    gameplayScene = new Scene(GAMEPLAY_SCENE);
    mainmenuScene = new Scene(MAINMENU_SCENE);

}
