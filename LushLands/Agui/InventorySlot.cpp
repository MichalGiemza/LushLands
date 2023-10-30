#include "InventorySlot.hpp"

agui::InventorySlot::InventorySlot() {
    setFontColor(UI_FG_COLOR);
    setBackColor(UI_BG_COLOR);
	setSize(36, 36);
	int m = 1;
	setMargins(m, m, m, m);
}

void agui::InventorySlot::setItemSlot(Item **s) {
	slot = s;
}

void agui::InventorySlot::paintComponent(const PaintEvent &paintEvent) {
	if (slot == 0 or *slot == 0)
		return;
	Image *img = TextureManager::getImage((**slot).getType());
	paintEvent.graphics()->drawImage(img, Point(0, 0));
}

void agui::InventorySlot::paintBackground(const PaintEvent &paintEvent) {

	paintEvent.graphics()->drawRoundedRectangle(
		getInnerRectangle(), roundingRadiusSmall, getFontColor(), 2.0f);

}
