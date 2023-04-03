#pragma once
#include <cmath>

// Simulation
const int TicksPerSecond = 24;
const int FramesPerSecond = 60;
const int maxMilisecondsPerTick = 1000;
const int itemCollectionEveryNTick = 4;

// World
const long long worldHeight = 64;
const unsigned char maxStack = UCHAR_MAX;
const unsigned char singleItemStack = 1;
const long long collisionEpsilon = 10000;
const int itemMagnetRadius = 1;

// Chunks
const int chunkSizeByTiles = 32;
const int chunkRenderDistance = 2;

// System
const long long representationComaValue = 100000;
const long long meter = representationComaValue;
const int tileSizePx = 32;
const int displayWidth = 1280;
const int displayHeight = 720;
const bool DEBUG = true;
const float PI = 3.14159265F;

// UI
const short CHAT_LENGTH = 16;
const int inventoryWidth = 12;
const float roundingRadiusSmall = 4.0f;
const float roundingRadiusBig = 8.0f;
