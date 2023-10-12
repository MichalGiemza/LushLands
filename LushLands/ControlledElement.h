#pragma once
#include "GameElement.h"

class ControlledElement {
    /**
    * Contains pointer to currently selected object.
    * Meant to be singleton. 
    */
    GameElement *focusedObject;
public:
    void setFocusedObject(GameElement *focusedObject);
    GameElement *getCurrentlyActiveGameElement();
};

