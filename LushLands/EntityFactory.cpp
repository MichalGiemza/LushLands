#include "EntityFactory.h"


EntityFactory::EntityFactory(InputEvents *inputEvents) : inputEvents(inputEvents) {
    nameGenerator = new NameGenerator(common_male_names_path, common_female_names_path, common_neutral_names_path);
}

Entity *EntityFactory::buildEntity(entitytype entityType, Position &position) {
    /*    Empty    */
    if (entityType == AIR or entityType == 0)
        return 0;
    /*    Ground    */
    if (entityType == SOIL)
        return new Ground(inputEvents, SOIL, SOIL_DESCRIPTION, position, GROUND_SIZE, SOIL_COLOR, SOIL_HEALTH, SOIL_TOOL, SOIL_DROPS);
    if (entityType == GRASS)
        return new Ground(inputEvents, GRASS, GRASS_DESCRIPTION, position, GROUND_SIZE, GRASS_COLOR, GRASS_HEALTH, GRASS_TOOL, GRASS_DROPS);
    if (entityType == WATER)
        return new Ground(inputEvents, WATER, WATER_DESCRIPTION, position, GROUND_SIZE, WATER_COLOR, WATER_HEALTH, WATER_TOOL, WATER_DROPS);
    if (entityType == SAND)
        return new Ground(inputEvents, SAND, SAND_DESCRIPTION, position, GROUND_SIZE, SAND_COLOR, SAND_HEALTH, SAND_TOOL, SAND_DROPS);
    if (entityType == ROCK)
        return new Ground(inputEvents, ROCK, ROCK_DESCRIPTION, position, GROUND_SIZE, ROCK_COLOR, ROCK_HEALTH, ROCK_TOOL, ROCK_DROPS);
    if (entityType == COBBLE)
        return new Ground(inputEvents, COBBLE, COBBLE_DESCRIPTION, position, GROUND_SIZE, COBBLE_COLOR, COBBLE_HEALTH, COBBLE_TOOL, COBBLE_DROPS);
    if (entityType == FARMLAND)
        return new Ground(inputEvents, FARMLAND, FARMLAND_DESCRIPTION, position, GROUND_SIZE, FARMLAND_COLOR, FARMLAND_HEALTH, FARMLAND_TOOL, FARMLAND_DROPS);
    if (entityType == GRAVEL)
        return new Ground(inputEvents, GRAVEL, GRAVEL_DESCRIPTION, position, GROUND_SIZE, GRAVEL_COLOR, GRAVEL_HEALTH, GRAVEL_TOOL, GRAVEL_DROPS);
    if (entityType == SNOW)
        return new Ground(inputEvents, SNOW, SNOW_DESCRIPTION, position, GROUND_SIZE, SNOW_COLOR, SNOW_HEALTH, SNOW_TOOL, SNOW_DROPS);
    /*    Structure    */
    if (entityType == TREE)
        return new Structure(inputEvents, TREE, TREE_DESCRIPTION, position, TREE_SIZE, TREE_COLOR, TREE_HEALTH, TREE_TOOL, TREE_DROPS);
    if (entityType == BUSH)
        return new Structure(inputEvents, BUSH, BUSH_DESCRIPTION, position, BUSH_SIZE, BUSH_COLOR, BUSH_HEALTH, BUSH_TOOL, BUSH_DROPS);
    if (entityType == FLOWER_YELLOW)
        return new Structure(inputEvents, FLOWER_YELLOW, FLOWER_YELLOW_DESCRIPTION, position, FLOWER_YELLOW_SIZE, FLOWER_YELLOW_COLOR, FLOWER_YELLOW_HEALTH, FLOWER_YELLOW_TOOL, FLOWER_YELLOW_DROPS);
    if (entityType == TALL_GRASS)
        return new Structure(inputEvents, TALL_GRASS, TALL_GRASS_DESCRIPTION, position, TALL_GRASS_SIZE, TALL_GRASS_COLOR, TALL_GRASS_HEALTH, TALL_GRASS_TOOL, TALL_GRASS_DROPS);
    if (entityType == STONE)
        return new Structure(inputEvents, STONE, STONE_DESCRIPTION, position, STONE_SIZE, STONE_COLOR, STONE_HEALTH, STONE_TOOL, STONE_DROPS);
    if (entityType == LOG)
        return new Structure(inputEvents, LOG, LOG_DESCRIPTION, position, LOG_SIZE, LOG_COLOR, TALL_GRASS_HEALTH, TALL_GRASS_TOOL, TALL_GRASS_DROPS);
    /*    Animal    */
    if (entityType == CHICKEN)
        return new Animal(inputEvents, CHICKEN, CHICKEN_DESCRIPTION, position, CHICKEN_SIZE, CHICKEN_COLOR, CHICKEN_MOVEMENT_SPEED, CHICKEN_WALK_INTERVAL, CHICKEN_HEALTH, CHICKEN_TOOL, CHICKEN_DROPS);
    /*    Humanoids    */
    if (entityType == HUMAN) {
        gendertype gender = rand() % 2 ? gdr::male : gdr::female;
        name firstName = nameGenerator->getCommonName(gender);
        name lastName = nameGenerator->getCommonName(gender);
        return new Humanoid(inputEvents, HUMAN, HUMAN_DESCRIPTION, position, HUMAN_SIZE, HUMAN_COLOR, HUMAN_MOVEMENT_SPEED, firstName, lastName, gender, HUMAN_INVENTORY_SLOTS, HUMAN_HEALTH, HUMAN_TOOL, HUMAN_DROPS);
    }
}
