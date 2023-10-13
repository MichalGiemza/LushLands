#pragma once
#include "stdafx.h"
#include "ConstantRepository.h"

struct CraftingIngredient {
    int amount;
    name ingredient;
    name ingredientType;
};

struct CraftingProduct {
    entitytype productType;
    int amount;
};

struct Recipe {
    CraftingIngredient *ingredients;
    int nIng;
    CraftingProduct product;
    miliseconds time;
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
    std::set<name> categories;
private:
    void loadRecipes();
    void loadRecipes(const fs::path fp, const name category);
public:
    CraftingManager();
    std::vector<Recipe> *getRecipes(const name category);
    std::set<name> *getCategories();
};

