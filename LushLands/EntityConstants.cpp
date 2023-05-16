#include "EntityConstants.h"

namespace entities {

    const EntityDrops SOIL_DROPS = {
        1,
        new ItemDropChance[] { { i::SOIL, 1, 1, 1}}
    };

    const EntityDrops GRASS_DROPS = {
        1,
        new ItemDropChance[] { { i::SOIL, 1, 1, 1 } }
    };

    const EntityDrops WATER_DROPS = {
        0,
        0
    };

    const EntityDrops SAND_DROPS = {
        1,
        new ItemDropChance[] { { i::SAND, 1, 1, 1 } }
    };

    const EntityDrops ROCK_DROPS = {
        1,
        new ItemDropChance[] { { i::STONE, 2, 2, 3 } }
    };

    const EntityDrops COBBLE_DROPS = {
        1,
        new ItemDropChance[] { { i::STONE, 2, 2, 3 } }
    };

    const EntityDrops FARMLAND_DROPS = {
        1,
        new ItemDropChance[] { { i::SOIL, 1, 1, 1 } }
    };

    const EntityDrops GRAVEL_DROPS = {
        1,
        new ItemDropChance[] { { i::GRAVEL, 1, 1, 1 } }
    };

    const EntityDrops SNOW_DROPS = {
        1,
        new ItemDropChance[] { { i::SNOW, 1, 1, 1 } }
    };

    const EntityDrops TREE_DROPS = {
        2,
        new ItemDropChance[] { { i::WOOD, 3, 3, 5 }, { i::BRANCH, 2, 2, 3 } }
    };

    const EntityDrops BUSH_DROPS = {
        1,
        new ItemDropChance[] { { i::BRANCH, 2, 2, 3 } }
    };

    const EntityDrops TALL_GRASS_DROPS = {
        0,
        0
    };

    const EntityDrops FLOWER_YELLOW_DROPS = {
        0,
        0
    };

    const EntityDrops STONE_DROPS = {
        1,
        new ItemDropChance[] { { i::STONE, 1, 1, 1 } }
    };

    const EntityDrops LOG_DROPS = {
        1,
        new ItemDropChance[] { { i::WOOD, 2, 2, 3 } }
    };

    const EntityDrops CHICKEN_DROPS = {
        2,
        new ItemDropChance[] { { i::MEAT, 1, 1, 1 }, { i::FEATHER, 3, 3, 5 } }
    };

    const EntityDrops HUMAN_DROPS = {
        0,
        0
    };

}
