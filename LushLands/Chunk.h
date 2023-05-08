#pragma once
#include <map>
#include "Position.h"
#include "Entity.h"
#include "DataTypes.h"
#include "Logger.h"
#include "Ground.h"
#include "EntityFactory.h"
#include "ItemFactory.h"
#include "Collider.h"
#include "CollisionManager.h"
#include "Animal.h"
#include "ChunkElements.h"
#include "ChunkUpdater.h"


class Chunk {
    /**
    * Klasa implementuj�ca chunki. Obiekty tej klasy reprezentuj� r�wnej wielko�ci obszary �wiata.
    * 
    * Ka�dy obiekt tej klasy zawiera w sobie zestaw swoich p�l, zestaw przebywaj�cych na terenie chunku mob�w
    * oraz collidery.
    */
private: 
    ChunkElements ce;
    ChunkPosition chunkPosition;
    EntityFactory *entityFactory;
    ItemFactory *itemFactory;
    InputEvents *inputEvents;
    CollisionManager collisionManager;
    ChunkUpdater chunkUpdater;
private:
    void generateTiles(ChunkPlan &chunkPlan);
    void generateStructures(ChunkPlan &chunkPlan);
    void generateAnimals(ChunkPlan &chunkPlan);
    void generateItems(ChunkPlan &chunkPlan);
    Structure *addStructure(entitytype entityType, Position &position);
    Animal *addAnimal(entitytype entityType, Position &position);
public:
    Chunk(ChunkPosition chunkPosition, ChunkPlan &chunkPlan, EntityFactory *entityFactory, ItemFactory *itemFactory, InputEvents *inputEvents);
    void placeHumanoid(Humanoid *humanoid);
    void placeItem(Item *item);
    Entity *getGround(TilePosition &tilePosition);
    Entity *getStructure(TilePosition &tilePosition);
    std::vector<Entity *> getByPosition(Position *position);
    CollisionManager *getCollisionManager();
    ChunkElements *getChunkElements();
    ChunkPosition *getChunkPosition();
    int entitiesLoadedCount();
    void handleItemCollection();
};

