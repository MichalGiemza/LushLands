#include "Position.h"


ll Position::objectCount = 0;

Position::Position(ll x, ll y, ll z, bool accurate) {
    if (accurate) {
        setPX(x);
        setPY(y);
        setPZ(z);
    } else {
        setX(x);
        setY(y);
        setZ(z);
    }
    objectCount += 1;
}

Position::Position(ChunkPosition &cp) {
    setX(cp.x * chunkSizeByTiles);
    setY(0);
    setZ(cp.z * chunkSizeByTiles);

    objectCount += 1;
}

Position::Position(const ChunkPosition &cp) {
    setX(cp.x * chunkSizeByTiles);
    setY(0);
    setZ(cp.z * chunkSizeByTiles);

    objectCount += 1;
}

Position::Position(TilePosition &tp) {
    setX(tp.x);
    setY(tp.y);
    setZ(tp.z);

    objectCount += 1;
}

Position::Position(const TilePosition &tp) {
    setX(tp.x);
    setY(tp.y);
    setZ(tp.z);

    objectCount += 1;
}

Position::Position(const Position &cp) : Position(cp._x, cp._y, cp._z, true) {
    objectCount += 1;
}

Position::Position() {
    setX(0);
    setY(0);
    setZ(0);

    objectCount += 1;
}

Position::~Position() {
    objectCount -= 1;
}

ll Position::getX() const {
    return _x / representationComaValue;
}

ll Position::getY() const {
    return _y / representationComaValue;
}

ll Position::getZ() const {
    return _z / representationComaValue;
}

ll Position::getPX() const {
    return _x;
}

ll Position::getPY() const {
    return _y;
}

ll Position::getPZ() const {
    return _z;
}

void Position::setX(ll x) {
    _x = x * representationComaValue;
}

void Position::setY(ll y) {
    if (y >= worldHeight || y * representationComaValue < 0)
        throw std::logic_error("Incorrect height of a position.");
    _y = y * representationComaValue;
}

void Position::setZ(ll z) {
    _z = z * representationComaValue;
}

void Position::setPX(ll x) {
    _x = x;
}

void Position::setPY(ll y) {
    if (y >= worldHeight * representationComaValue || y < 0)
        throw std::logic_error("Incorrect height of a position.");
    _y = y;
}

void Position::setPZ(ll z) {
    _z = z;
}

ll Position::getChunkX() const {
    return _x / chunkSizeByTiles / representationComaValue;
}

ll Position::getChunkZ() const {
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

void Position::updateTilePosition(TilePosition &tp) const {
    tp.x = getX();
    tp.y = getY();
    tp.z = getZ();
}

ll Position::getInsideChunkRawX() const {
    return fmod(_x, chunkSizeByTiles * representationComaValue);
}

ll Position::getInsideChunkRawZ() const {
    return fmod(_z, chunkSizeByTiles * representationComaValue);
}

std::string Position::getTextX() const {
    return std::to_string(_x / representationComaValue);
}

std::string Position::getTextY() const {
    return std::to_string(_y / representationComaValue);
}

void Position::updatePosition(const Position &pos) {
    setPX(pos._x);
    setPY(pos._y);
    setPZ(pos._z);
}

void Position::push2D(radian direction, ll distance) {
    setPX(getPX() - std::sin(direction) * distance);
    setPZ(getPZ() + std::cos(direction) * distance);
}

std::string Position::getTextZ() const {
    return std::to_string(_z / representationComaValue);
}

ll Position::distance3D(const Position &other) const {
    ll x = getPX() - other.getPX();
    ll y = getPY() - other.getPY();
    ll z = getPZ() - other.getPZ();
    return std::sqrt(x * x + y * y + z * z);
}

ll Position::distance2D(const Position &other) const {
    ll x = getPX() - other.getPX();
    ll z = getPZ() - other.getPZ();
    return std::sqrt(x * x + z * z);
}

std::string Position::getText() const {
    return "(X=" + getTextX() + ",Y=" + getTextY() + ",Z=" + getTextZ() + ")";
}

ChunkPositionsSet Position::getNeighbouringChunkPositions() const {
    const ll chunksInLine = (chunkRenderDistance - 1) * 2 + 1;
    const ll displacement = chunksInLine / 2;
    const ll chunkAmount = chunksInLine * chunksInLine;

    ChunkPositionsSet ncp = {
        new ChunkPosition[chunkAmount],
        chunkAmount
    };

    for (ll i = 0; i < chunksInLine; i++) {
        for (ll j = 0; j < chunksInLine; j++) {
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
        std::max((_y - other._y) / representationComaValue, (ll)0),
        (_z - other._z) / representationComaValue);
}

Position Position::operator+(const Position &other) const {
    return Position(
        (_x + other._x) / representationComaValue,
        std::min((_y + other._y) / representationComaValue, worldHeight - 1), 
        (_z + other._z) / representationComaValue);
}

void Position::operator=(const Position &other) {
    setPX(other._x);
    setPY(other._y);
    setPZ(other._z);
}
