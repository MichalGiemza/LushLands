#pragma once
#include "JsonHandler.h"
#include "DataTypes.h"
#include "Entity.h"
#include "NameGenerator.h"
#include "Directories.h"
#include "Ground.h"
#include "Structure.h"
#include "Animal.h"
#include "Humanoid.h"
#include "CtorParamStructures.h"


class EntityFactory {
    /**
    * Klasa tworz¹ca wybrane elemenety œwiata - entity.
    * 
    */
    NameGenerator *nameGenerator;
    InputEvents *inputEvents;
    std::unordered_map<entitytype, templateclass> entityToTemplateMap;
    std::unordered_map<entitytype, Entity *> flyweightMap;

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
    Entity *buildEntity(entitytype entityType, Position &position, bool flyweight=false);
};

