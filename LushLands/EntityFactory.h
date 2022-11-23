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
    static std::unordered_map<entitytype, Entity *> prefabs;
private:
    static void setupPrefabs();
public:
    static void init();
    static Entity *buildEntity(entitytype entityType);
};

