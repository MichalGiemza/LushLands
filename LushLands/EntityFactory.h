#pragma once
#include "Entity.h"
#include "DataTypes.h"
#include "ConstantSets.h"
#include "Ground.h"

class EntityFactory {
    /**
    * Klasa tworz�ca wybrane elemenety �wiata - entity.
    * 
    */
    static std::unordered_map<entitytype, Entity *> prefabs;
private:
    static void setupPrefabs();
public:
    static void init();
    static Entity *buildEntity(entitytype entityType);
};

