#pragma once
#include <map>
#include <allegro5/keycodes.h>
#include <functional>
#include "DataTypes.h"
#include "Actions.h"
#include "ConstantSets.h"


class ActionMap {
    /**
    * Provides keycodes for mapping actioncodes.
    */
private:
    static std::map<keycode, actioncode> actionMap;
public:
    static void init();
    static std::map<keycode, actioncode> getActionMap() { return actionMap; }

    static actioncode mapKeyToCode(keycode kc);
};

