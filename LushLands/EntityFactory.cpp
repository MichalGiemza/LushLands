#include "EntityFactory.h"


EntityFactory::EntityFactory(InputEvents *inputEvents) : inputEvents(inputEvents) {
    nameGenerator = new NameGenerator(common_male_names_path, common_female_names_path, common_neutral_names_path);
}

Entity *EntityFactory::buildEntity(entitytype entityType, Position &position) {
    /*    Empty    */
    if (entityType == e::AIR or entityType == 0)
        return 0;
    /*    Ground    */
    if (entityType == e::SOIL)
        return new Ground(inputEvents, e::SOIL, e::SOIL_DESCRIPTION, position, e::GROUND_SIZE, e::SOIL_COLOR, e::SOIL_HEALTH, e::SOIL_TOOL, e::SOIL_DROPS);
    if (entityType == e::GRASS)
        return new Ground(inputEvents, e::GRASS, e::GRASS_DESCRIPTION, position, e::GROUND_SIZE, e::GRASS_COLOR, e::GRASS_HEALTH, e::GRASS_TOOL, e::GRASS_DROPS);
    if (entityType == e::WATER)
        return new Ground(inputEvents, e::WATER, e::WATER_DESCRIPTION, position, e::GROUND_SIZE, e::WATER_COLOR, e::WATER_HEALTH, e::WATER_TOOL, e::WATER_DROPS);
    if (entityType == e::SAND)
        return new Ground(inputEvents, e::SAND, e::SAND_DESCRIPTION, position, e::GROUND_SIZE, e::SAND_COLOR, e::SAND_HEALTH, e::SAND_TOOL, e::SAND_DROPS);
    if (entityType == e::ROCK)
        return new Ground(inputEvents, e::ROCK, e::ROCK_DESCRIPTION, position, e::GROUND_SIZE, e::ROCK_COLOR, e::ROCK_HEALTH, e::ROCK_TOOL, e::ROCK_DROPS);
    if (entityType == e::COBBLE)
        return new Ground(inputEvents, e::COBBLE, e::COBBLE_DESCRIPTION, position, e::GROUND_SIZE, e::COBBLE_COLOR, e::COBBLE_HEALTH, e::COBBLE_TOOL, e::COBBLE_DROPS);
    if (entityType == e::FARMLAND)
        return new Ground(inputEvents, e::FARMLAND, e::FARMLAND_DESCRIPTION, position, e::GROUND_SIZE, e::FARMLAND_COLOR, e::FARMLAND_HEALTH, e::FARMLAND_TOOL, e::FARMLAND_DROPS);
    if (entityType == e::GRAVEL)
        return new Ground(inputEvents, e::GRAVEL, e::GRAVEL_DESCRIPTION, position, e::GROUND_SIZE, e::GRAVEL_COLOR, e::GRAVEL_HEALTH, e::GRAVEL_TOOL, e::GRAVEL_DROPS);
    if (entityType == e::SNOW)
        return new Ground(inputEvents, e::SNOW, e::SNOW_DESCRIPTION, position, e::GROUND_SIZE, e::SNOW_COLOR, e::SNOW_HEALTH, e::SNOW_TOOL, e::SNOW_DROPS);
    /*    Structure    */
    if (entityType == e::TREE)
        return new Structure(inputEvents, e::TREE, e::TREE_DESCRIPTION, position, e::TREE_SIZE, e::TREE_COLOR, e::TREE_HEALTH, e::TREE_TOOL, e::TREE_DROPS);
    if (entityType == e::BUSH)
        return new Structure(inputEvents, e::BUSH, e::BUSH_DESCRIPTION, position, e::BUSH_SIZE, e::BUSH_COLOR, e::BUSH_HEALTH, e::BUSH_TOOL, e::BUSH_DROPS);
    if (entityType == e::FLOWER_YELLOW)
        return new Structure(inputEvents, e::FLOWER_YELLOW, e::FLOWER_YELLOW_DESCRIPTION, position, e::FLOWER_YELLOW_SIZE, e::FLOWER_YELLOW_COLOR, e::FLOWER_YELLOW_HEALTH, e::FLOWER_YELLOW_TOOL, e::FLOWER_YELLOW_DROPS);
    if (entityType == e::TALL_GRASS)
        return new Structure(inputEvents, e::TALL_GRASS, e::TALL_GRASS_DESCRIPTION, position, e::TALL_GRASS_SIZE, e::TALL_GRASS_COLOR, e::TALL_GRASS_HEALTH, e::TALL_GRASS_TOOL, e::TALL_GRASS_DROPS);
    if (entityType == e::STONE)
        return new Structure(inputEvents, e::STONE, e::STONE_DESCRIPTION, position, e::STONE_SIZE, e::STONE_COLOR, e::STONE_HEALTH, e::STONE_TOOL, e::STONE_DROPS);
    if (entityType == e::LOG)
        return new Structure(inputEvents, e::LOG, e::LOG_DESCRIPTION, position, e::LOG_SIZE, e::LOG_COLOR, e::TALL_GRASS_HEALTH, e::TALL_GRASS_TOOL, e::TALL_GRASS_DROPS);
    /*    Animal    */
    if (entityType == e::CHICKEN)
        return new Animal(inputEvents, e::CHICKEN, e::CHICKEN_DESCRIPTION, position, e::CHICKEN_SIZE, e::CHICKEN_COLOR, e::CHICKEN_MOVEMENT_SPEED, e::CHICKEN_WALK_INTERVAL, e::CHICKEN_HEALTH, e::CHICKEN_TOOL, e::CHICKEN_DROPS);
    /*    Humanoids    */
    if (entityType == e::HUMAN) {
        gendertype gender = rand() % 2 ? gdr::male : gdr::female;
        name firstName = nameGenerator->getCommonName(gender);
        name lastName = nameGenerator->getCommonName(gender);
        return new Humanoid(inputEvents, e::HUMAN, e::HUMAN_DESCRIPTION, position, e::HUMAN_SIZE, e::HUMAN_COLOR, e::HUMAN_MOVEMENT_SPEED, firstName, lastName, gender, e::HUMAN_INVENTORY_SLOTS, e::HUMAN_HEALTH, e::HUMAN_TOOL, e::HUMAN_DROPS);
    }
}
