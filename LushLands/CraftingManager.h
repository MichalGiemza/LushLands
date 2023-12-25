#pragma once
#include "DataTypes.h"
#include "ConstantRepository.h"
#include "Directories.h"
#include "JsonHandler.h"
#include "CraftingStructures.h"
#include <map>
#include <set>


class CraftingManager {
    /** 
    * Manages crafting in game.
    * Factors for crafting:
    *  - Ingredients (specific items or general tags) and amounts
    *  - Time for crafting
    *  - Available technologies
    *  - Recipe category (ex. personal crafting, workbench, smelting, ...)
    */
    std::map<std::string, std::vector<Recipe>> recipes;
    std::vector<std::string> categories;
private:
    void loadRecipes();
    void loadRecipes(const fs::path fp, std::string category);
public:
    CraftingManager();
    std::vector<Recipe> *getRecipes(const std::string category);
    std::vector<std::string> *getCategories();
};

