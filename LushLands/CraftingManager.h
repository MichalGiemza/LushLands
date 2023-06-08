#pragma once
#include "DataTypes.h"
#include "Directories.h"
#include "JsonHandler.h"
#include "ConstantRepository.h"
#include <map>
#include <vector>

struct CraftingIngredient {
    int amount;
    name ingredient;
    name ingredientType;
};

struct CraftingProduct {
    entitytype product;
    int amount;
};

struct Recipe {
    CraftingIngredient *ingredients;
    CraftingProduct product;
};

class CraftingManager {
    /** 
    * Manages crafting in game.
    * Factors for crafting:
    *  - Ingredients (specific items or general tags) and amounts
    *  - Time for crafting
    *  - Available technologies
    *  - Recipe category (ex. personal crafting, workbench, smelting, ...)
    */
    std::map<name, std::vector<Recipe>> recipes;
private:
    void loadRecipes();
    void loadRecipes(const fs::path fp, const name category);
public:
    std::vector<Recipe> *getRecipes(const name category);
};

