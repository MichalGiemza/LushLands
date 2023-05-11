#pragma once
#include <vector>
#include "Position.h"
#include "ChunkSystem.h"
#include "BaseWorldPlanner.h"
#include "DataTypes.h"
#include "ConstantSets.h"
#include "FlatlandWorldPlanner.h"
#include "ChickenBoxWorldPlanner.h"
#include "Logger.h"
#include "Player.h"
#include "ItemFactory.h"

class World  {
    /** 
    * Klasa reprezentuj�ca �wiat gry.
    * 
    * Wymaga utworzenia instancji, w przysz�o�ci b�d� mog�y istnie� dodatkowe �wiaty w ramach jednego zapisu,
    * np. powierzchnia, podziemia. O ile zostanie to zaimplementowane w ten w�a�nie spos�b.
    * 
    * Uwagi:
    *  - Nie mo�na tu dodawa� systemu event�w, stworzy to oddzieln� pul� event�w (niezale�n� od chunkowej).
    */
    int seed_;
    BaseWorldPlanner *worldPlanner;
    ChunkSystem *chunkSystem;
    worldtype worldType;
    EntityFactory *entityFactory;
    ItemFactory *itemFactory;
    Time *time;
    miliseconds sessionActiveSince;
    miliseconds lastTimeUpdated;
    InputEvents *inputEvents;
public:
    World(worldtype worldType, int seed_, EntityFactory *entityFactory, ItemFactory *itemFactory, InputEvents *inputEvents);
    int getSeed();
    int getSeaLevel();
    Time *getWorldTime();
    ChunkLoadManager *getChunkLoadManager();
    std::vector<Entity *> getByPosition(Position *position); // TODO: Dla klikania myszk�
    void placePlayer(Player *player);
    void placeItem(Item *item);
    friend void updateTime(ALLEGRO_EVENT *allegroEvent, void *obj);
};

void updateTime(ALLEGRO_EVENT *allegroEvent, void *obj);
