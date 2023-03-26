#include "ActionMap.h"

ActionMap::ActionMap() {
    worldKeyboardActionMap = {
        { ALLEGRO_KEY_W, player_wills_go_north },
        { ALLEGRO_KEY_S, player_wills_go_south },
        { ALLEGRO_KEY_A, player_wills_go_east },
        { ALLEGRO_KEY_D, player_wills_go_west },

        { ALLEGRO_KEY_E, player_wills_use },

        { ALLEGRO_KEY_1, player_hotbar + 0 },
        { ALLEGRO_KEY_2, player_hotbar + 1 },
        { ALLEGRO_KEY_3, player_hotbar + 2 },
        { ALLEGRO_KEY_4, player_hotbar + 3 },
        { ALLEGRO_KEY_5, player_hotbar + 4 },
        { ALLEGRO_KEY_6, player_hotbar + 5 },
        { ALLEGRO_KEY_7, player_hotbar + 6 },
        { ALLEGRO_KEY_8, player_hotbar + 7 },
        { ALLEGRO_KEY_9, player_hotbar + 8 },
        { ALLEGRO_KEY_0, player_hotbar + 9 },
        { ALLEGRO_KEY_MINUS, player_hotbar + 10 },
        { ALLEGRO_KEY_EQUALS, player_hotbar + 11 }
    };
    systemKeyboardActionMap = {
        { ALLEGRO_KEY_ESCAPE, user_open_pause_menu },

        { ALLEGRO_KEY_I, user_open_inventory },
        { ALLEGRO_KEY_M, user_open_map },
        { ALLEGRO_KEY_T, user_open_chat },
        { ALLEGRO_KEY_SLASH, user_open_command_chat },
        { ALLEGRO_KEY_C, user_open_status },
        { ALLEGRO_KEY_J, user_open_quests },
        { ALLEGRO_KEY_B, user_open_build_menu },

        { ALLEGRO_KEY_F5, user_quick_save },
        { ALLEGRO_KEY_F9, user_quick_load },

        { ALLEGRO_KEY_W, camera_move_north },
        { ALLEGRO_KEY_S, camera_move_south },
        { ALLEGRO_KEY_A, camera_move_east },
        { ALLEGRO_KEY_D, camera_move_west }
    };
    worldMouseActionMap = {
        { MOUSE_LMB, player_wills_use }
    };
    systemMouseActionMap = {
        { MOUSE_LMB, user_interact },
        { MOUSE_RMB, user_open_context_menu }
    };
}

simulationevent ActionMap::mapKeyboardToWorldAction(keycode kc) {
    if (worldKeyboardActionMap.find(kc) == worldKeyboardActionMap.end())
        return -1;
    return worldKeyboardActionMap[kc];
}

systemevent ActionMap::mapKeyboardToSystemAction(keycode kc) {
    if (systemKeyboardActionMap.find(kc) == systemKeyboardActionMap.end())
        return -1;
    return systemKeyboardActionMap[kc];
}

simulationevent ActionMap::mapMouseToWorldAction(keycode kc) {
    if (worldMouseActionMap.find(kc) == worldMouseActionMap.end())
        return -1;
    return worldMouseActionMap[kc];
}

systemevent ActionMap::mapMouseToSystemAction(keycode kc) {
    if (systemMouseActionMap.find(kc) == systemMouseActionMap.end())
        return -1;
    return systemMouseActionMap[kc];
}

