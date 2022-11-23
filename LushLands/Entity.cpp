#include "Entity.h"

Entity::Entity(entitytype entityType, std::string description) {
    this->entityType = entityType;
    this->description = description;
    Logger::log("Entity Chunk [%s]", entityType);
}

entitytype Entity::getType() {
    return entityType;
}

std::string Entity::getDescription() {
    return description;
}
