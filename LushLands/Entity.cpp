#include "stdafx.h"
#include "Entity.h"

boost::uuids::random_generator uuidGenerator;

Entity::Entity(entitytype entityType, std::string description, updatetype updateType, InputEvents *inputEvents) :
    entityType(entityType), description(description), updateType(updateType), inputEvents(inputEvents), id(uuidGenerator()) { }

entitytype Entity::getType() {
    return entityType;
}

updatetype Entity::getUpdateType() {
    return updateType;
}

std::string Entity::getDescription() {
    return description;
}

void Entity::handleChunkRegister() {
    for (auto &p : onChunkReg)
        (*p.first)(p.second);
}

void Entity::handleChunkUnregister() {
    for (auto &p : onChunkUnreg)
        (*p.first)(p.second);
}

bool operator==(const Entity &e1, const Entity &e2) {
    return e1.id == e2.id;
}

