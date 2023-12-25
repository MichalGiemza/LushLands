#pragma once
#include "DataTypes.h"


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
