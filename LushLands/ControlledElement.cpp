#include "ControlledElement.h"

void ControlledElement::setFocusedObject(GameElement *focusedObject) {
    this->focusedObject = focusedObject;
}

GameElement *ControlledElement::getCurrentlyActiveGameElement() {
    return focusedObject;
}
