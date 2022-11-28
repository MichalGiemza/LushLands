#pragma once
#include <string>
#include "Constants.h"
#include "PositionStructures.h"


class Position {
private:
    int _x, _y, _z;
public:
    Position(int x, int y, int z);
    Position(ChunkPosition cp);
    Position();
    int getX() const;
    int getY() const;
    int getZ() const;
    int getAccurateX() const;
    int getAccurateY() const;
    int getAccurateZ() const;
    int x() const;
    int y() const;
    int z() const;
    void setX(int x);
    void setY(int y);
    void setZ(int z);
    int getChunkX();
    int getChunkZ();
    ChunkPosition getChunkPosition();
    TilePosition getTilePosition();
    int getInsideChunkRawX();
    int getInsideChunkRawZ();
    std::string getTextX();
    std::string getTextY();
    std::string getTextZ();
    std::string getText();
    NeighbouringChunkPositions getNeighbouringChunkPositions();
    bool operator==(const Position &other) const;
};
