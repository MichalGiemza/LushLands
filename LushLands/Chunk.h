#pragma once
#include <map>
#include "Position.h"
#include "Entity.h"
#include "DataTypes.h"
#include "Logger.h"
#include "Ground.h"
#include "EntityFactory.h"
#include "Collider.h"
#include "CollisionManager.h"
#include "Animal.h"
#include "ChunkEvents.h"


class Chunk {
    /**
    * Klasa implementuj�ca chunki. Obiekty tej klasy reprezentuj� r�wnej wielko�ci obszary �wiata.
    * 
    * Ka�dy obiekt tej klasy zawiera w sobie zestaw swoich p�l, zestaw przebywaj�cych na terenie chunku mob�w
    * oraz collidery.
    */
private: 
    ChunkPosition chunkPosition;
    std::unordered_map<TilePosition, Entity *> groundTiles;
    std::unordered_map<TilePosition, Entity *> structures;
    std::unordered_map<TilePosition, Entity *> animals;
    EntityFactory *entityFactory;
    CollisionManager collisionManager;
    ChunkEvents chunkEvents;
    void generateTiles(ChunkPlan &chunkPlan);
    void generateStructures(ChunkPlan &chunkPlan);
    void generateAnimal(ChunkPlan &chunkPlan);
    Structure *addStructure(entitytype entityType, Position &position);
    Animal *addAnimal(entitytype entityType, Position &position);
public:
    Chunk(ChunkPosition chunkPosition, ChunkPlan &chunkPlan, EntityFactory *entityFactory);
    Entity *getGround(TilePosition &tilePosition);
    Entity *getStructure(TilePosition &tilePosition);
    ChunkEvents *getChunkEvents();
    CollisionManager *getCollisionManager();
    std::unordered_map<TilePosition, Entity *> *getGround();
    std::unordered_map<TilePosition, Entity *> *getStructures();
    ChunkPosition *getChunkPosition();
    int entitiesLoadedCount();
};

