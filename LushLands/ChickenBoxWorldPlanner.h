#pragma once
#include "stdafx.h"
#include "BaseWorldPlanner.h"


class ChickenBoxWorldPlanner : public BaseWorldPlanner {
    int seed;
    worldtype worldType = CHICKEN_BOX;
    const int seaLevel = 32;
public:
    ChickenBoxWorldPlanner(int seed);
    int getSeaLevel();
    FieldPlan getFieldPlan(Position position);
};

