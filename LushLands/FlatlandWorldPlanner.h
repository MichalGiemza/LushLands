#pragma once
#include <string>
#include "BaseWorldPlanner.h"

using namespace std;

class FlatlandWorldPlanner : public BaseWorldPlanner {
    int seed;
    string worldType = "flatland";
    const int seaLevel = 32;
public:
    FlatlandWorldPlanner(int seed);
    int getSeaLevel();

    FieldPlan getFieldPlan(Position position);
};
