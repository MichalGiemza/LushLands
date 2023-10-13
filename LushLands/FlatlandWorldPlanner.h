#pragma once
#include "stdafx.h"
#include "BaseWorldPlanner.h"


class FlatlandWorldPlanner : public BaseWorldPlanner {
    int seed;
    worldtype worldType = FLATLAND;
    const int seaLevel = 32;
public:
    FlatlandWorldPlanner(int seed);
    int getSeaLevel();
    FieldPlan getFieldPlan(Position position);
};
