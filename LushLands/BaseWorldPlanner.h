#pragma once
#include "stdafx.h"


class BaseWorldPlanner {
    /** 
    * Obiekty tej klasy odpowiedzialne s� za planowanie generowania �wiata gry.
    * 
    * Planowanie �wiata musi odbywa� si� w spos�b deterministyczny. 
    */
public:
    virtual FieldPlan getFieldPlan(Position position) = 0;
    virtual int getSeaLevel() = 0;
    ChunkPlan *getChunkPlan(ChunkPosition &chunkPosition);
};
