#include "EntityFactory.h"


void EntityFactory::setupPrefabs() {  // TODO: Czy wszystkie te pola s¹ w kó³ko kopiowane przy kolejnych konstruktorach?
    prefabs[SOIL] = new Ground(SOIL, SOIL_DESCRIPTION, Position(), Size(1, 1, 1), &SOIL_COLOR);
    prefabs[GRASS] = new Ground(GRASS, GRASS_DESCRIPTION, Position(), Size(1, 1, 1), &GRASS_COLOR);
    prefabs[WATER] = new Ground(WATER, WATER_DESCRIPTION, Position(), Size(1, 1, 1), &WATER_COLOR);
    prefabs[SAND] = new Ground(SAND, SAND_DESCRIPTION, Position(), Size(1, 1, 1), &SAND_COLOR);
    prefabs[ROCK] = new Ground(ROCK, ROCK_DESCRIPTION, Position(), Size(1, 1, 1), &ROCK_COLOR);
    prefabs[COBBLE] = new Ground(COBBLE, COBBLE_DESCRIPTION, Position(), Size(1, 1, 1), &COBBLE_COLOR);
    prefabs[FARMLAND] = new Ground(FARMLAND, FARMLAND_DESCRIPTION, Position(), Size(1, 1, 1), &FARMLAND_COLOR);
    prefabs[GRAVEL] = new Ground(GRAVEL, GRAVEL_DESCRIPTION, Position(), Size(1, 1, 1), &GRAVEL_COLOR);
    prefabs[SNOW] = new Ground(SNOW, SNOW_DESCRIPTION, Position(), Size(1, 1, 1), &SNOW_COLOR);

    prefabs[TREE] = new Structure(TREE, TREE_DESCRIPTION, Position(), Size(1, 2, 1), &TREE_COLOR);
    prefabs[BUSH] = new Structure(BUSH, BUSH_DESCRIPTION, Position(), Size(.8f, 0.8f, 0.8f), &BUSH_COLOR);
    prefabs[FLOWER_YELLOW] = new Structure(FLOWER_YELLOW, FLOWER_YELLOW_DESCRIPTION, Position(), Size(.4f, .4f, .4f), &FLOWER_YELLOW_COLOR);
    prefabs[TALL_GRASS] = new Structure(TALL_GRASS, TALL_GRASS_DESCRIPTION, Position(), Size(1, .6, 1), &TALL_GRASS_COLOR);
    prefabs[STONE] = new Structure(STONE, STONE_DESCRIPTION, Position(), Size(.5f, .5f, .5f), &STONE_COLOR);
    prefabs[LOG] = new Structure(LOG, LOG_DESCRIPTION, Position(), Size(1, .6, .6), &LOG_COLOR);

    prefabs[CHICKEN] = new Animal(CHICKEN, CHICKEN_DESCRIPTION, Position(), Size(.5f, .5f, .5f), &CHICKEN_COLOR, (int)CHICKEN_MOVEMENT_SPEED, (miliseconds)CHICKEN_WALK_INTERVAL);
}

EntityFactory::EntityFactory() {
    prefabs = std::unordered_map<entitytype, Entity *>();
    setupPrefabs();
}

Entity *EntityFactory::buildEntity(entitytype entityType) {
    if (entityType == AIR or entityType == 0)
        return 0;
    return prefabs[entityType]->clone();
}
