#pragma once
#include "Scene.h"
#include "TextureManager.h"

class GraphicsManager {
    /**
    * G³ówna klasa zarz¹dzaj¹ca grafik¹.
    */
    static Scene *gameplayScene;
    static Scene *mainmenuScene;
public:
    static void init();
};

