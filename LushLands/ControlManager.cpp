#include "ControlManager.h"

Entity *ControlManager::controlledEntity = 0;
InputController *ControlManager::controller = 0;

void ControlManager::setController(InputController *controller) {
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

