#pragma once
#include "Entity.h"
#include "Controller.h"

using namespace std;

class ControlManager {
    /**
    * Pozwala na kontrolowanie elementów symulacji za pomoc¹ danych wejœciowych.
    * Klasa pozwala na kontrolê obiektów œwiata poprzez wejœcia z UI (podane przez Connectory).
    */
    static Entity *controlledEntity; // IControlNode
    static Keyboard *controller;
public:
    void setController(Keyboard *controller);
    void clearController();
    void setControlledEntity(Entity *entity);
    void clearControlledEntity();
};

