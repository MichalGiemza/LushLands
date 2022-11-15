#include "ActionMap.h"

std::map<keycode, actioncode> ActionMap::actionMap;

void ActionMap::init() {
    ActionMap::actionMap = std::map<keycode, actioncode>();
    ActionMap::actionMap[ALLEGRO_KEY_W] = GO_NORTH;
    ActionMap::actionMap[ALLEGRO_KEY_S] = GO_SOUTH;
    ActionMap::actionMap[ALLEGRO_KEY_A] = GO_WEST;
    ActionMap::actionMap[ALLEGRO_KEY_D] = GO_EAST;
    ActionMap::actionMap[ALLEGRO_KEY_E] = USE;
}

actioncode ActionMap::mapKeyToCode(keycode kc) {
    return ActionMap::actionMap[kc];
}

