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
        fp.ground = 0;
        return fp;
    }
    // Underground
    if (position.getY() < seaLevel) {
        fp.ground = "rock";
        return fp;
    }
    // Exposed ground level
    if (position.getX() == 0 or position.getZ() == 0 or position.getX() == -1 or position.getZ() == -1) {
        fp.ground = "cobble";
        return fp;
    }
    if ((position.getX() + position.getZ()) % 2 == 0) {
        if (position.getX() % 4 == 0 and position.getZ() % 4 == 0) {
            fp.ground = "grass";
            fp.structure = "tree";
            return fp;
        }
        if (position.getX() % 6 == 2 and position.getZ() % 6 == 2) {
            fp.ground = "grass";
            fp.animal = "chicken";
            return fp;
        }
        if (position.getX() % 6 == 4 and position.getZ() % 6 == 4) {
            fp.ground = "grass";
            fp.itemAmount = 100;
            return fp;
        } else {
            fp.ground = "grass";
            return fp;
        }
    } else {
        fp.ground = "soil";
        return fp;
    }
}
