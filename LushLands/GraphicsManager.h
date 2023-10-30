#pragma once
#include "Scene.h"
#include "Display.h"
#include "Simulation.h"
#include "Console.h"


class GraphicsManager {
    /**
    * G³ówna klasa zarz¹dzaj¹ca grafik¹.
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

