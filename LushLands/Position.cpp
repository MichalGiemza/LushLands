#include <math.h>
#include <string>
#include "Position.h"
#include "Constants.h"
#include <stdexcept>


Position::Position(int x, int y, int z) {
    setX(x);
    setY(y);
    setZ(z);
}

Position::Position(ChunkPosition cp) {
    setX(cp.x * chunkSize * representationComaValue);
    setY(0);
    setZ(cp.z * chunkSize * representationComaValue);
}

Position::Position() {
    setX(0);
    setY(0);
    setZ(0);
}

int Position::getX() const {
    return _x / representationComaValue;
}

int Position::getY() const {
    return _x / representationComaValue;
}

int Position::getZ() const {
    return _z / representationComaValue;
}

int Position::getAccurateX() const {
    return _x;
}

int Position::getAccurateY() const {
    return _x;
}

int Position::getAccurateZ() const {
    return _z;
}

int Position::x() const {
    return getX();
}

int Position::y() const {
    return getY();
}

int Position::z() const {
    return getZ();
}

void Position::setX(int x) {
    _x = x * representationComaValue;
}

void Position::setY(int y) {
    if (y >= worldHeight or y < 0)
        throw std::logic_error("Incorrect height of a position.");
    _y = y * representationComaValue;
}

void Position::setZ(int z) {
    _z = z * representationComaValue;
}

int Position::getChunkX() {
    return int(_x) / chunkSize / representationComaValue;
}

int Position::getChunkZ() {
    return int(_z) / chunkSize / representationComaValue;
}

ChunkPosition Position::getChunkPosition() {
    return ChunkPosition(getChunkX(), getChunkZ());
}

int Position::getInsideChunkRawX() {
    return fmod(_x, chunkSize * representationComaValue);
}

int Position::getInsideChunkRawZ() {
    return fmod(_z, chunkSize * representationComaValue);
}

std::string Position::getTextX() {
    return std::to_string(_x / representationComaValue);
}

std::string Position::getTextY() {
    return std::to_string(_y / representationComaValue);
}

std::string Position::getTextZ() {
    return std::to_string(_z / representationComaValue);
}

std::string Position::getText() {
    return "(X=" + getTextX() + ",Y=" + getTextY() + ",Z=" + getTextZ() + ")";
}

NeighbouringChunkPositions Position::getNeighbouringChunkPositions() {
    const int chunksInLine = (chunkRenderDistance - 1) * 2 + 1;
    const int displacement = chunksInLine / 2;
    const int chunkAmount = chunksInLine * chunksInLine;

    NeighbouringChunkPositions ncp = {
        new ChunkPosition[chunkAmount],
        chunkAmount
    };

    for (int i = 0; i < chunksInLine; i++) {
        for (int j = 0; j < chunksInLine; j++) {
            ncp.chunkPositions[i * chunksInLine + j].x = getChunkX() - displacement + j;
            ncp.chunkPositions[i * chunksInLine + j].z = getChunkZ() - displacement + i;
        }
    }
    return ncp;
}

bool Position::operator==(const Position &other) const {
    return _x == other._x 
        && _y == other._y
        && _z == other._z;
}
