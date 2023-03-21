#include "FlatlandWorldPlanner.h"

FlatlandWorldPlanner::FlatlandWorldPlanner(int seed) {
    this->seed = seed;
}

int FlatlandWorldPlanner::getSeaLevel() {
    return seaLevel;
}

FieldPlan FlatlandWorldPlanner::getFieldPlan(Position position) {
    FieldPlan fp = FieldPlan();
    // Over ground
    if (position.getY() > seaLevel) {
        fp.ground = AIR;
        fp.structure = 0;
        fp.animal = 0;
        return fp;
    }
    // Underground
    if (position.getY() < seaLevel) {
        fp.ground = ROCK;
        fp.structure = 0;
        fp.animal = 0;
        return fp;
    }
    // Exposed ground level
    if (position.getX() == 0 or position.getZ() == 0 or position.getX() == -1 or position.getZ() == -1) {
        fp.ground = COBBLE;
        fp.structure = 0;
        fp.animal = 0;
        return fp;
    }
    if ((position.getX() + position.getZ()) % 2 == 0) {
        if (position.getX() % 4 == 0 and position.getZ() % 4 == 0) {
            fp.ground = GRASS;
            fp.structure = TREE;
            fp.animal = 0;
            return fp;
        }
        if (position.getX() % 6 == 2 and position.getZ() % 6 == 2) {
            fp.ground = GRASS;
            fp.structure = 0;
            fp.animal = CHICKEN;
            return fp;
        }
        if (position.getX() % 6 == 4 and position.getZ() % 6 == 4) {
            fp.ground = GRASS;
            fp.structure = TALL_GRASS;
            fp.animal = 0;
            return fp;
        } else {
            fp.ground = GRASS;
            fp.structure = 0;
            fp.animal = 0;
            return fp;
        }
    } else {
        fp.ground = SOIL;
        fp.structure = 0;
        fp.animal = 0;
        return fp;
    }
}
