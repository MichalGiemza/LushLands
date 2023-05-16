#include "ItemFactory.h"

ItemFactory::ItemFactory() {
}

Item *ItemFactory::buildItem(itemtype itemType, stack amount) {
	if (itemType == 0) 
		return 0;
	/*    Resources    */
	if (itemType == i::WOOD)
		return new Item(i::WOOD, i::WOOD_DESCRIPTION, i::WOOD_STACK, amount);
	if (itemType == i::PLANK)
		return new Item(i::PLANK, i::PLANK_DESCRIPTION, i::PLANK_STACK, amount);
	if (itemType == i::BRANCH)
		return new Item(i::BRANCH, i::BRANCH_DESCRIPTION, i::BRANCH_STACK, amount);
	/*    Animal Loot    */
	if (itemType == i::MEAT)
		return new Item(i::MEAT, i::MEAT_DESCRIPTION, i::MEAT_STACK, amount);
	if (itemType == i::FEATHER)
		return new Item(i::FEATHER, i::FEATHER_DESCRIPTION, i::FEATHER_STACK, amount);
	/*    Tools    */
	if (itemType == i::SWORD)
		return new Item(i::SWORD, i::SWORD_DESCRIPTION, i::SWORD_STACK, amount, tlt::weapon); //TODO: Przerobic constanty na baze/plik config
	if (itemType == i::SHOVEL)
		return new Item(i::SHOVEL, i::SHOVEL_DESCRIPTION, i::SHOVEL_STACK, amount, tlt::shovel);
	if (itemType == i::PICKAXE)
		return new Item(i::PICKAXE, i::PICKAXE_DESCRIPTION, i::PICKAXE_STACK, amount, tlt::pickaxe);
	if (itemType == i::AXE)
		return new Item(i::AXE, i::AXE_DESCRIPTION, i::AXE_STACK, amount, tlt::axe);
	if (itemType == i::SCYTHE)
		return new Item(i::SCYTHE, i::SCYTHE_DESCRIPTION, i::SCYTHE_STACK, amount, tlt::harvesting);
}

Item *ItemFactory::buildItem(ItemDropChance &idc) {
	stack amount = std::min(idc.chanceGuaranteed, Random_::random(idc.chanceLow, idc.chanceHigh));
	return buildItem(idc.item, amount);
}
