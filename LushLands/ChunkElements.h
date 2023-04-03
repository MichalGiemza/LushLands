#pragma once
#include <unordered_map>
#include "PositionStructures.h"
#include "Entity.h"
#include "Item.h"


struct ChunkElements {
    std::unordered_map<TilePosition, Entity *> groundTiles;
    std::unordered_map<TilePosition, Entity *> structures;
    std::unordered_set<Entity *> animals;
    std::unordered_set<Entity *> humanoids;
    std::unordered_set<Item *> items;
};
