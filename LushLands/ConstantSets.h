#pragma once
#include "Color.h"
#include <allegro5/events.h>

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
namespace ll = logging_level;

// Scene types
const scenename GAMEPLAY_SCENE = "gameplay";
const scenename MAINMENU_SCENE = "main_menu";

// World types
const worldtype FLATLAND = "flatland";

// Entity types (ground)
const entitytype AIR = "air";
const entitytype SOIL = "soil";
const entitytype GRASS = "grass";
const entitytype WATER = "water";
const entitytype SAND = "sand";
const entitytype ROCK = "rock";
const entitytype COBBLE = "cobble";
const entitytype FARMLAND = "farmland";
const entitytype GRAVEL = "gravel";
const entitytype SNOW = "snow";
// Entity types (structures)
const entitytype TREE = "tree";
const entitytype BUSH = "bush";
const entitytype TALL_GRASS = "tall_grass";
const entitytype FLOWER_YELLOW = "yellow_flower";
const entitytype STONE = "stone";
const entitytype LOG = "log";
// Entity types (animals)

// Colors (ground)
const Color SOIL_COLOR = Color(100, 60, 20, 255);
const Color GRASS_COLOR = Color(80, 100, 50, 255);
const Color WATER_COLOR = Color(15, 50, 100, 255);
const Color SAND_COLOR = Color(200, 200, 110, 255);
const Color ROCK_COLOR = Color(100, 110, 120, 255);
const Color COBBLE_COLOR = Color(100, 120, 110, 255);
const Color FARMLAND_COLOR = Color(60, 40, 20, 255);
const Color GRAVEL_COLOR = Color(80, 80, 100, 255);
const Color SNOW_COLOR = Color(240, 240, 250, 255);
// Colors (structures)
const Color TREE_COLOR = Color(70, 120, 50, 255);
const Color BUSH_COLOR = TREE_COLOR;
const Color TALL_GRASS_COLOR = Color(50, 120, 40, 255);
const Color FLOWER_YELLOW_COLOR = TALL_GRASS_COLOR;
const Color STONE_COLOR = Color(90, 100, 110, 255);
const Color LOG_COLOR = Color(90, 80, 50, 255);
// Colors (animals)

// Descriptions (ground)
const std::string SOIL_DESCRIPTION = "Fertile soil.";
const std::string GRASS_DESCRIPTION = "Green, idyllic grass.";
const std::string WATER_DESCRIPTION = "Drinkable freshwater.";
const std::string SAND_DESCRIPTION = "Sand, just like on a beach.";
const std::string ROCK_DESCRIPTION = "Hard as rock.";
const std::string COBBLE_DESCRIPTION = "Crushed rocks.";
const std::string FARMLAND_DESCRIPTION = "Land ready to grow crops.";
const std::string GRAVEL_DESCRIPTION = "Lots of small, loose stones.";
const std::string SNOW_DESCRIPTION = "So cold and crunches under your feet.";
// Descriptions (structures)
const std::string TREE_DESCRIPTION = "Tall tree, gives a lot of shade.";
const std::string BUSH_DESCRIPTION = "Big blob of leaves";
const std::string TALL_GRASS_DESCRIPTION = "Tallgrass, hard to pass through.";
const std::string FLOWER_YELLOW_DESCRIPTION = "Yellow flower.";
const std::string STONE_DESCRIPTION = "Just a stone, sized like any other stone.";
const std::string LOG_DESCRIPTION = "Fallen tree, doesn't give too much shade anymore.";
// Descriptions (animals)

// Texture paths (ground)
const TextureLocalization SOIL_TEXTURE_LOCALIZATION = TextureLocalization(64, 64, "..\\Assets\\textures\\RPG Nature Tileset - Seasons by Stealthix\\RPG Nature Tileset.png");
const TextureLocalization GRASS_TEXTURE_LOCALIZATION = TextureLocalization(0, 64, "..\\Assets\\textures\\RPG Nature Tileset - Seasons by Stealthix\\RPG Nature Tileset.png");
const TextureLocalization WATER_TEXTURE_LOCALIZATION = TextureLocalization(0, 0, "..\\Assets\\textures\\32x32 and 64x64 Pixel Art Textures by 711studios\\32x32 Tiles\\Water.png");
const TextureLocalization SAND_TEXTURE_LOCALIZATION = TextureLocalization(0, 0, "..\\Assets\\textures\\32x32 and 64x64 Pixel Art Textures by 711studios\\32x32 Tiles\\Dehydrated_Earth.png");
const TextureLocalization ROCK_TEXTURE_LOCALIZATION = TextureLocalization(96, 64, "..\\Assets\\textures\\RPG Nature Tileset - Seasons by Stealthix\\RPG Nature Tileset.png");
const TextureLocalization COBBLE_TEXTURE_LOCALIZATION = TextureLocalization(64, 64, "..\\Assets\\textures\\RPG Nature Tileset - Seasons by Stealthix\\IceTileset.png");
const TextureLocalization FARMLAND_TEXTURE_LOCALIZATION = TextureLocalization(126, 9, "..\\Assets\\textures\\Edinnu Small Forest by rowdy41\\Ground tileset\\Earth-tileset.png");
const TextureLocalization GRAVEL_TEXTURE_LOCALIZATION = TextureLocalization(0, 0, "..\\Assets\\textures\\32x32 and 64x64 Pixel Art Textures by 711studios\\32x32 Tiles\\Metal_Floor.png");
const TextureLocalization SNOW_TEXTURE_LOCALIZATION = TextureLocalization(0, 64, "..\\Assets\\textures\\RPG Nature Tileset - Seasons by Stealthix\\IceTileset.png");
// Texture names (structures)
const TextureLocalization TREE_TEXTURE_LOCALIZATION = TextureLocalization(0, 0, "..\\Assets\\textures\\RPG Nature Tileset - Seasons by Stealthix\\RPG Nature Tileset.png", 32, 64);
const TextureLocalization BUSH_TEXTURE_LOCALIZATION = TextureLocalization(0, 0, "..\\Assets\\textures\\Edinnu Small Forest by rowdy41\\Bushes\\Bush-3.png", 25, 19);
const TextureLocalization TALL_GRASS_TEXTURE_LOCALIZATION = TextureLocalization(0, 0, "..\\Assets\\textures\\Edinnu Small Forest by rowdy41\\Grass\\Grass-1.png", 25, 24);
const TextureLocalization FLOWER_YELLOW_TEXTURE_LOCALIZATION = TextureLocalization(0, 0, "..\\Assets\\textures\\Edinnu Small Forest by rowdy41\\Flowers\\Flower-2.png", 24, 22);
const TextureLocalization STONE_TEXTURE_LOCALIZATION = TextureLocalization(64, 32, "..\\Assets\\textures\\RPG Nature Tileset - Seasons by Stealthix\\RPG Nature Tileset.png");
const TextureLocalization LOG_TEXTURE_LOCALIZATION = TextureLocalization(128, 0, "..\\Assets\\textures\\RPG Nature Tileset - Seasons by Stealthix\\RPG Nature Tileset.png");
// Texture names (animals)

// Exception messages
const exceptionmessage could_not_init_allegro = "Could not initialize Allegro.\n";
const exceptionmessage cannot_run_uninitialized = "Cannot run main loop without initialization.\n";
const exceptionmessage could_not_init_allegro_font = "Could not initialize Allegro Font Addon.\n";
const exceptionmessage could_not_init_allegro_ttf = "Could not initialize Allegro TTF Addon.\n";
const exceptionmessage could_not_create_event_queue = "Could not create event queue.\n";
const exceptionmessage could_not_install_keyboard = "Could not install keyboard.\n";
const exceptionmessage could_not_create_display = "Could not create display.\n";
const exceptionmessage system_event_in_world_event_queue = "Unexpected system event found in world event queue.\n";
const exceptionmessage could_not_init_primitives = "Could not initialize Allegro primitives addon.\n";
const exceptionmessage ui_element_priority = "User Interface Element priority needs to be set above fp::UI value.\n";

// Debug colors
const Color COLOR_RED = Color(255, 0, 20, 255);
const Color DEBUG_CHUNK_BORDER_COLOR = COLOR_RED;
// System colors
const Color TRANSPARENT_COLOR = Color(0, 0, 0, 0);
const Color CHAT_GRAY_COLOR = Color(220, 220, 220, 255);
// Fonts 
const rawpath jamesStrokerFont = "fonts/James Stroker.ttf";
const rawpath openSansSBFont = "fonts/OpenSans-Semibold.ttf";

// World event types
const worldevent player_attempt_go_north = ALLEGRO_GET_EVENT_TYPE('P', 'A', 'G', 0);
const worldevent player_attempt_go_south = player_attempt_go_north + 1;
const worldevent player_attempt_go_east =  player_attempt_go_north + 2;
const worldevent player_attempt_go_west =  player_attempt_go_north + 3;
const worldevent player_attempt_use = ALLEGRO_GET_EVENT_TYPE('P', 'A', 'U', 0);

// System Event Types
const systemevent letter_typed = ALLEGRO_GET_EVENT_TYPE('U', 'L', 'T', 0);
const systemevent camera_move_north = ALLEGRO_GET_EVENT_TYPE('U', 'A', 'G', 0);
const systemevent camera_move_south = camera_move_north + 1;
const systemevent camera_move_east =  camera_move_north + 2;
const systemevent camera_move_west =  camera_move_north + 3;
