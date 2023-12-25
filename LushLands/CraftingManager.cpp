#include "CraftingManager.h"

void CraftingManager::loadRecipes() {
    // Personal
    auto categoriesDirs = Directories::listDir(recipesDir);
    for (auto &category : categoriesDirs) {
        auto filesD = Directories::listDir(category.path());
        for (auto &fp : filesD)
            loadRecipes(fp.path(), category.path().filename().string().c_str()); // TODO
    }
}

void CraftingManager::loadRecipes(const fs::path fp, std::string category) {
    auto data = JsonHandler::parseJson(fp);
    auto &d = data->as_object();

    auto &ig = d.at("Ingredients").as_array();
    auto &pd = d.at("Product").as_object();

    CraftingIngredient *cis = new CraftingIngredient[ig.size()];
    for (int i = 0; i < ig.size(); i++) {
        auto &in = ig[i].as_object();
        // General Crafting Ingredient 
        if (in.contains("General")) {
            cis[i].ingredient = CR::selectTag(a_s(in, "General"));
            cis[i].amount = in.at("Amount").as_int64();
            cis[i].ingredientType = igt::general;
        }
        // Specific Crafting Ingredient 
        if (in.contains("Specific")) {
            cis[i].ingredient = CR::selectEntityType(a_s(in, "Specific"));
            cis[i].amount = in.at("Amount").as_int64();
            cis[i].ingredientType = igt::specific;
        }
    }

    auto *cpd = new CraftingProduct();
    cpd->productType = CR::selectEntityType(a_s(pd, "EntityType"));
    cpd->amount = pd.at("Amount").as_int64();

    miliseconds tm = d.at("Time").as_int64();
    
    Recipe *recipe = new Recipe {
        cis,
        (int)ig.size(),
        *cpd,
        tm
    };

    // Add Recipe
    recipes[category].push_back(*recipe);
    // Add category
    auto it = std::find(categories.begin(), categories.end(), category);
    if (it == categories.end())
        categories.push_back(category);
}

CraftingManager::CraftingManager() {
    loadRecipes();
}

std::vector<Recipe> *CraftingManager::getRecipes(const std::string category) {
    return &recipes[category];
}

std::vector<std::string> *CraftingManager::getCategories() {
    return &categories;
}
