#pragma once

// Simulation
const int TicksPerSecond = 24;
const int FramesPerSecond = 60;
const int maxMilisecondsPerTick = 1000;
//const int itemCollectionEveryNTick = 4; // TODO
const int interactionRadiusS = 1;
const int interactionRadiusL = 8;

// World
const long long worldHeight = 64;
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

