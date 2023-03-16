#pragma once
#include "DataTypes.h"

namespace focus {
    // Object Groups
    const objectgroup STATIC_UI = "static_ui";
    const objectgroup WORLD_UI = "world_ui";
    const objectgroup SIMULATION = "simulation";

    // Object Types (world)
    const objecttype GROUND = "ground";
    const objecttype STRUCTURE = "structure";
    const objecttype ITEM_IN_INVENTORY = "item_in_inventory";
    const objecttype ITEM_PUT_ON_GROUND = "item_put_on_ground";
    // Object Types (ui)
    const objecttype CAMERA = "camera";
    const objecttype CONSOLE = "console";
    const objecttype UI_WINDOW = "ui_window";
}
namespace f = focus;

namespace focus_priority {
    // Focus priority
    const priority DEFAULT = USHRT_MAX;
    const priority UI = 1024;
    const priority CONSOLE = 1;
}
namespace fp = focus_priority;

namespace logging_level {
    // Logging levels (debug)
    const loglevel DEBUG_ALL = 0;
    const loglevel DEBUG_ENTITY = 20;
    const loglevel DEBUG_CHUNK = 30;
    const loglevel DEBUG_WORLD = 30;
    const loglevel DEBUG_SIMULATION = 40;
    const loglevel DEBUG_SYSTEM = 50;
    // Logging levels (user messages)
    const loglevel USER_COMMAND = 254;
    const loglevel USER_MESSAGE = 255;
}
namespace lg = logging_level;

namespace random_actions {
    // Random Walk
    const actiontype walking = "walking";
    const actiontype waiting = "waiting";
}
namespace ra = random_actions;

// Scene types
const scenename GAMEPLAY_SCENE = "gameplay";
const scenename MAINMENU_SCENE = "main_menu";

// World types
const worldtype FLATLAND = "flatland";

// Exception messages
const exceptionmessage not_implemented = "Not implemented yet.\n";
const exceptionmessage could_not_init_allegro = "Could not initialize Allegro.\n";
const exceptionmessage cannot_run_uninitialized = "Cannot run main loop without initialization.\n";
const exceptionmessage could_not_init_allegro_font = "Could not initialize Allegro Font Addon.\n";
const exceptionmessage could_not_init_allegro_ttf = "Could not initialize Allegro TTF Addon.\n";
const exceptionmessage could_not_create_event_queue = "Could not create event queue.\n";
const exceptionmessage could_not_install_keyboard = "Could not install keyboard.\n";
const exceptionmessage could_not_create_display = "Could not create display.\n";
const exceptionmessage system_event_in_world_event_queue = "Unexpected system event found in world event queue.\n";
const exceptionmessage system_event_in_chunk_event_queue = "Unexpected system event found in chunk event queue.\n";
const exceptionmessage could_not_init_primitives = "Could not initialize Allegro primitives addon.\n";
const exceptionmessage ui_element_priority = "User Interface Element priority needs to be set above fp::UI value.\n";
const exceptionmessage could_not_create_random_from_type = "Could not create random value using provided type.\n";

// Fonts 
const rawpath jamesStrokerFont = "fonts/James Stroker.ttf";
const rawpath openSansSBFont = "fonts/OpenSans-Semibold.ttf";

// Entity Update Type
const updatetype no_update = "no_update";
const updatetype random_tick = "random_tick";
const updatetype constant_update = "constant_update";
