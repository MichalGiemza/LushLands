#include "ActionMap.h"

ActionMap::ActionMap() {
    worldActionMap = {
        { ALLEGRO_KEY_W, player_attempt_go_north },
        { ALLEGRO_KEY_S, player_attempt_go_south },
        { ALLEGRO_KEY_A, player_attempt_go_east },
        { ALLEGRO_KEY_D, player_attempt_go_west },
        { ALLEGRO_KEY_E, player_attempt_use }
    };
    systemActionMap = {
        { ALLEGRO_KEY_W, camera_move_north },
        { ALLEGRO_KEY_S, camera_move_south },
        { ALLEGRO_KEY_A, camera_move_east },
        { ALLEGRO_KEY_D, camera_move_west }
    };
}

simulationevent ActionMap::mapToWorldAction(keycode kc) {
    if (worldActionMap.find(kc) == worldActionMap.end())
        return -1;
    return worldActionMap[kc];
}

systemevent ActionMap::mapToSystemAction(keycode kc) {
    if (systemActionMap.find(kc) == systemActionMap.end())
        return -1;
    return systemActionMap[kc];
}

