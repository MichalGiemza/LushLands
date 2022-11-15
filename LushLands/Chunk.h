#pragma once
#include <map>
#include "Position.h"
#include "Entity.h"
#include "BaseWorldPlanner.h"


using namespace std;

class Chunk {
    /**
    * Klasa implementuj¹ca chunki. Obiekty tej klasy reprezentuj¹ równej wielkoœci obszary œwiata.
    * 
    * Ka¿dy obiekt tej klasy zawiera w sobie zestaw swoich pól, zestaw przebywaj¹cych na terenie chunku mobów
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

