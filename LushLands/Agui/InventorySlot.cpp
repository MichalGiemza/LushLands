#include "InventorySlot.hpp"

agui::InventorySlot::InventorySlot() {
    setFontColor(UI_FG_COLOR);
    setBackColor(UI_HIGHLIGHT_COLOR);
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
	// Item icon
	Image *img = TextureManager::getImage((**slot).getType());
	paintEvent.graphics()->drawImage(img, Point(0, 0));
	// Item amount
	const int buffSize = 4;
	char buffer[buffSize];
	if ((**slot).getAmount() > 1) {
		sprintf_s(buffer, buffSize, "%3d", (**slot).getAmount());
		paintEvent.graphics()->drawText(agui::Point(amountX, amountY), buffer, COLOR_WHITE, Widget::getGlobalFont(), agui::ALIGN_RIGHT);
	}
}

void agui::InventorySlot::paintBackground(const PaintEvent &paintEvent) {
	// Background
	if (highlighted)
		paintEvent.graphics()->drawFilledRoundedRectangle(getInnerRectangle(), roundingRadiusSmall, getBackColor());
	// Frame
	paintEvent.graphics()->drawRoundedRectangle(
		getInnerRectangle(), roundingRadiusSmall, getFontColor(), 2.0f);
}

void agui::InventorySlot::setHighlight(bool status) {
	highlighted = status;
}
