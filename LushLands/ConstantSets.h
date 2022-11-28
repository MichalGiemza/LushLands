#pragma once
#include "Color.h"

// World types
const worldtype FLATLAND = "flatland";

// Action codes
const actioncode GO_NORTH = "go_north";
const actioncode GO_SOUTH = "go_south";
const actioncode GO_WEST = "go_west";
const actioncode GO_EAST = "go_east";
const actioncode USE = "use";

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
// Entity types (animals)

// Texture names (ground)
const texturename SOIL_TEXTURE = "soil_tex";
const texturename GRASS_TEXTURE = "grass_tex";
const texturename WATER_TEXTURE = "water_tex";
const texturename SAND_TEXTURE = "sand_tex";
const texturename ROCK_TEXTURE = "rock_tex";
const texturename COBBLE_TEXTURE = "cobble_tex";
const texturename FARMLAND_TEXTURE = "farmland_tex";
const texturename GRAVEL_TEXTURE = "gravel_tex";
const texturename SNOW_TEXTURE = "snow_tex";

// Texture names (structures)
// Texture names (animals)


// Colors (ground)
const Color SOIL_COLOR = Color(100, 60, 20, 255);
const Color GRASS_COLOR = Color(80, 100, 50, 255);
const Color WATER_COLOR = Color(15, 50, 100, 255);
const Color SAND_COLOR = Color(200, 200, 110, 255);
const Color ROCK_COLOR = Color(120, 120, 120, 255);
const Color COBBLE_COLOR = Color(80, 80, 80, 255);
const Color FARMLAND_COLOR = Color(60, 40, 20, 255);
const Color GRAVEL_COLOR = Color(80, 80, 100, 255);
const Color SNOW_COLOR = Color(240, 240, 250, 255);

// Colors (structures)
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
// Descriptions (animals)
