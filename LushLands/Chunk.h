#pragma once
#include <map>
#include "Position.h"
#include "Entity.h"
#include "BaseWorldPlanner.h"


using namespace std;

class Chunk {
    /**
    * Klasa implementuj�ca chunki. Obiekty tej klasy reprezentuj� r�wnej wielko�ci obszary �wiata.
    * 
    * Ka�dy obiekt tej klasy zawiera w sobie zestaw swoich p�l, zestaw przebywaj�cych na terenie chunku mob�w
    * oraz collidery.
    */
private: 
    ChunkPosition chunkPosition;
    map<TilePosition, Entity> groundTiles;
    map<TilePosition, Entity> structures;

    //EventManagementSystem eventManagementSystem;
    //LooseEntityManager looseEntityManager;
    //RandomWalkManager randomWalkManager;
    //CollisionManager collisionManager;
    //PositionManager positionManager;
    //TileMovementManager tileMovementManager;

public:
    Entity getGround(TilePosition tilePosition);
    Entity getStructure(TilePosition tilePosition);
    void generateChunk(BaseWorldPlanner worldPlanner);
};

