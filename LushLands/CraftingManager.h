#pragma once
#include "DataTypes.h"
#include "ConstantRepository.h"
#include "Directories.h"
#include "JsonHandler.h"
#include "CraftingStructures.h"
#include "Inventory.h"
#include <map>
#include <set>
#include <ItemFactory.h>
#include <EventFactory.h>
#include "InputEvents.h"


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
    ItemFactory *itemFactory;
    InputEvents *inputEvents;
private:
    void loadRecipes();
    void loadRecipes(const fs::path fp, std::string category);
public:
    CraftingManager(ItemFactory *itemFactory, InputEvents *inputEvents);
    std::vector<Recipe> *getRecipes(const std::string category);
    std::vector<std::string> *getCategories();
    void applyCrafting(Recipe *recipe, Inventory *inventory, int amount = 1);
    static int maxCraftableAmount(Recipe *recipe, Inventory *inventory);

    friend void craft(ALLEGRO_EVENT *ae, void *cm);
};

void craft(ALLEGRO_EVENT *ae, void *cm);
