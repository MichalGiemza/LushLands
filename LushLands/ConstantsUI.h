#pragma once
#include "Constants.h"

// General
const float roundingRadiusSmall = 4.0f;
const float roundingRadiusBig = 8.0f;
const float thinLineThickness = 2.0f;

// Console
const short CHAT_LENGTH = 16;
const int consoleWidth = 350;
const int consoleHeight = 400;
const bool consoleLogDebug = true;

// Crafting Menu
const int craftBtnW = (tileSizePx + 2) * 6 + 2;
const int craftBtnH = tileSizePx + 4;
const int craftMenuX = displayWidth * 2 / 5;
const int craftMenuY = 50;
const int craftMenuW = craftBtnW + 16;
const int craftMenuH = displayHeight * 3 / 4;

// Inventory
const int iconSizePx = 36;
const int invSlotSizePx = iconSizePx + 2;
const int amountPosX = 30;
const int amountPosY = 20;
