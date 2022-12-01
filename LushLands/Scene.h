#pragma once
#include "Representation.h"

class Scene {
    /**
    * Pozwala na dodawanie elementów œwiata i UI na scenê w celu rysowania i przedstawiania ich u¿ytkownikowi.
    */
    scenename name;
public:
    Scene(scenename sceneName);
    void registerGround(Representation representation);
    void registerStructure(Representation representation);
    void registerDynamicEntity(Representation representation);
    //void registerTextUI(TextBox textbox, ScreenPosition sp);
};

