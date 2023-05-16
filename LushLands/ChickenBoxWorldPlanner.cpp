#include "ChickenBoxWorldPlanner.h"

ChickenBoxWorldPlanner::ChickenBoxWorldPlanner(int seed) {
    this->seed = seed;
}

int ChickenBoxWorldPlanner::getSeaLevel() {
    return seaLevel;
}

FieldPlan ChickenBoxWorldPlanner::getFieldPlan(Position position) {
    FieldPlan fp = FieldPlan();
    // Over ground
    if (position.getY() > seaLevel) {
        fp.ground = e::AIR;
        fp.structure = 0;
        fp.animal = 0;
        return fp;
    }
    // Under ground
    if (position.getY() < seaLevel) {
        fp.ground = e::AIR;
        fp.structure = 0;
        fp.animal = 0;
        return fp;
    }
    // Exposed ground level
    if (position.getX() < 0 or position.getZ() < 0 or position.getX() > 6 or position.getZ() > 6) {
        fp.ground = e::GRASS;
        fp.structure = 0;
        fp.animal = 0;
        return fp;
    }
    if (position.getX() == 0 or position.getZ() == 0) {
        fp.ground = e::SOIL;
        fp.structure = e::BUSH;
        fp.animal = 0;
        return fp;
    }
    if (position.getX() == 6 or position.getZ() == 6) {
        fp.ground = e::SOIL;
        fp.structure = e::BUSH;
        fp.animal = 0;
        return fp;
    }
    if (position.getX() == 3 and position.getZ() == 3) {
        fp.ground = e::SNOW;
        fp.structure = 0;
        fp.animal = e::CHICKEN;
        return fp;
    }
    fp.ground = e::GRASS;
    fp.structure = 0;
    fp.animal = 0;
    return fp;
}