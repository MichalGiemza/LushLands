#pragma once
#include <allegro5/events.h>
#include <boost/functional/hash.hpp>
#include <boost/container_hash/hash.hpp>
#include <functional>
#include <filesystem>
#include <tuple>
#include "Constants.h"

namespace fs = std::filesystem;

typedef const int cstint;
typedef unsigned char stack;
typedef long long ll;
typedef int tickperiod;
typedef int keycode;
typedef int mousebcode;
typedef const char *actiontype;
typedef const char *worldtype;
typedef const char *entitytype;
typedef const char *templateclass;
typedef const char *tag;
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
    entitytype ground = 0;
    entitytype structure = 0;
    entitytype animal = 0;
    entitytype item = 0;
    stack itemAmount = 0;
};

struct ItemDropChance {
    entitytype item;
    int chanceGuaranteed;
    int chanceLow;
    int chanceHigh;
};

struct EntityDrops {
    int n;
    ItemDropChance *dropChances;
};

struct ChunkPlan { // TODO: Zrobiæ z tego generator, takie jedno coœ mo¿e zajmowaæ chyba ok. 1.5MB miejsca.
    FieldPlan fieldPlans[chunkSizeByTiles][chunkSizeByTiles][worldHeight]; // [X][Z][Y]
};

struct TextureLocalization {
    /** 
    * x, y - position on bitmap
    * x, h - tile size, default is defined in constants as tileSize
    * path - to source image
    */
    int x = 0, y = 0; 
    std::string path = "..\\Assets\\textures\\default.png";
    int w = tileSizePx, h = tileSizePx;
    int variation = 0;
    bool operator==(const TextureLocalization &other) const {
        return x == other.x && y == other.y && path == other.path;
    }
};

template<> struct std::hash<char *> {
    std::size_t operator()(const char *p) const;
};

template<> struct std::hash<TextureLocalization> {
    std::size_t operator()(const TextureLocalization &p) const;
};

bool operator==(const std::tuple<float, float, float> &lhs, const std::tuple<float, float, float> &rhs);
template<> struct std::hash<std::tuple<float, float, float>> {
    std::size_t operator()(const std::tuple<float, float, float> &p) const;
};

bool operator==(const std::tuple<uint8_t, uint8_t, uint8_t> &lhs, const std::tuple<uint8_t, uint8_t, uint8_t> &rhs);
template<> struct std::hash<std::tuple<uint8_t, uint8_t, uint8_t>> {
    std::size_t operator()(const std::tuple<uint8_t, uint8_t, uint8_t> &p) const;
};
