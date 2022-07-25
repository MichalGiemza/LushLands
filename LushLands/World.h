#pragma once
#include <vector>
#include "Position.h"
#include "ChunkSystem.h"

using namespace std;

class World {
    int seed;
    WorldPlanner worldPlanner;
    ChunkSystem chunkSystem;
    PlayerManager playerManager;
    ControlManager controlManager;
public:
    int getSeed();
    vector<Entity> getByPosition(Position position);
    void addPlayer(Entity player, Position position);

};
