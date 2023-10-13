#include "stdafx.h"
#include "GameElement.h"

GameElement::GameElement(objecttype objectType, priority clickPriority, objectgroup objectGroup) {
    this->objectType = objectType;
    this->objectGroup = objectGroup;
    this->clickPriority = clickPriority;
}

objectgroup GameElement::getObjGroup() {
    return objectGroup;
}

objecttype GameElement::getObjType() {
    return objectType;
}

priority GameElement::getPriority() {
    return clickPriority;
}

