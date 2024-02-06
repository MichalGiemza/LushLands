#pragma once
#include "Position.h"


typedef std::vector < std::pair<entitytype, Position> > entitytypeset;

class BaseWorldPlanner {
    /** 
    * Obiekty tej klasy odpowiedzialne s¹ za planowanie generowania œwiata gry.
    * 
    * Planowanie œwiata musi odbywaæ siê w sposób deterministyczny. 
    */
public:
    virtual int getSeaLevel() = 0;
    virtual entitytype getGround(TilePosition &p) = 0;
    virtual entitytype getStructure(TilePosition &p) = 0;
    virtual entitytypeset getAnimals(ChunkPosition &p) = 0;
};
