#pragma once
#include "ChunkSystem.h"


class SavingManager {
    /** 
    * Used to manage savegames.
    */
    ChunkSystem *cs;
public:
    SavingManager(ChunkSystem *chunkSystem);
};

