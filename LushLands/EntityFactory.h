#pragma once
#include "Entity.h"
#include "DataTypes.h"
#include "ConstantSets.h"
#include "Ground.h"

class EntityFactory {
    /**
    * Klasa tworz¹ca wybrane elemenety œwiata - entity.
    * 
    */
    std::unordered_map<entitytype, Entity *> prefabs;
private:
    void setupPrefabs();
public:
    EntityFactory();
    Entity *buildEntity(entitytype entityType);
};

