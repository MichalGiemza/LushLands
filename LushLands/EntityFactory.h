#pragma once
#include "Entity.h"
#include "DataTypes.h"
#include "ConstantSets.h"
#include "EntityConstants.h"
#include "Ground.h"
#include "Structure.h"
#include "Animal.h"
#include "Humanoid.h"
#include "NameGenerator.h"


class EntityFactory {
    /**
    * Klasa tworz¹ca wybrane elemenety œwiata - entity.
    * 
    */
    NameGenerator *nameGenerator;
    InputEvents *inputEvents;
public:
    EntityFactory(InputEvents *inputEvents);
    Entity *buildEntity(entitytype entityType, Position &position);
};

