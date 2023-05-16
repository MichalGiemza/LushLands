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
        fp.ground = e::AIR;
        return fp;
    }
    // Underground
    if (position.getY() < seaLevel) {
        fp.ground = e::ROCK;
        return fp;
    }
    // Exposed ground level
    if (position.getX() == 0 or position.getZ() == 0 or position.getX() == -1 or position.getZ() == -1) {
        fp.ground = e::COBBLE;
        return fp;
    }
    if ((position.getX() + position.getZ()) % 2 == 0) {
        if (position.getX() % 4 == 0 and position.getZ() % 4 == 0) {
            fp.ground = e::GRASS;
            fp.structure = e::TREE;
            return fp;
        }
        if (position.getX() % 6 == 2 and position.getZ() % 6 == 2) {
            fp.ground = e::GRASS;
            fp.animal = e::CHICKEN;
            return fp;
        }
        if (position.getX() % 6 == 4 and position.getZ() % 6 == 4) {
            fp.ground = e::GRASS;
            fp.item = i::WOOD;
            fp.itemAmount = 100;
            return fp;
        } else {
            fp.ground = e::GRASS;
            return fp;
        }
    } else {
        fp.ground = e::SOIL;
        return fp;
    }
}
