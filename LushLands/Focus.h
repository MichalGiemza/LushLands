#pragma once
#include "GameElement.h"

class Focus {
    /**
    * Contains pointer to currently selected object.
    * Meant to be singleton. 
    */
    GameElement *focusedObject;
public:
    void setFocusedObject(GameElement *focusedObject);
    GameElement *getCurrentlyActiveGameElement();
};

