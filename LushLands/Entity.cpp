#include "Entity.h"

Entity::Entity(entitytype entityType, std::string description, updatetype updateType, InputEvents *inputEvents) :
    entityType(entityType), description(description), updateType(updateType), inputEvents(inputEvents) { }

entitytype Entity::getType() {
    return entityType;
}

updatetype Entity::getUpdateType() {
    return updateType;
}

std::string Entity::getDescription() {
    return description;
}

Entity *Entity::clone() {
    return nullptr;
}
