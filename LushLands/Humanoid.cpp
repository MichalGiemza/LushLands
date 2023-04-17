#include "Humanoid.h"

Humanoid::Humanoid(InputEvents *inputEvents, const entitytype entityType, const std::string &description, Position &position, const Size &size, const Color &color, const int movementSpeed, name firstName, name lastName, gendertype gender, const int invSize, int maxHealth, const tooltype requiredTool, const ItemDropChance *drops) :
    Entity(entityType, description, constant_update, inputEvents),
    entityUpdater(),
    appearance(color),
    body(position, size),
    collider(&body),
    dynamicCollider(&collider),
    mobility(&dynamicCollider, &entityUpdater, movementSpeed),
    firstName(firstName),
    lastName(lastName),
    gender(gender),
    inventory(invSize, body.getPosition()),
    destroyability(this, inputEvents, maxHealth, requiredTool, drops),
    gameElement(ft::HUMANOID, fp::HUMANOID, fg::SIMULATION) {
}

Entity *Humanoid::clone() {
    return new Humanoid(*this);
}

void *Humanoid::getEntityUpdater() {
    return &entityUpdater;
}

void *Humanoid::getGameElement() {
    return &gameElement;
}

void *Humanoid::getColor() {
    return (void *)appearance.getColor();
}

void *Humanoid::getAppearance() {
    return &appearance;
}

void *Humanoid::getMobility() {
    return &mobility;
}

void *Humanoid::getCollider() {
    return &collider;
}

void *Humanoid::getDynamicCollider() {
    return &dynamicCollider;
}

void *Humanoid::getRandomWalk() {
    return nullptr;
}

void *Humanoid::getBody() {
    return &body;
}

void *Humanoid::getSize() {
    return body.getSize();
}

void *Humanoid::getPosition() {
    return body.getPosition();
}

void *Humanoid::getDestroyability() {
    return &destroyability;
}

void *Humanoid::getFirstName() {
    return (void *)firstName;
}

void *Humanoid::getLastName() {
    return (void *)lastName;
}

void *Humanoid::getInventory() {
    return &inventory;
}
