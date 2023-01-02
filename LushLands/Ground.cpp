#include "Ground.h"

Ground::Ground(entitytype entityType, std::string description, Position position, Size size, const Color *color) :
    Entity(entityType, description),
    Body(position, size),
    Appearance(color) {

    Logger::log(ll::DEBUG_ENTITY, "Created Ground entity [%s;%i,%i]", entityType, position.x(), position.z());
}

Entity *Ground::clone() {
    return new Ground(*this);
}
