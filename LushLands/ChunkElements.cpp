#include "ChunkElements.h"

json ChunkElements::serialize() {
    json sd;
    //std::transform(entityMap.begin(), entityMap.end(), std::back_inserter(pairs),
    //    [](const auto &pair) { return std::make_pair(pair.first, pair.second); });

    //sd[GROUND_N] = json::parse(groundTiles.begin(), groundTiles.end());
    //sd[STRUCTURES_N] = json::parse(structures.begin(), structures.end());
    //sd[ANIMALS_N] = json::parse(animals.begin(), animals.end());
    ////sd[HUMANOIDS_N] = json::parse(humanoids.begin(), humanoids.end()); TODO
    //sd[ITEMS_N] = json::parse(items.begin(), items.end());
    return sd;
}

void ChunkElements::deserialize(json data) {
    //groundTiles = std::unordered_map<TilePosition, Entity *>(data[GROUND_N]);
    //structures = std::unordered_map <TilePosition, Entity *>(data[STRUCTURES_N]);
    //animals = std::unordered_set<Entity *>(data[ANIMALS_N]);
    //humanoids = std::unordered_set<Entity *>(data[HUMANOIDS_N]);
    //items = std::unordered_set<Item *>(data[ITEMS_N]);
}
