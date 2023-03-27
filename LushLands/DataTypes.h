#pragma once
#include <functional>
#include <filesystem>
#include "Constants.h"

namespace fs = std::filesystem;

typedef const int cstint;
typedef long long ll;
typedef int tickperiod;
typedef int keycode;
typedef int mousebcode;
typedef const char *actiontype;
typedef const char *worldtype;
typedef const char *entitytype;
typedef const char *itemtype;
typedef const char *tooltype;
typedef const char *texturename;
typedef const char *scenename;
typedef const char *rawpath;
typedef int pxint;
typedef const char *exceptionmessage;
typedef const int simulationevent;
typedef const int systemevent;
typedef unsigned short priority;
typedef const char *objecttype;
typedef const char *objectgroup;
typedef unsigned char loglevel;
typedef long long miliseconds;
typedef float radian;
typedef const char *season;
typedef const char *updatetype;
typedef const char *name;
typedef const char *gendertype;

struct FieldPlan {
    entitytype ground;
    entitytype structure;
    entitytype animal;
};

struct ItemDropChance {
    itemtype item;
    int chanceGuaranteed;
    int chanceLow;
    int chanceHigh;
};

struct ChunkPlan { // TODO: Zrobiæ z tego generator, takie jedno coœ mo¿e zajmowaæ chyba ok. 1.5MB miejsca.
    FieldPlan fieldPlans[chunkSizeByTiles][chunkSizeByTiles][worldHeight]; // [X][Z][Y]
};

struct TextureLocalization {
    int x, y; // [x,y] position on bitmap, 32x32 tile size defined in constants as tileSize
    const char *path;
    int w = tileSizePx, h = tileSizePx;
    bool operator==(const TextureLocalization &other) const {
        return x == other.x && y == other.y && strcmp(path, other.path) == 0;
    }
};

template<> struct std::hash<char *> {
    std::size_t operator()(const char *p) const {
        std::size_t hash_ = 0;
        for (int i = 0; p[i] != 0; i++) {
            hash_ = 33 * hash_ + p[i];
        }
        return hash_;
    }
};

template<> struct std::hash<TextureLocalization> {
    std::size_t operator()(const TextureLocalization &p) const {
        return
            hash<int>()(p.x) ^
            hash<int>()(p.y) ^
            hash<char *>()(p.path);
    }
};
