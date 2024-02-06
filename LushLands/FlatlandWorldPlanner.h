#pragma once
#include "BaseWorldPlanner.h"
#include <ConstantSets.h>


class FlatlandWorldPlanner : public BaseWorldPlanner {
    int seed;
    worldtype worldType = FLATLAND;
    const int seaLevel = 32;
public:
    FlatlandWorldPlanner(int seed);
    int getSeaLevel();
    virtual entitytype getGround(TilePosition &p) override;
    virtual entitytype getStructure(TilePosition &p) override;
    virtual entitytypeset getAnimals(ChunkPosition &p) override;
};
