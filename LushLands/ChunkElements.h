#pragma once
#include <unordered_map>
#include <unordered_set>
#include "PositionStructures.h"
#include "Entity.h"
#include "Item.h"
#include "JsonHandler.h"
#include "Serializable.h"


class ChunkElements : Serializable {

public:
    std::unordered_map<TilePosition, Entity *> groundTiles;
    std::unordered_map<TilePosition, Entity *> structures;
    std::unordered_set<Entity *> animals;
    std::unordered_set<Entity *> humanoids;
    std::unordered_set<Item *> items;
public:
    json serialize() override;
    void deserialize(json data) override;
};
