#include "Animal.h"

Animal::Animal(entitytype entityType, std::string description, Position position, Size size, const Color *color, int movementSpeed_, miliseconds walkInterval) :
    Entity(entityType, description),
    RandomWalk(position, size, movementSpeed_, walkInterval),
    Appearance(color), 
    Body(position, size),
    Collider(position, size),
    Mobility(movementSpeed_, position, size) {

    updateType = constant_update;
    Logger::log(ll::DEBUG_ENTITY, "Created Animal entity [%s;%i,%i]", entityType, position.x(), position.z());
}

Entity *Animal::clone() {
    return new Animal(*this);
}
