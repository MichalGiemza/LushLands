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
    if (position.y() > seaLevel) {
        fp.ground = AIR;
        fp.structure = 0;
        fp.animal = 0;
        return fp;
    }
    // Underground
    if (position.y() < seaLevel) {
        fp.ground = ROCK;
        fp.structure = 0;
        fp.animal = 0;
        return fp;
    }
    // Exposed ground level
    if (position.x() == 0 or position.z() == 0) {
        fp.ground = FARMLAND;
        fp.structure = FLOWER_YELLOW;
        fp.animal = 0;
        return fp;
    }
    if ((position.x() + position.z()) % 2 == 0) {
        if (position.x() % 4 == 0 and position.z() % 4 == 0) {
            fp.ground = GRASS;
            fp.structure = TREE;
            fp.animal = 0;
            return fp;
        }
        if (position.x() % 6 == 2 and position.z() % 6 == 2) {
            fp.ground = GRASS;
            fp.structure = 0;
            fp.animal = CHICKEN;
            return fp;
        }
        if (position.x() % 6 == 4 and position.z() % 6 == 4) {
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
