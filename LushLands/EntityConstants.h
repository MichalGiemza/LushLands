#pragma once
#include "DataTypes.h"
#include "Color.h"


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
const entitytype CHICKEN = "chicken";

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
const Color CHICKEN_COLOR = Color(250, 240, 230, 255);

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
const std::string CHICKEN_DESCRIPTION = "A chicken! There should be eggs somewhere around.";

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
const TextureLocalization CHICKEN_TEXTURE_LOCALIZATION = TextureLocalization(0, 130, "..\\Assets\\textures\\Cozy Farm Asset Pack by shubibubi\\free.png", 16, 16);