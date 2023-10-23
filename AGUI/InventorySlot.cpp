#include "InventorySlot.hpp"

agui::InventorySlot::InventorySlot() {
    setFontColor(UI_FG_COLOR);
    setBackColor(UI_BG_COLOR);
}

void agui::InventorySlot::paintComponent(const PaintEvent &paintEvent) {
}

void agui::InventorySlot::paintBackground(const PaintEvent &paintEvent) {
    
	Color color = getBackColor();

	switch (getButtonState()) {
	case HOVERED:
		color = Color(
			(float)(color.getR() + 0.075f),
			(float)(color.getG() + 0.075f),
			(float)(color.getB() + 0.075f),
			(float)(color.getA()));
		break;
	default:
		break;
	}

	paintEvent.graphics()->drawRoundedRectangle(
		getSizeRectangle(), iconSizePx, color, 2.0f);
	//ALLEGRO_BITMAP *itemTex = Texture ->getTexture(item->getType());
	//paintEvent.graphics()->drawImage()
    
}
