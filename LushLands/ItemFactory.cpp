#include "ItemFactory.h"

ItemFactory::ItemFactory() {
}

Item *ItemFactory::buildItem(itemtype itemType) {
	if (itemType == 0) 
		return 0;
	/*    Resources    */
	if (itemType == WOOD)
		return new Item(WOOD, WOOD_DESCRIPTION);
	if (itemType == PLANK)
		return new Item(PLANK, PLANK_DESCRIPTION);
	if (itemType == BRANCH)
		return new Item(BRANCH, BRANCH_DESCRIPTION);
	/*    Animal Loot    */
	if (itemType == MEAT)
		return new Item(MEAT, MEAT_DESCRIPTION);
	if (itemType == FEATHER)
		return new Item(FEATHER, FEATHER_DESCRIPTION);
}
