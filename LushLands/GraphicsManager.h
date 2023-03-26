#pragma once
#include "Scene.h"
#include "Display.h"
#include "TextureManager.h"
#include "Simulation.h"
#include "Console.h"

class GraphicsManager {
    /**
    * G��wna klasa zarz�dzaj�ca grafik�.
    */
    Simulation *simulation;
    Display *display;
    TextureManager *textureManager;
    Console *console;

    Scene *currentScene;
    Scene *gameplayScene;
    Scene *mainmenuScene;
public:
    GraphicsManager(Controller *controller, Simulation *simulation);
    Scene *getCurrentGameplayScene();
    TextureManager *getTextureManager();
    Display *getDisplay();
};

