#include "Entity.h"

Entity::Entity(entitytype entityType, std::string description) {
    this->entityType = entityType;
    this->description = description;
}

entitytype Entity::getType() {
    return entityType;
}

std::string Entity::getDescription() {
    return description;
}
