#pragma once
#include "Scene.h"
#include "TextureManager.h"

class GraphicsManager {
    /**
    * G��wna klasa zarz�dzaj�ca grafik�.
    */
    static Scene *gameplayScene;
    static Scene *mainmenuScene;
public:
    static void init();
};

