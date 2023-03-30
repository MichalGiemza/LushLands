#include "Humanoid.h"

Humanoid::Humanoid(const entitytype entityType, const std::string &desc, Position &p, const Size &s, const Color &c, const int mSpeed, name fName, name lName, gendertype gender, const int invSize) :
    Entity(entityType, desc, constant_update),
    entityUpdater(),
    appearance(c),
    body(p, s),
    collider(&body),
    dynamicCollider(&collider),
    mobility(&dynamicCollider, &entityUpdater, mSpeed),
    firstName(fName),
    lastName(lName),
    gender(gender),
    inventory(invSize),
    gameElement(ft::HUMANOID, fp::HUMANOID, fg::SIMULATION) {
}

DynamicCollider *Humanoid::getDynamicCollider() {
    return &dynamicCollider;
}

name Humanoid::getFirstName() {
    return firstName;
}

name Humanoid::getLastName() {
    return lastName;
}

void Humanoid::setFirstName(name newName) {
    firstName = newName;
}

void Humanoid::setLastName(name newName) {
    lastName = newName;
}

GameElement *Humanoid::getGameElement() {
    return &gameElement;
}

Inventory *Humanoid::getInventory() {
    return &inventory;
}


Position *Humanoid::getPosition() {
    return body.getPosition();
}

void Humanoid::setPosition(Position &position) {
    body.setPosition(position);
}

Size *Humanoid::getSize() {
    return body.getSize();
}

Collider *Humanoid::getCollider() {
    return &collider;
}

const Color *Humanoid::getColor() {
    return appearance.getColor();
}

Entity *Humanoid::clone() {
    return new Humanoid(*this);
}

EntityUpdater *Humanoid::getEntityUpdater() {
    return &entityUpdater;
}

Body *Humanoid::getBody() {
    return &body;
}

Mobility *Humanoid::getMobility() {
    return &mobility;
}
