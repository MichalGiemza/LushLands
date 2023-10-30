#include "EntityFactory.h"


EntityFactory::EntityFactory(InputEvents *inputEvents) : inputEvents(inputEvents) {
    nameGenerator = new NameGenerator(common_male_names_path, common_female_names_path, common_neutral_names_path);
    loadCtorParams();
}

void EntityFactory::loadCtorParams() {
    // Humanoids
    auto filesH = Directories::listDir(ctorParamsHumanoid);
    for (auto &fp : filesH)
        loadHumanoidCtorParams(fp.path());
    // Animals
    auto filesA = Directories::listDir(ctorParamsAnimal);
    for (auto &fp : filesA)
        loadAnimalCtorParams(fp.path());
    // Structures
    auto filesS = Directories::listDir(ctorParamsStructure);
    for (auto &fp : filesS)
        loadStructureCtorParams(fp.path());
    // Ground
    auto filesG = Directories::listDir(ctorParamsGround);
    for (auto &fp : filesG)
        loadGroundCtorParams(fp.path());
}

void EntityFactory::loadHumanoidCtorParams(const fs::path fp) {
    auto data = JsonHandler::parseJson(fp);
    const json::object &d = data->as_object();

    auto et = a_s(d, "EntityType");
    auto des = a_s(d, "Description");
    auto &sz = d.at("Size").as_object();
    auto &cl = d.at("Color").as_object();
    auto &ms = d.at("MovementSpeed");
    auto &is = d.at("InventorySlots");
    auto &hl = d.at("Health");
    auto rt = a_s(d, "ToolType");
    auto &dp = d.at("EntityDrops").as_array();
    
    float sw = sz.at("W").as_double();
    float sh = sz.at("H").as_double();
    float sl = sz.at("L").as_double();
    
    float cr = cl.at("R").as_int64();
    float cg = cl.at("G").as_int64();
    float cb = cl.at("B").as_int64();

    entitytype entityType = CR::selectEntityType(et, true);

    HumanoidCtorParams *params = new HumanoidCtorParams {
        inputEvents,
        entityType,
        new std::string(des.c_str()),
        nullptr,
        CR::selectSize(sw, sh, sl),
        CR::selectColor(cr, cg, cb),
        (int)ms.as_int64(),
        nullptr,
        nullptr,
        nullptr,
        (int)is.as_int64(),
        (int)hl.as_int64(),
        CR::selectToolType(rt, true),
        CR::selectEntityDrops(dp)
    };

    humanoidParams[entityType] = params;
    entityToTemplateMap[entityType] = tc::HUMANOID;
}

void EntityFactory::loadAnimalCtorParams(const fs::path fp) {
    auto data = JsonHandler::parseJson(fp);
    auto &d = data->as_object();

    auto et = a_s(d, "EntityType");
    auto des = a_s(d, "Description");
    auto &sz = d.at("Size").as_object();
    auto &cl = d.at("Color").as_object();
    auto &ms = d.at("MovementSpeed");
    auto &wi = d.at("WalkInterval");
    auto &hl = d.at("Health");
    auto rt = a_s(d, "ToolType");
    auto &dp = d.at("EntityDrops").as_array();

    float sw = sz.at("W").as_double();
    float sh = sz.at("H").as_double();
    float sl = sz.at("L").as_double();

    float cr = cl.at("R").as_int64();
    float cg = cl.at("G").as_int64();
    float cb = cl.at("B").as_int64();

    entitytype entityType = CR::selectEntityType(et, true);

    AnimalCtorParams *params = new AnimalCtorParams {
        inputEvents,
        entityType,
        new std::string(des.c_str()),
        nullptr,
        CR::selectSize(sw, sh, sl),
        CR::selectColor(cr, cg, cb),
        (int)ms.as_int64(),
        (miliseconds)wi.as_int64(),
        (int)hl.as_int64(),
        CR::selectToolType(rt, true),
        CR::selectEntityDrops(dp)
    };

    animalParams[entityType] = params;
    entityToTemplateMap[entityType] = tc::ANIMAL;
}

void EntityFactory::loadStructureCtorParams(const fs::path fp) {
    auto data = JsonHandler::parseJson(fp);
    auto &d = data->as_object();

    auto et = a_s(d, "EntityType");
    auto des = a_s(d, "Description");
    auto &sz = d.at("Size").as_object();
    auto &cl = d.at("Color").as_object();
    auto &hl = d.at("Health");
    auto rt = a_s(d, "ToolType");
    auto &dp = d.at("EntityDrops").as_array();

    float sw = sz.at("W").as_double();
    float sh = sz.at("H").as_double();
    float sl = sz.at("L").as_double();

    float cr = cl.at("R").as_int64();
    float cg = cl.at("G").as_int64();
    float cb = cl.at("B").as_int64();

    entitytype entityType = CR::selectEntityType(et, true);

    StructureCtorParams *params = new StructureCtorParams {
        inputEvents,
        entityType,
        new std::string(des.c_str()),
        nullptr,
        CR::selectSize(sw, sh, sl),
        CR::selectColor(cr, cg, cb),
        (int)hl.as_int64(),
        CR::selectToolType(rt, true),
        CR::selectEntityDrops(dp),
        no_update // TODO
    };

    structureParams[entityType] = params;
    entityToTemplateMap[entityType] = tc::STRUCTURE;
}

void EntityFactory::loadGroundCtorParams(const fs::path fp) {
    auto data = JsonHandler::parseJson(fp);
    const json::object &d = data->as_object();

    auto et = a_s(d, "EntityType");
    auto des = a_s(d, "Description");
    auto &cl = d.at("Color").as_object();
    auto &hl = d.at("Health");
    auto rt = a_s(d, "ToolType");
    auto &dp = d.at("EntityDrops").as_array();

    float cr = cl.at("R").as_int64();
    float cg = cl.at("G").as_int64();
    float cb = cl.at("B").as_int64();

    entitytype entityType = CR::selectEntityType(et, true);

    GroundCtorParams *params = new GroundCtorParams {
        inputEvents,
        entityType,
        new std::string(des.c_str()),
        nullptr,
        CR::selectSize(1.0f, 1.0f, 1.0f),
        CR::selectColor(cr, cg, cb),
        (int)hl.as_int64(),
        CR::selectToolType(rt, true),
        CR::selectEntityDrops(dp),
        no_update // TODO
    };

    groundParams[entityType] = params;
    entityToTemplateMap[entityType] = tc::GROUND;
}

Entity *EntityFactory::buildEntity(entitytype entityType, Position &position) {
    Entity *newEntity = 0;
    if (entityType == 0)
        return 0;
    entityType = CR::selectEntityType(entityType);
    auto it = entityToTemplateMap.find(entityType);
    if (it != entityToTemplateMap.end()) {
        if (it->second == tc::GROUND) {
            groundParams[entityType]->position = &position;
            newEntity = new Ground(*groundParams[entityType]);
        }
        if (it->second == tc::STRUCTURE) {
            structureParams[entityType]->position = &position;
            newEntity = new Structure(*structureParams[entityType]);
        }
        if (it->second == tc::ANIMAL) {
            animalParams[entityType]->position = &position;
            newEntity = new Animal(*animalParams[entityType]);
        }
        if (it->second == tc::HUMANOID) {
            humanoidParams[entityType]->position = &position;
            newEntity = new Humanoid(*humanoidParams[entityType]);
        }
    } else {
        Logger::log(lg::ERROR_, "Could not create entity '%s'. Unknown entity type!", entityType);
    }
    return newEntity;
}

