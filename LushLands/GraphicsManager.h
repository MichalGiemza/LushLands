#pragma once
#include "Scene.h"
#include "Display.h"
#include "TextureManager.h"
#include "Simulation.h"

class GraphicsManager {
    /**
    * G��wna klasa zarz�dzaj�ca grafik�.
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

