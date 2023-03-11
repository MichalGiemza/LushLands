#pragma once
#include <vector>
#include <unordered_map>
#include "Position.h"
#include "Chunk.h"
#include "BaseWorldPlanner.h"


class ChunkLoadManager {
    /**
    * One ChunkLoadManager per world.
    * 
    */
    std::vector<Position> followedLoadingPositions;
    std::unordered_map<ChunkPosition, Chunk *> *chunks;
    BaseWorldPlanner *worldPlanner;
    EntityFactory *entityFactory;
private:
    void generateChunksByPosition(Position &pos);
public:
    ChunkLoadManager(std::unordered_map<ChunkPosition, Chunk *> *chunks, BaseWorldPlanner *worldPlanner, EntityFactory *entityFactory);
    void loadByPosition(Position &position);
    void updateLoadedChunkList();
    Chunk *generateChunk(ChunkPosition &chunkPosition);
    Chunk *getChunk(ChunkPosition chunkPosition);
    int getChunksLoadedCount();
    int getEntitiesCreatedCount();
    ChunkPositionsSet *getLoadedChunkList();
};

