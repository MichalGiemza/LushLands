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
    * Klasa reprezentuj¹ca œwiat gry.
    * 
    * Wymaga utworzenia instancji, w przysz³oœci bêd¹ mog³y istnieæ dodatkowe œwiaty w ramach jednego zapisu,
    * np. powierzchnia, podziemia. O ile zostanie to zaimplementowane w ten w³aœnie sposób.
    * 
    * Uwagi:
    *  - Nie mo¿na tu dodawaæ systemu eventów, stworzy to oddzieln¹ pulê eventów (niezale¿n¹ od chunkowej).
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
    std::vector<Entity *> getByPosition(Position *position); // TODO: Dla klikania myszk¹
    void placePlayer(Player *player);
    void placeItem(Item *item);
    friend void updateTime(ALLEGRO_EVENT *allegroEvent, void *obj);
};

void updateTime(ALLEGRO_EVENT *allegroEvent, void *obj);
