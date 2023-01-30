#pragma once
#include <unordered_map>
#include <allegro5/keycodes.h>
#include <functional>
#include "DataTypes.h"
#include "ConstantSets.h"
#include "Events.h"


class ActionMap {
    /**
    * Provides keycodes for mapping actioncodes.
    */
private:
    std::unordered_map<keycode, simulationevent> worldActionMap;
    std::unordered_map<keycode, systemevent> systemActionMap;
public:
    ActionMap();
    simulationevent mapToWorldAction(keycode kc);
    systemevent mapToSystemAction(keycode kc);
};

