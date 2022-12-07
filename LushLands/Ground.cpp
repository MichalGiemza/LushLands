#include "Ground.h"

Ground::Ground(entitytype entityType, std::string description, Position position, Size size, texturename textureName, Color color) :
    Entity(entityType, description),
    Body(position, size) {

    Logger::log("Created Ground entity [%s;%i,%i]", entityType, position.x(), position.z());
}

Entity *Ground::clone() {
    return new Ground(*this);
}
