#include "FlatlandWorldPlanner.h"

FlatlandWorldPlanner::FlatlandWorldPlanner(int seed) {
    this->seed = seed;
}

int FlatlandWorldPlanner::getSeaLevel() {
    return seaLevel;
}

FieldPlan FlatlandWorldPlanner::getFieldPlan(Position position) {
    FieldPlan fp;
    // Over ground
    if (position.y() > seaLevel) {
        fp.ground = "";
        fp.structure = "";
        fp.animal = "";
        return fp;
    }
    // Underground
    if (position.y() < seaLevel) {
        fp.ground = "stone";
        fp.structure = "";
        fp.animal = "";
        return fp;
    }
    // Exposed ground level
    if ((position.x() + position.z()) % 2 == 0) {
        if (position.x() % 4 == 0 and position.z() % 4 == 0) {
            fp.ground = "grass";
            fp.structure = "tree";
            fp.animal = "";
            return fp;
        }
        if (position.x() % 6 == 2 and position.z() % 6 == 2) {
            fp.ground = "grass";
            fp.structure = "";
            fp.animal = "rabbit";
            return fp;
        }
        if (position.x() % 6 == 4 and position.z() % 6 == 4) {
            fp.ground = "grass";
            fp.structure = "brick_wall";
            fp.animal = "";
            return fp;
        } else {
            fp.ground = "grass";
            fp.structure = "";
            fp.animal = "";
            return fp;
        }
    } else {
        fp.ground = "sand";
        fp.structure = "";
        fp.animal = "";
        return fp;
    }
}
