#pragma once
#include <string>
#include <functional>

typedef int tickperiod;
typedef int keycode;
typedef const char *actioncode;
typedef std::function<void()> eventfn;
typedef const char *worldtype;
typedef const char *entitytype;
typedef int seed;


struct FieldPlan {
    entitytype ground;
    entitytype structure;
    entitytype animal;
};
