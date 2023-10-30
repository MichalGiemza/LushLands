#pragma once
#include "Scene.h"
#include "Display.h"
#include "Simulation.h"
#include "Console.h"


class GraphicsManager {
    /**
    * G��wna klasa zarz�dzaj�ca grafik�.
    */
    Simulation *simulation;
    Display *display;
    Console *console;

    Scene *currentScene;
    Scene *gameplayScene;
    Scene *mainmenuScene;

public:
    GraphicsManager(Core *core, Controller *controller, Simulation *simulation);
    Scene *getCurrentGameplayScene();
    Display *getDisplay();
};

