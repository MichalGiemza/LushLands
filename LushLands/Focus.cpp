#include "Focus.h"

void Focus::setFocusedObject(GameElement *focusedObject) {
    this->focusedObject = focusedObject;
}

GameElement *Focus::getCurrentlyActiveGameElement() {
    return focusedObject;
}
