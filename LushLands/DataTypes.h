#pragma once
#include <functional>
#include <filesystem>
#include "Constants.h"

namespace fs = std::filesystem;

typedef int tickperiod;
typedef int keycode;
typedef const char *actioncode;
typedef std::function<void(void *obj)> eventfn;
typedef const char *worldtype;
typedef const char *entitytype;
typedef int seed;
typedef const char *texturename;
typedef const char *scenename;
typedef const char *rawpath;
typedef int pxint;
typedef const char *exceptionmessage;

struct FieldPlan {
    entitytype ground;
    entitytype structure;
    entitytype animal;
};

struct ChunkPlan { // TODO: Zrobiæ z tego generator, takie jedno coœ mo¿e zajmowaæ chyba ok. 1.5MB miejsca.
    FieldPlan fieldPlans[chunkSizeByTiles][chunkSizeByTiles][worldHeight]; // [X][Z][Y]
};

class not_implemented_error : public std::logic_error {
public:
    not_implemented_error() : std::logic_error("Function not yet implemented.") {}
};

struct TextureLocalization {
    int x, y; // [x,y] position on bitmap, 32x32 tile size defined in constants as tileSize
    const char *path;
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
