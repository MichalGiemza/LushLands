#include "ControlManager.h"

Entity *ControlManager::controlledEntity = 0;
Controller *ControlManager::controller = 0;

void ControlManager::setController(Controller *controller) {
    ControlManager::controller = controller;
}

void ControlManager::clearController() {
    ControlManager::controller = 0;
}

void ControlManager::setControlledEntity(Entity *entity) {
    ControlManager::controlledEntity = entity;
}

void ControlManager::clearControlledEntity() {
    ControlManager::controlledEntity = 0;
}

