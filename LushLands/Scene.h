#pragma once
#include "Representation.h"

class Scene {
    /**
    * Pozwala na dodawanie element�w �wiata i UI na scen� w celu rysowania i przedstawiania ich u�ytkownikowi.
    */
    scenename name;
public:
    Scene(scenename sceneName);
    void registerGround(Representation representation);
    void registerStructure(Representation representation);
    void registerDynamicEntity(Representation representation);
    //void registerTextUI(TextBox textbox, ScreenPosition sp);
};

