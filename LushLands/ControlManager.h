#pragma once
#include "Entity.h"
#include "Controller.h"

using namespace std;

class ControlManager {
    /**
    * Pozwala na kontrolowanie elementów symulacji za pomoc¹ danych wejœciowych.
    * Klasa pozwala na kontrolê obiektów œwiata poprzez wejœcia z UI (podane przez Connectory).
    */
    Entity* controlledEntity; // IControlNode
    Controller* controller;
public:
    ControlManager();
    void setController(Controller controller);
    void clearController();
    void setControlledEntity(Entity entity);
    void clearControlledEntity();
};

