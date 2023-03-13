#include "Structure.h"

Structure::Structure(const entitytype entityType, const std::string &description, Position &position, const Size &size, const Color &color, const updatetype updateType) :
    Entity(entityType, description, updateType),
    entityUpdater(),
    appearance(color),
    body(position, size),
    collider(&body) {

    //Logger::log(ll::DEBUG_ENTITY, "Created Structure entity [%s;%i,%i]", entityType, position.x(), position.z());
}

Entity *Structure::clone() {
    return new Structure(*this);
}

Position *Structure::getPosition() {
    return body.getPosition();
}

Size *Structure::getSize() {
    return body.getSize();
}

const Color *Structure::getColor() {
    return appearance.getColor();
}

Collider *Structure::getCollider() {
    return &collider;
}
