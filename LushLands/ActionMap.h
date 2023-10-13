#pragma once
#include "stdafx.h"


class ActionMap {
    /**
    * Provides keycodes for mapping actioncodes.
    */
private:
    std::unordered_map<keycode, simulationevent> worldKeyboardActionPressMap;
    std::unordered_map<keycode, simulationevent> systemKeyboardActionPressMap;
    std::unordered_map<keycode, systemevent> systemKeyboardActionMap;
    std::unordered_map<mousebcode, systemevent> worldMouseActionMap;
    std::unordered_map<mousebcode, systemevent> systemMouseActionMap;
public:
    ActionMap();
    simulationevent mapKeyboardToWorldPressAction(keycode kc);
    systemevent mapKeyboardToSystemAction(keycode kc);
    simulationevent mapMouseToWorldAction(keycode kc);
    systemevent mapMouseToSystemAction(keycode kc);
};

