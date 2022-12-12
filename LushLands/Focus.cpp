#include "Focus.h"

void Focus::setFocusedObject(GameElement *focusedObject) {
    this->focusedObject = focusedObject;
}

GameElement *Focus::getFocusedObject() {
    return focusedObject;
}
