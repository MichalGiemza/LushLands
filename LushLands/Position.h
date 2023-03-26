#pragma once
#include <string>
#include <math.h>
#include <stdexcept>
#include "Constants.h"
#include "PositionStructures.h"
#include "DataTypes.h"


class Position {
private:
    ll _x, _y, _z;
    static ll objectCount;
public:
    Position(ll x, ll y, ll z, bool accurate=false);
    Position(ChunkPosition &cp);
    Position(const ChunkPosition &cp);
    Position(TilePosition &tp);
    Position(const TilePosition &tp);
    Position(const Position &cp);
    Position();
    ~Position();
    ll getX() const;
    ll getY() const;
    ll getZ() const;
    ll getPX() const;
    ll getPY() const;
    ll getPZ() const;
    void setX(ll x);
    void setY(ll y);
    void setZ(ll z);
    void setPX(ll x);
    void setPY(ll y);
    void setPZ(ll z);
    ll getChunkX() const;
    ll getChunkZ() const;
    ChunkPosition getChunkPosition() const;
    TilePosition getTilePosition() const;
    void updateTilePosition(TilePosition &tp) const;
    ll getInsideChunkRawX() const;
    ll getInsideChunkRawZ() const;
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
