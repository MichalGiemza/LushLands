#pragma once
#include <map>
#include "Position.h"
#include "Entity.h"
#include "DataTypes.h"
#include "Logger.h"
#include "Ground.h"
#include "EntityFactory.h"
#include "Collider.h"


class Chunk {
    /**
    * Klasa implementuj¹ca chunki. Obiekty tej klasy reprezentuj¹ równej wielkoœci obszary œwiata.
    * 
    * Ka¿dy obiekt tej klasy zawiera w sobie zestaw swoich pól, zestaw przebywaj¹cych na terenie chunku mobów
    * oraz collidery.
    */
private: 
    ChunkPosition chunkPosition;
    std::unordered_map<TilePosition, Entity *> groundTiles;
    std::unordered_map<TilePosition, Entity *> structures;
    EntityFactory *entityFactory;
    std::unordered_set<Collider *> colliders;
    //EventManagementSystem eventManagementSystem;
    //LooseEntityManager looseEntityManager;
    //RandomWalkManager randomWalkManager;
    //CollisionManager collisionManager;
    //PositionManager positionManager;
    //TileMovementManager tileMovementManager;
    void generateTiles(ChunkPlan &chunkPlan);
    void generateStructures(ChunkPlan &chunkPlan);
    Structure *addStructure(entitytype entityType, Position &position);
public:
    Chunk(ChunkPosition chunkPosition, ChunkPlan &chunkPlan, EntityFactory *entityFactory);
    Entity *getGround(TilePosition &tilePosition);
    Entity *getStructure(TilePosition &tilePosition);
    std::unordered_set<Collider *> *getColliders();
    std::unordered_map<TilePosition, Entity *> *getGround();
    std::unordered_map<TilePosition, Entity *> *getStructures();
    ChunkPosition *getChunkPosition();
    int entitiesLoadedCount();
};

