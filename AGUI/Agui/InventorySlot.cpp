#include "InventorySlot.hpp"

agui::InventorySlot::InventorySlot() {
    setFontColor(UI_FG_COLOR);
    setBackColor(UI_BG_COLOR);
	setSize(36, 36);
	//int m = invSlotSizePx - iconSizePx;
	int m = 1;
	setMargins(m, m, m, m);
}

void agui::InventorySlot::paintComponent(const PaintEvent &paintEvent) {
	// TODO: Tutaj - rysowanie ikonek itemów 
	//ALLEGRO_BITMAP *itemTex = Texture ->getTexture(item->getType());
    //paintEvent.graphics()->drawImage()
}

void agui::InventorySlot::paintBackground(const PaintEvent &paintEvent) {

	paintEvent.graphics()->drawRoundedRectangle(
		getInnerRectangle(), roundingRadiusSmall, getFontColor(), 2.0f);

}
