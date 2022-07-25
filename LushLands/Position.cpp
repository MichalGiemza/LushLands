#include <math.h>
#include <string>
#include "Position.h"
#include "Constants.h"
#include <stdexcept>

using namespace std;


Position::Position(int x, int y, int z) {
    if (y >= worldHeight or y < 0) 
        throw out_of_range("Incorrect height of a position.");
    setRawX(x);
    setRawY(y);
    setRawZ(z);
}

int Position::getRawX() {
    return _x / representationComaValue;
}

int Position::getRawY() {
    return _x / representationComaValue;
}

int Position::getRawZ() {
    return _z / representationComaValue;
}

void Position::setRawX(int x) {
    _x = x * representationComaValue;
}

void Position::setRawY(int y) {
    _y = y * representationComaValue;
}

void Position::setRawZ(int z) {
    _z = z * representationComaValue;
}

int Position::getChunkX() {
    return int(_x) / chunkSize / representationComaValue;
}

int Position::getChunkZ() {
    return int(_z) / chunkSize / representationComaValue;
}

int Position::getInsideChunkRawX() {
    return fmod(_x, chunkSize * representationComaValue);
}

int Position::getInsideChunkRawZ() {
    return fmod(_z, chunkSize * representationComaValue);
}

string Position::getTextX() {
    return to_string(_x / representationComaValue);
}

string Position::getTextY() {
    return to_string(_y / representationComaValue);
}

string Position::getTextZ() {
    return to_string(_z / representationComaValue);
}

string Position::getText() {
    return "(X=" + getTextX() + ",Y=" + getTextY() + ",Z=" + getTextZ() + ")";
}
