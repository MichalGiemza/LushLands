#pragma once
#include <climits>
#include "DataTypes.h"

class GameElement {
    /**
    * Most basic element of game.
    * Needs to be inherited by everything, that shows up on the screen.
    * Highest click priority is lovest value of "clickPriority".
    */
    objecttype objectType = 0;
    objectgroup objectGroup = 0;
    priority clickPriority = USHRT_MAX;
public:
    GameElement(objecttype objectType, priority clickPriority, objectgroup objectGroup);
    objecttype getObjType();
    objectgroup getObjGroup();
    priority getPriority();
};

