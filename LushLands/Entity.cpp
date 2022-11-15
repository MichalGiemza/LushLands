#include "Entity.h"

inline Entity::Entity(string typeName, string description) {
    this->typeName = typeName;
    this->description = description;
}

inline string Entity::getTypeName() {
    return typeName;
}

inline string Entity::getDescription() {
    return description;
}
