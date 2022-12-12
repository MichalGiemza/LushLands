#pragma once
#include <unordered_map>
#include <allegro5/keycodes.h>
#include <functional>
#include "DataTypes.h"
#include "ConstantSets.h"


class ActionMap {
    /**
    * Provides keycodes for mapping actioncodes.
    */
private:
    std::unordered_map<keycode, worldevent> worldActionMap;
    std::unordered_map<keycode, systemevent> systemActionMap;
public:
    ActionMap();
    worldevent mapToWorldAction(keycode kc);
    systemevent mapToSystemAction(keycode kc);
};

