#pragma once
#include <string>
#include <functional>
#include <filesystem>
#include "Constants.h"

typedef int tickperiod;
typedef int keycode;
typedef const char *actioncode;
typedef std::function<void()> eventfn;
typedef const char *worldtype;
typedef const char *entitytype;
typedef int seed;
typedef std::filesystem::path path;
typedef const char *texturename;


struct FieldPlan {
    entitytype ground;
    entitytype structure;
    entitytype animal;
};

struct ChunkPlan {
    FieldPlan fieldPlans[chunkSize][chunkSize];
};

class not_implemented_error : public std::logic_error {
public:
    not_implemented_error() : std::logic_error("Function not yet implemented.") {}
};