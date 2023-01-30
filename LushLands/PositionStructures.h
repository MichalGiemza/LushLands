#pragma once

struct ChunkPosition {
    int x;
    int z;
    bool operator==(const ChunkPosition &other) const {
        return x == other.x && z == other.z;
    }
};

struct TilePosition {
    int x;
    int y;
    int z;
    bool operator==(const TilePosition &other) const {
        return x == other.x && y == other.y && z == other.z;
    }
};

struct ChunkPositionsSet {
    ChunkPosition *chunkPositions;
    int n;
};

template<> struct std::hash<ChunkPosition> {
    std::size_t operator()(const ChunkPosition &p) const {
        return
            hash<int>()(p.x) ^
            hash<int>()(p.z);
    }
};

template<> struct std::hash<TilePosition> {
    std::size_t operator()(const TilePosition &p) const {
        return
            hash<int>()(p.x) ^
            hash<int>()(p.y) ^
            hash<int>()(p.z);
    }
};
