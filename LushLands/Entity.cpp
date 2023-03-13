#include "Entity.h"

Entity::Entity(entitytype entityType, std::string description, updatetype updateType) :
    entityType(entityType),
    description(description),
    updateType(updateType) 
{ }

entitytype Entity::getType() {
    return entityType;
}

updatetype Entity::getUpdateType() {
    return updateType;
}

std::string Entity::getDescription() {
    return description;
}
