#include "FlatlandWorldPlanner.h"

FlatlandWorldPlanner::FlatlandWorldPlanner(int seed) {
    this->seed = seed;
}

int FlatlandWorldPlanner::getSeaLevel() {
    return seaLevel;
}

entitytype FlatlandWorldPlanner::getGround(TilePosition &p) {
    // Over ground
    if (p.y > seaLevel)
        return 0;
    // Underground
    if (p.y < seaLevel)
        return "rock";
    // Exposed ground level
    if (p.x == 0 or p.z == 0 or p.x == -1 or p.z == -1)
        return "cobble";
    if ((p.x + p.z) % 2 == 0) {
        return "grass";
    } else {
        return "soil";
    }
}

entitytype FlatlandWorldPlanner::getStructure(TilePosition &p) {
    if (p.x == 0 or p.z == 0 or p.x == -1 or p.z == -1)
        return 0;
    if (p.y == seaLevel and p.x % 4 == 0 and p.z % 4 == 0) {
        return "tree";
    }
    return 0;
}

entitytypeset FlatlandWorldPlanner::getAnimals(ChunkPosition &p) {
    entitytypeset *s = new entitytypeset();
    // I know, I know... but it's debug only.
    for (int i = p.x * chunkSizeByTiles; i < (p.x + 1) * chunkSizeByTiles; i++) {
        for (int j = p.z * chunkSizeByTiles; j < (p.z + 1) * chunkSizeByTiles; j++) {
            if (i % 6 == 2 and j % 6 == 2) {
                s->push_back({ "chicken", Position(i, seaLevel, j) });
            }
        }
    }
    return *s;
}

