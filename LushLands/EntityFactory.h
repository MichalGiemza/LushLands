#pragma once
#include "Entity.h"
#include "DataTypes.h"
#include "ConstantSets.h"
#include "EntityConstants.h"
#include "Ground.h"
#include "Structure.h"
#include "Animal.h"

class EntityFactory {
    /**
    * Klasa tworz¹ca wybrane elemenety œwiata - entity.
    * 
    */
public:
    Entity *buildEntity(entitytype entityType, Position &position);
};

