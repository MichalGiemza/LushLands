#include "EntityFactory.h"


EntityFactory::EntityFactory() {
    nameGenerator = new NameGenerator(common_male_names_path, common_female_names_path, common_neutral_names_path);
}

Entity *EntityFactory::buildEntity(entitytype entityType, Position &position) {
    /*    Empty    */
    if (entityType == AIR or entityType == 0)
        return 0;
    /*    Ground    */
    if (entityType == SOIL)
        return new Ground(SOIL, SOIL_DESCRIPTION, position, GROUND_SIZE, SOIL_COLOR);
    if (entityType == GRASS)
        return new Ground(GRASS, GRASS_DESCRIPTION, position, GROUND_SIZE, GRASS_COLOR);
    if (entityType == WATER)
        return new Ground(WATER, WATER_DESCRIPTION, position, GROUND_SIZE, WATER_COLOR);
    if (entityType == SAND)
        return new Ground(SAND, SAND_DESCRIPTION, position, GROUND_SIZE, SAND_COLOR);
    if (entityType == ROCK)
        return new Ground(ROCK, ROCK_DESCRIPTION, position, GROUND_SIZE, ROCK_COLOR);
    if (entityType == COBBLE)
        return new Ground(COBBLE, COBBLE_DESCRIPTION, position, GROUND_SIZE, COBBLE_COLOR);
    if (entityType == FARMLAND)
        return new Ground(FARMLAND, FARMLAND_DESCRIPTION, position, GROUND_SIZE, FARMLAND_COLOR);
    if (entityType == GRAVEL)
        return new Ground(GRAVEL, GRAVEL_DESCRIPTION, position, GROUND_SIZE, GRAVEL_COLOR);
    if (entityType == SNOW)
        return new Ground(SNOW, SNOW_DESCRIPTION, position, GROUND_SIZE, SNOW_COLOR);
    /*    Structure    */
    if (entityType == TREE)
        return new Structure(TREE, TREE_DESCRIPTION, position, TREE_SIZE, TREE_COLOR);
    if (entityType == BUSH)
        return new Structure(BUSH, BUSH_DESCRIPTION, position, BUSH_SIZE, BUSH_COLOR);
    if (entityType == FLOWER_YELLOW)
        return new Structure(FLOWER_YELLOW, FLOWER_YELLOW_DESCRIPTION, position, FLOWER_YELLOW_SIZE, FLOWER_YELLOW_COLOR);
    if (entityType == TALL_GRASS)
        return new Structure(TALL_GRASS, TALL_GRASS_DESCRIPTION, position, TALL_GRASS_SIZE, TALL_GRASS_COLOR);
    if (entityType == STONE)
        return new Structure(STONE, STONE_DESCRIPTION, position, STONE_SIZE, STONE_COLOR);
    if (entityType == LOG)
        return new Structure(LOG, LOG_DESCRIPTION, position, LOG_SIZE, LOG_COLOR);
    /*    Animal    */
    if (entityType == CHICKEN)
        return new Animal(CHICKEN, CHICKEN_DESCRIPTION, position, CHICKEN_SIZE, CHICKEN_COLOR, CHICKEN_MOVEMENT_SPEED, CHICKEN_WALK_INTERVAL);
    /*    Humanoids    */
    if (entityType == HUMAN) {
        gendertype gender = rand() % 2 ? gdr::male : gdr::female;
        name firstName = nameGenerator->getCommonName(gender);
        name lastName = nameGenerator->getCommonName(gender);
        return new Humanoid(HUMAN, HUMAN_DESCRIPTION, position, HUMAN_SIZE, HUMAN_COLOR, HUMAN_MOVEMENT_SPEED, firstName, lastName, gender);
    }
}
