#pragma once
#include "DataTypes.h"
#include "Constants.h"
#include "Color.h"

/*    Resources    */
// WOOD
const itemtype WOOD = "wood";
const Color WOOD_COLOR = Color(110, 60, 30, 255);
const std::string WOOD_DESCRIPTION = "Wood from cut down tree.";
const TextureLocalization WOOD_TEXTURE_LOCALIZATION = TextureLocalization(0, 0, "..\\Assets\\textures\\Crafting Materials by Beast Pixels\\resources_basic.png", 24, 24);
const stack WOOD_STACK = maxStack;

// PLANK
const itemtype PLANK = "plank";
const Color PLANK_COLOR = Color(210, 180, 80, 255);
const std::string PLANK_DESCRIPTION = "Wooden plank, one of the most usable resources.";
const TextureLocalization PLANK_TEXTURE_LOCALIZATION = TextureLocalization(24, 0, "..\\Assets\\textures\\Crafting Materials by Beast Pixels\\resources_basic.png", 24, 24);
const stack PLANK_STACK = maxStack;

// BRANCH
const itemtype BRANCH = "branch";
const Color BRANCH_COLOR = Color(110, 60, 30, 255);
const std::string BRANCH_DESCRIPTION = "Branch from a tree.";
const TextureLocalization BRANCH_TEXTURE_LOCALIZATION = TextureLocalization(48, 0, "..\\Assets\\textures\\Crafting Materials by Beast Pixels\\resources_basic.png", 24, 24);
const stack BRANCH_STACK = maxStack;


/*    Animal Loot    */
// MEAT
const itemtype MEAT = "meat";
const Color MEAT_COLOR = Color(60, 10, 30, 255);
const std::string MEAT_DESCRIPTION = "Delicius piece of raw meat.";
const TextureLocalization MEAT_TEXTURE_LOCALIZATION = TextureLocalization(24, 192, "..\\Assets\\textures\\Crafting Materials by Beast Pixels\\resources_basic.png", 24, 24);
const stack MEAT_STACK = maxStack;


// FEATHER
const itemtype FEATHER = "FEATHER";
const Color FEATHER_COLOR = Color(180, 160, 170, 255);
const std::string FEATHER_DESCRIPTION = "Bird's feather.";
const TextureLocalization FEATHER_TEXTURE_LOCALIZATION = TextureLocalization(189, 192, "..\\Assets\\textures\\Crafting Materials by Beast Pixels\\resources_basic.png", 24, 24);
const stack FEATHER_STACK = maxStack;


/*    Tools    */
// SWORD
const itemtype SWORD = "SWORD";
const std::string SWORD_DESCRIPTION = "Most common melee weapon around here.";
const TextureLocalization SWORD_TEXTURE_LOCALIZATION = TextureLocalization(82, 63, "..\\Assets\\textures\\All tools mini-pack by SnowHex\\AllTools - SnowHex.png");
const stack SWORD_STACK = singleItemStack;

// SHOVEL
const itemtype SHOVEL = "SHOVEL";
const std::string SHOVEL_DESCRIPTION = "Tool used for digging in soil.";
const TextureLocalization SHOVEL_TEXTURE_LOCALIZATION = TextureLocalization(121, 63, "..\\Assets\\textures\\All tools mini-pack by SnowHex\\AllTools - SnowHex.png");
const stack SHOVEL_STACK = singleItemStack;

// PICKAXE
const itemtype PICKAXE = "PICKAXE";
const std::string PICKAXE_DESCRIPTION = "Used for chipping hard rock.";
const TextureLocalization PICKAXE_TEXTURE_LOCALIZATION = TextureLocalization(162, 63, "..\\Assets\\textures\\All tools mini-pack by SnowHex\\AllTools - SnowHex.png");
const stack PICKAXE_STACK = singleItemStack;

// AXE
const itemtype AXE = "AXE";
const std::string AXE_DESCRIPTION = "Obligatory for every lumberjack.";
const TextureLocalization AXE_TEXTURE_LOCALIZATION = TextureLocalization(199, 63, "..\\Assets\\textures\\All tools mini-pack by SnowHex\\AllTools - SnowHex.png");
const stack AXE_STACK = singleItemStack;

// SCYTHE
const itemtype SCYTHE = "SCYTHE";
const std::string SCYTHE_DESCRIPTION = "Is it harvest season yet?";
const TextureLocalization SCYTHE_TEXTURE_LOCALIZATION = TextureLocalization(238, 63, "..\\Assets\\textures\\All tools mini-pack by SnowHex\\AllTools - SnowHex.png");
const stack SCYTHE_STACK = singleItemStack;
