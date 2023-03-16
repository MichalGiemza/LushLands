#include "Animal.h"

Animal::Animal(const entitytype entityType, const std::string &description, Position &position, const Size &size, const Color &color, const int movementSpeed, const miliseconds walkInterval) :
    Entity(entityType, description, constant_update), 
    entityUpdater(),
    appearance(color),
    body(position, size),
    collider(&body),
    mobility(&body, movementSpeed),
    dynamicCollider(&collider, &mobility),
    randomWalk(&dynamicCollider, &entityUpdater, walkInterval) {

    //Logger::log(ll::DEBUG_ENTITY, "Created Animal entity [%s;%i,%i]", entityType, position.x(), position.z());
}
Position *Animal::getPosition() {
    return body.getPosition();
}

void Animal::setPosition(Position &position) {
    body.setPosition(position);
}

Size *Animal::getSize() {
    return body.getSize();
}

Collider *Animal::getCollider() {
    return &collider;
}

const Color *Animal::getColor() {
    return appearance.getColor();
}

Entity *Animal::clone() {
    return new Animal(*this);
}

EntityUpdater *Animal::getEntityUpdater() {
    return &entityUpdater;
}

Body *Animal::getBody() {
    return &body;
}