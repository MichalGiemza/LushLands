#include "Ground.h"

Ground::Ground(entitytype entityType, std::string description, Position position, Size size, texturename textureName, Color color) :
    Entity(entityType, description),
    Body(position, size),
    Representation(textureName, color) {
}

Entity *Ground::clone() {
    return new Ground(*this);
}
