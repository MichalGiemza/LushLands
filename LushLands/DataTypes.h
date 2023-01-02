#pragma once
#include <functional>
#include <filesystem>
#include <allegro5/events.h>
#include "Constants.h"

namespace fs = std::filesystem;

typedef int tickperiod;
typedef int keycode;
typedef const char *actioncode;
typedef std::function<void(ALLEGRO_EVENT *allegroEvent, void *caller)> eventfn;
typedef const char *worldtype;
typedef const char *entitytype;
typedef int seed;
typedef const char *texturename;
typedef const char *scenename;
typedef const char *rawpath;
typedef int pxint;
typedef const char *exceptionmessage;
typedef const int worldevent;
typedef const int systemevent;
typedef unsigned short priority;
typedef const char *objecttype;
typedef const char *objectgroup;
typedef unsigned char loglevel;

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

struct KeySubscribtion {
    eventfn func;
    void *caller;
};

struct TimerSubscription {
    tickperiod period;
    int64_t lastTickExecutedOn;
    eventfn func;
    void *caller;
};

struct SystemEventSubscription {
    systemevent systemEvent;
    eventfn func;
    void *caller;
};

struct LoggerSubscription {
    loglevel logLevel;
    std::function<void(void *caller, char *str)> func;
    void *caller;
};
