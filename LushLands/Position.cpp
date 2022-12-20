#include "Position.h"


Position::Position(int x, int y, int z, bool accurate) {
    if (accurate) {
        setAccurateX(x);
        setAccurateY(y);
        setAccurateZ(z);
    } else {
        setX(x);
        setY(y);
        setZ(z);
    }
}

Position::Position(ChunkPosition &cp) {
    setX(cp.x * chunkSizeByTiles);
    setY(0);
    setZ(cp.z * chunkSizeByTiles);
}

Position::Position(const ChunkPosition &cp) {
    setX(cp.x * chunkSizeByTiles);
    setY(0);
    setZ(cp.z * chunkSizeByTiles);
}

Position::Position(TilePosition &tp) {
    setX(tp.x);
    setY(tp.y);
    setZ(tp.z);
}

Position::Position(const TilePosition &tp) {
    setX(tp.x);
    setY(tp.y);
    setZ(tp.z);
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
    return _y / representationComaValue;
}

int Position::getZ() const {
    return _z / representationComaValue;
}

int Position::getAccurateX() const {
    return _x;
}

int Position::getAccurateY() const {
    return _y;
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
    if (y >= worldHeight || y < 0)
        throw std::logic_error("Incorrect height of a position.");
    _y = y * representationComaValue;
}

void Position::setZ(int z) {
    _z = z * representationComaValue;
}

void Position::setAccurateX(int x) {
    _x = x;
}

void Position::setAccurateY(int y) {
    if (y * representationComaValue >= worldHeight || y * representationComaValue < 0)
        throw std::logic_error("Incorrect height of a position.");
    _y = y;
}

void Position::setAccurateZ(int z) {
    _z = z;
}


int Position::getChunkX() const {
    return _x / chunkSizeByTiles / representationComaValue;
}

int Position::getChunkZ() const {
    return _z / chunkSizeByTiles / representationComaValue;
}

ChunkPosition Position::getChunkPosition() const {
    return ChunkPosition(getChunkX(), getChunkZ());
}

TilePosition Position::getTilePosition() const {
    TilePosition tp = TilePosition();
    tp.x = getX();
    tp.y = getY();
    tp.z = getZ();
    return tp;
}

int Position::getInsideChunkRawX() const {
    return fmod(_x, chunkSizeByTiles * representationComaValue);
}

int Position::getInsideChunkRawZ() const {
    return fmod(_z, chunkSizeByTiles * representationComaValue);
}

std::string Position::getTextX() const {
    return std::to_string(_x / representationComaValue);
}

std::string Position::getTextY() const {
    return std::to_string(_y / representationComaValue);
}

std::string Position::getTextZ() const {
    return std::to_string(_z / representationComaValue);
}

std::string Position::getText() const {
    return "(X=" + getTextX() + ",Y=" + getTextY() + ",Z=" + getTextZ() + ")";
}

NeighbouringChunkPositions Position::getNeighbouringChunkPositions() const {
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

Position Position::operator-(const Position &other) const {
    return Position(
        (_x - other._x) / representationComaValue, 
        std::max((_y - other._y) / representationComaValue, 0),
        (_z - other._z) / representationComaValue);
}

Position Position::operator+(const Position &other) const {
    return Position(
        (_x + other._x) / representationComaValue,
        std::min((_y + other._y) / representationComaValue, worldHeight - 1),
        (_z + other._z) / representationComaValue);
}
