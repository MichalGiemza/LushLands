#include "Representation.h"

Representation::Representation(texturename textureName, Color color, Body *body) : textureName(textureName), color(color), body(body) {
    texture = TextureManager::getTexture(textureName);
}

Color Representation::getColor() {
    return color;
}

texturename Representation::getTextureName() {
    return textureName;
}

ALLEGRO_BITMAP *Representation::getTexture() {
    return texture;
}

Body *Representation::getBody() {
    return body;
}
