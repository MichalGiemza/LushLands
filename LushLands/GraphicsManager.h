#pragma once
#include "Scene.h"
#include "Display.h"
#include "TextureManager.h"
#include "Simulation.h"

class GraphicsManager {
    /**
    * G³ówna klasa zarz¹dzaj¹ca grafik¹.
    */
    Simulation *simulation;
    Display *display;
    TextureManager *textureManager;

    Scene *currentScene;
    Scene *gameplayScene;
    Scene *mainmenuScene;
public:
    GraphicsManager(InputEvents *inputEvents, Simulation *simulation);
    Scene *getCurrentGameplayScene();
};

