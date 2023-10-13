#pragma once
#include "stdafx.h"


class BaseWorldPlanner {
    /** 
    * Obiekty tej klasy odpowiedzialne s¹ za planowanie generowania œwiata gry.
    * 
    * Planowanie œwiata musi odbywaæ siê w sposób deterministyczny. 
    */
public:
    virtual FieldPlan getFieldPlan(Position position) = 0;
    virtual int getSeaLevel() = 0;
    ChunkPlan *getChunkPlan(ChunkPosition &chunkPosition);
};
