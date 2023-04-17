#include "ItemFactory.h"

ItemFactory::ItemFactory() {
}

Item *ItemFactory::buildItem(itemtype itemType, stack amount) {
	if (itemType == 0) 
		return 0;
	/*    Resources    */
	if (itemType == WOOD)
		return new Item(WOOD, WOOD_DESCRIPTION, WOOD_STACK, amount);
	if (itemType == PLANK)
		return new Item(PLANK, PLANK_DESCRIPTION, PLANK_STACK, amount);
	if (itemType == BRANCH)
		return new Item(BRANCH, BRANCH_DESCRIPTION, BRANCH_STACK, amount);
	/*    Animal Loot    */
	if (itemType == MEAT)
		return new Item(MEAT, MEAT_DESCRIPTION, MEAT_STACK, amount);
	if (itemType == FEATHER)
		return new Item(FEATHER, FEATHER_DESCRIPTION, FEATHER_STACK, amount);
	/*    Tools    */
	if (itemType == SWORD)
		return new Item(SWORD, SWORD_DESCRIPTION, SWORD_STACK, amount, tlt::weapon); //TODO: Przerobic constanty na baze/plik config
	if (itemType == SHOVEL)
		return new Item(SHOVEL, SHOVEL_DESCRIPTION, SHOVEL_STACK, amount, tlt::shovel);
	if (itemType == PICKAXE)
		return new Item(PICKAXE, PICKAXE_DESCRIPTION, PICKAXE_STACK, amount, tlt::pickaxe);
	if (itemType == AXE)
		return new Item(AXE, AXE_DESCRIPTION, AXE_STACK, amount, tlt::axe);
	if (itemType == SCYTHE)
		return new Item(SCYTHE, SCYTHE_DESCRIPTION, SCYTHE_STACK, amount, tlt::harvesting);
}

Item *ItemFactory::buildItem(ItemDropChance &idc) {
	stack amount = std::min(idc.chanceGuaranteed, Random_::random(idc.chanceLow, idc.chanceHigh));
	return buildItem(idc.item, amount);
}
