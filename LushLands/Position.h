#pragma once
#include <string>

using namespace std;

struct ChunkPosition {
    int x;
    int z;
};

struct TilePosition {
    int x;
    int y;
    int z;
};

class Position {
private:
    int _x, _y, _z;
    const int representationComaValue = 100;
public:
    Position(int x, int y, int z);
    int getRawX();
    int getRawY();
    int getRawZ();
    int x();
    int y();
    int z();
    void setRawX(int x);
    void setRawY(int y);
    void setRawZ(int z);
    int getChunkX();
    int getChunkZ();
    ChunkPosition getChunkPosition();
    int getInsideChunkRawX();
    int getInsideChunkRawZ();
    string getTextX();
    string getTextY();
    string getTextZ();
    string getText();
};
