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
    auto d = JsonHandler::parseJson(fp);

    auto &ig = d.at("Ingredients");
    auto &pd = d.at("Product");

    CraftingIngredient *cis = new CraftingIngredient[ig.size()];
    for (int i = 0; i < ig.size(); i++) {
        auto &in = ig[i];
        // General Crafting Ingredient 
        if (in.contains("General")) {
            cis[i].ingredient = CR::selectTag(a_s(in, "General"));
            cis[i].amount = in.at("Amount");
            cis[i].ingredientType = igt::general;
        }
        // Specific Crafting Ingredient 
        if (in.contains("Specific")) {
            cis[i].ingredient = CR::selectEntityType(a_s(in, "Specific"));
            cis[i].amount = in.at("Amount");
            cis[i].ingredientType = igt::specific;
        }
    }

    auto *cpd = new CraftingProduct();
    cpd->productType = CR::selectEntityType(a_s(pd, "EntityType"));
    cpd->amount = pd.at("Amount");

    miliseconds tm = d.at("Time");
    
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

CraftingManager::CraftingManager(ItemFactory *itemFactory, InputEvents *inputEvents) : 
    itemFactory(itemFactory), inputEvents(inputEvents) {
    loadRecipes();
    inputEvents->subscribeSystemEvent(item_craft, craft, this);
}

std::vector<Recipe> *CraftingManager::getRecipes(const std::string category) {
    return &recipes[category];
}

std::vector<std::string> *CraftingManager::getCategories() {
    return &categories;
}

void CraftingManager::applyCrafting(Recipe *rcp, Inventory *inv, int n) {
    n = std::min(n, maxCraftableAmount(rcp, inv));
    // Take ingredients
    for (int i = 0; i < rcp->nIng; i++) {
        CraftingIngredient *ing = &rcp->ingredients[i];
        inv->takeItemAuto(ing->ingredient, ing->amount * n);
    }
    // Put products
    Item *prod = itemFactory->buildItem(rcp->product.productType, rcp->product.amount * n, inv->getPosition());
    inv->putItemAuto(prod);
}

int CraftingManager::maxCraftableAmount(Recipe *r, Inventory *inv) {
    int maxCraft = INT32_MAX;
    for (int i = 0; i < r->nIng; i++) {
        // Per ingredient
        auto ing = r->ingredients[i];
        int maxCurr = 0;
        if (ing.ingredientType == igt::specific)
            maxCurr = inv->getItemCount(ing.ingredient) / ing.amount;
        if (ing.ingredientType == igt::general)
            maxCurr = inv->getItemCount(ing.ingredient) / ing.amount; // TODO: General types - not working yet
        maxCraft = std::min(maxCraft, maxCurr);
    }
    return maxCraft;
}

void craft(ALLEGRO_EVENT *ae, void *cm) {
    CraftingManager *crm = (CraftingManager *)cm;
    Inventory *inv = 0;
    Recipe *rcp = 0;
    int amount = 1; // TODO: Craft whole stack with [Shift]
    EventFactory::unpackItemCraft(ae, (void **)&inv, (void **)&rcp);
    crm->applyCrafting(rcp, inv, amount);
}
