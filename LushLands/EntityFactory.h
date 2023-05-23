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
#include "JsonHandler.h"
#include "CtorParamStructures.h"
#include <unordered_map>
#include "Directories.h"
#include "JsonHandler.h"
#include "ConstSelector.h"


class EntityFactory {
    /**
    * Klasa tworz¹ca wybrane elemenety œwiata - entity.
    * 
    */
    NameGenerator *nameGenerator;
    InputEvents *inputEvents;
    std::unordered_map<entitytype, templateclass> entityToTemplateMap;

    std::unordered_map<entitytype, HumanoidCtorParams *> humanoidParams;
    std::unordered_map<entitytype, AnimalCtorParams *> animalParams;
    std::unordered_map<entitytype, StructureCtorParams *> structureParams;
    std::unordered_map<entitytype, GroundCtorParams *> groundParams;
private:
    void loadCtorParams();
    void loadHumanoidCtorParams(const fs::path fp);
    void loadAnimalCtorParams(const fs::path fp);
    void loadStructureCtorParams(const fs::path fp);
    void loadGroundCtorParams(const fs::path fp);
public:
    EntityFactory(InputEvents *inputEvents);
    Entity *buildEntity(entitytype entityType, Position &position);
};

