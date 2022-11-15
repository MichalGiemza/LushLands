#pragma once
#include "Entity.h"
#include "Controller.h"

using namespace std;

class ControlManager {
    /**
    * Pozwala na kontrolowanie element�w symulacji za pomoc� danych wej�ciowych.
    * Klasa pozwala na kontrol� obiekt�w �wiata poprzez wej�cia z UI (podane przez Connectory).
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

