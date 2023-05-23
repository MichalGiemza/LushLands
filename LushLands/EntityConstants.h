#pragma once
#include "DataTypes.h"
#include "ItemConstants.h"
#include "ConstantSets.h"
#include "Color.h"
#include "Size.h"

namespace entities {

    /*    Defaults    */
    const Size GROUND_SIZE = Size(1, 1, 1);

    /*    Empty    */
    const entitytype AIR = "air";


    /*    Ground    */

    // Soil
    const entitytype SOIL = "soil";
    const Color SOIL_COLOR = Color(100, 60, 20, 255);
    const std::string SOIL_DESCRIPTION = "Fertile soil.";
    const TextureLocalization SOIL_TEXTURE_LOCALIZATION = TextureLocalization(64, 64, "..\\Assets\\textures\\RPG Nature Tileset - Seasons by Stealthix\\RPG Nature Tileset.png");
    extern const EntityDrops SOIL_DROPS;
    const cstint SOIL_HEALTH = 50;
    const tooltype SOIL_TOOL = tlt::shovel;

    // Grass
    const entitytype GRASS = "grass";
    const Color GRASS_COLOR = Color(80, 100, 50, 255);
    const std::string GRASS_DESCRIPTION = "Green, idyllic grass.";
    const TextureLocalization GRASS_TEXTURE_LOCALIZATION = TextureLocalization(0, 64, "..\\Assets\\textures\\RPG Nature Tileset - Seasons by Stealthix\\RPG Nature Tileset.png");
    extern const EntityDrops GRASS_DROPS;
    const cstint GRASS_HEALTH = 50;
    const tooltype GRASS_TOOL = tlt::shovel;

    // Water
    const entitytype WATER = "water";
    const Color WATER_COLOR = Color(15, 50, 100, 255);
    const std::string WATER_DESCRIPTION = "Drinkable freshwater.";
    const TextureLocalization WATER_TEXTURE_LOCALIZATION = TextureLocalization(0, 0, "..\\Assets\\textures\\32x32 and 64x64 Pixel Art Textures by 711studios\\32x32 Tiles\\Water.png");
    extern const EntityDrops WATER_DROPS;
    const cstint WATER_HEALTH = 50;
    const tooltype WATER_TOOL = tlt::bucket;

    // Sand
    const entitytype SAND = "sand";
    const Color SAND_COLOR = Color(200, 200, 110, 255);
    const std::string SAND_DESCRIPTION = "Sand, just like on a beach.";
    const TextureLocalization SAND_TEXTURE_LOCALIZATION = TextureLocalization(0, 0, "..\\Assets\\textures\\32x32 and 64x64 Pixel Art Textures by 711studios\\32x32 Tiles\\Dehydrated_Earth.png");
    extern const EntityDrops SAND_DROPS;
    const cstint SAND_HEALTH = 50;
    const tooltype SAND_TOOL = tlt::shovel;

    // Rock
    const entitytype ROCK = "rock";
    const Color ROCK_COLOR = Color(100, 110, 120, 255);
    const std::string ROCK_DESCRIPTION = "Hard as rock.";
    const TextureLocalization ROCK_TEXTURE_LOCALIZATION = TextureLocalization(96, 64, "..\\Assets\\textures\\RPG Nature Tileset - Seasons by Stealthix\\RPG Nature Tileset.png");
    extern const EntityDrops ROCK_DROPS;
    const cstint ROCK_HEALTH = 50;
    const tooltype ROCK_TOOL = tlt::pickaxe;

    // Cobble
    const entitytype COBBLE = "cobble";
    const Color COBBLE_COLOR = Color(100, 120, 110, 255);
    const std::string COBBLE_DESCRIPTION = "Crushed rocks.";
    const TextureLocalization COBBLE_TEXTURE_LOCALIZATION = TextureLocalization(64, 64, "..\\Assets\\textures\\RPG Nature Tileset - Seasons by Stealthix\\IceTileset.png");
    extern const EntityDrops COBBLE_DROPS;
    const cstint COBBLE_HEALTH = 50;
    const tooltype COBBLE_TOOL = tlt::pickaxe;

    // Farmland
    const entitytype FARMLAND = "farmland";
    const Color FARMLAND_COLOR = Color(60, 40, 20, 255);
    const std::string FARMLAND_DESCRIPTION = "Land ready to grow crops.";
    const TextureLocalization FARMLAND_TEXTURE_LOCALIZATION = TextureLocalization(126, 9, "..\\Assets\\textures\\Edinnu Small Forest by rowdy41\\Ground tileset\\Earth-tileset.png");
    extern const EntityDrops FARMLAND_DROPS;
    const cstint FARMLAND_HEALTH = 50;
    const tooltype FARMLAND_TOOL = tlt::shovel;

    // Gravel
    const entitytype GRAVEL = "gravel";
    const Color GRAVEL_COLOR = Color(80, 80, 100, 255);
    const std::string GRAVEL_DESCRIPTION = "Lots of small, loose stones.";
    const TextureLocalization GRAVEL_TEXTURE_LOCALIZATION = TextureLocalization(0, 0, "..\\Assets\\textures\\32x32 and 64x64 Pixel Art Textures by 711studios\\32x32 Tiles\\Metal_Floor.png");
    extern const EntityDrops GRAVEL_DROPS;
    const cstint GRAVEL_HEALTH = 50;
    const tooltype GRAVEL_TOOL = tlt::shovel;

    // Snow
    const entitytype SNOW = "snow";
    const Color SNOW_COLOR = Color(240, 240, 250, 255);
    const std::string SNOW_DESCRIPTION = "So cold and crunches under your feet.";
    const TextureLocalization SNOW_TEXTURE_LOCALIZATION = TextureLocalization(0, 64, "..\\Assets\\textures\\RPG Nature Tileset - Seasons by Stealthix\\IceTileset.png");
    extern const EntityDrops SNOW_DROPS;
    const cstint SNOW_HEALTH = 50;
    const tooltype SNOW_TOOL = tlt::shovel;

    /*    Structure    */

    // Tree
    const entitytype TREE = "tree";
    const Color TREE_COLOR = Color(70, 120, 50, 255);
    const std::string TREE_DESCRIPTION = "Tall tree, gives a lot of shade.";
    const Size TREE_SIZE = Size(1, 2, 1);
    const TextureLocalization TREE_TEXTURE_LOCALIZATION = TextureLocalization(0, 0, "..\\Assets\\textures\\RPG Nature Tileset - Seasons by Stealthix\\RPG Nature Tileset.png", 32, 64);
    extern const EntityDrops TREE_DROPS;
    const cstint TREE_HEALTH = 300;
    const tooltype TREE_TOOL = tlt::axe;

    // Bush
    const entitytype BUSH = "bush";
    const Color BUSH_COLOR = TREE_COLOR;
    const std::string BUSH_DESCRIPTION = "Big blob of leaves";
    const Size BUSH_SIZE = Size(.8f, 0.8f, 0.8f);
    const TextureLocalization BUSH_TEXTURE_LOCALIZATION = TextureLocalization(0, 0, "..\\Assets\\textures\\Edinnu Small Forest by rowdy41\\Bushes\\Bush-3.png", 25, 19);
    extern const EntityDrops BUSH_DROPS;
    const cstint BUSH_HEALTH = 50;
    const tooltype BUSH_TOOL = 0;

    // Tall Grass
    const entitytype TALL_GRASS = "tall_grass";
    const Color TALL_GRASS_COLOR = Color(50, 120, 40, 255);
    const std::string TALL_GRASS_DESCRIPTION = "Tallgrass, hard to pass through.";
    const Size TALL_GRASS_SIZE = Size(.6f, .4f, .6f);
    const TextureLocalization TALL_GRASS_TEXTURE_LOCALIZATION = TextureLocalization(4, 0, "..\\Assets\\textures\\Edinnu Small Forest by rowdy41\\Grass\\Grass-1.png", 21, 24);
    extern const EntityDrops TALL_GRASS_DROPS;
    const cstint TALL_GRASS_HEALTH = 20;
    const tooltype TALL_GRASS_TOOL = 0;


    // Yellow Flower
    const entitytype FLOWER_YELLOW = "yellow_flower";
    const Color FLOWER_YELLOW_COLOR = TALL_GRASS_COLOR;
    const std::string FLOWER_YELLOW_DESCRIPTION = "Yellow flower.";
    const Size FLOWER_YELLOW_SIZE = Size(.2f, .2f, .2f);
    const TextureLocalization FLOWER_YELLOW_TEXTURE_LOCALIZATION = TextureLocalization(0, 0, "..\\Assets\\textures\\Edinnu Small Forest by rowdy41\\Flowers\\Flower-2.png", 24, 22);
    extern const EntityDrops FLOWER_YELLOW_DROPS;
    const cstint FLOWER_YELLOW_HEALTH = 20;
    const tooltype FLOWER_YELLOW_TOOL = 0;

    // Stone
    const entitytype STONE = "stone";
    const Color STONE_COLOR = Color(90, 100, 110, 255);
    const std::string STONE_DESCRIPTION = "Just a stone, sized like any other stone.";
    const Size STONE_SIZE = Size(.5f, .5f, .5f);
    const TextureLocalization STONE_TEXTURE_LOCALIZATION = TextureLocalization(64, 32, "..\\Assets\\textures\\RPG Nature Tileset - Seasons by Stealthix\\RPG Nature Tileset.png");
    extern const EntityDrops STONE_DROPS;
    const cstint STONE_HEALTH = 50;
    const tooltype STONE_TOOL = tlt::pickaxe;

    // Log
    const entitytype LOG = "log";
    const Color LOG_COLOR = Color(90, 80, 50, 255);
    const std::string LOG_DESCRIPTION = "Fallen tree, doesn't give too much shade anymore.";
    const Size LOG_SIZE = Size(1.0f, .6f, .6f);
    const TextureLocalization LOG_TEXTURE_LOCALIZATION = TextureLocalization(128, 0, "..\\Assets\\textures\\RPG Nature Tileset - Seasons by Stealthix\\RPG Nature Tileset.png");
    extern const EntityDrops LOG_DROPS;
    const cstint LOG_HEALTH = 200;
    const tooltype LOG_TOOL = tlt::axe;


    /*    Animal    */

    // Chicken
    const entitytype CHICKEN = "chicken";
    const Color CHICKEN_COLOR = Color(250, 240, 230, 255);
    const std::string CHICKEN_DESCRIPTION = "A chicken! There should be eggs somewhere around.";
    const Size CHICKEN_SIZE = Size(.5f, .5f, .5f);
    const TextureLocalization CHICKEN_TEXTURE_LOCALIZATION = TextureLocalization(0, 130, "..\\Assets\\textures\\Cozy Farm Asset Pack by shubibubi\\free.png", 16, 16);
    const cstint CHICKEN_MOVEMENT_SPEED = 600;
    const miliseconds CHICKEN_WALK_INTERVAL = 5000;
    extern const EntityDrops CHICKEN_DROPS;
    const cstint CHICKEN_HEALTH = 70;
    const tooltype CHICKEN_TOOL = tlt::weapon;


    /*    Humanoids    */

    // HUMAN
    const entitytype HUMAN = "human";
    const Color HUMAN_COLOR = Color(250, 240, 230, 255);
    const std::string HUMAN_DESCRIPTION = "A living human, they are everywhere.";
    const Size HUMAN_SIZE = Size(0.7f, 1.0f, 0.7f);
    const TextureLocalization HUMAN_TEXTURE_LOCALIZATION = TextureLocalization(0, 0, "..\\Assets\\textures\\FREE Mana Seed Character Base Demo\\char_a_p1\\char_a_p1_0bas_humn_v01.png", 64, 64);
    const cstint HUMAN_MOVEMENT_SPEED = 10000;
    const cstint HUMAN_INVENTORY_SLOTS = 12;
    extern const EntityDrops HUMAN_DROPS;
    const cstint HUMAN_HEALTH = 200;
    const tooltype HUMAN_TOOL = tlt::weapon;

}

namespace e = entities;
                                                                                                                  