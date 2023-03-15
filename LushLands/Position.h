#pragma once
#include <string>
#include <math.h>
#include <stdexcept>
#include "Constants.h"
#include "PositionStructures.h"
#include "DataTypes.h"


class Position {
private:
    int _x, _y, _z;
public:
    Position(int x, int y, int z, bool accurate=false);
    Position(ChunkPosition &cp);
    Position(const ChunkPosition &cp);
    Position(TilePosition &tp);
    Position(const TilePosition &tp);
    Position();
    int getX() const;
    int getY() const;
    int getZ() const;
    int getPX() const;
    int getPY() const;
    int getPZ() const;
    int x() const;
    int y() const;
    int z() const;
    void setX(int x);
    void setY(int y);
    void setZ(int z);
    void setPX(int x);
    void setPY(int y);
    void setPZ(int z);
    int getChunkX() const;
    int getChunkZ() const;
    ChunkPosition getChunkPosition() const;
    TilePosition getTilePosition() const;
    int getInsideChunkRawX() const;
    int getInsideChunkRawZ() const;
    std::string getTextX() const;
    std::string getTextY() const;
    std::string getTextZ() const;
    std::string getText() const;
    ChunkPositionsSet getNeighbouringChunkPositions() const;
    bool operator==(const Position &other) const;
    Position operator-(const Position &other) const;
    Position operator+(const Position &other) const;
    void operator=(const Position &other);
};
