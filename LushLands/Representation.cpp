#include "Representation.h"

Representation::Representation(texturename textureName, Color color) : textureName(textureName), color(color) {}

Color Representation::getColor() {
    return color;
}

texturename Representation::getTextureName() {
    return textureName;
}
