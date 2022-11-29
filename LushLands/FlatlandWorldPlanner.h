#pragma once
#include <string>
#include "BaseWorldPlanner.h"
#include "DataTypes.h"
#include "ConstantSets.h"

class FlatlandWorldPlanner : public BaseWorldPlanner {
    int seed;
    worldtype worldType = FLATLAND;
    const int seaLevel = 32;
public:
    FlatlandWorldPlanner(int seed);
    int getSeaLevel();
    FieldPlan getFieldPlan(Position position);
};
