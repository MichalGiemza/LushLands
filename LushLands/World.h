#pragma once
#include <vector>
#include "Position.h"
#include "ChunkSystem.h"
#include "BaseWorldPlanner.h"
#include "DataTypes.h"
#include "ConstantSets.h"
#include "FlatlandWorldPlanner.h"
#include "WorldEvents.h"
#include "Logger.h"

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
    WorldEvents *worldEvents;
    Time *time;
    miliseconds lastTimeUpdated;
public:
    World(worldtype worldType, seed seed_, EntityFactory *entityFactory, EventHandler *eventHandler);
    void update();
    int getSeed();
    int getSeaLevel();
    Time *getWorldTime();
    ChunkLoadManager *getChunkLoadManager();
    std::vector<Entity *> getByPosition(Position position); // TODO: Dla klikania myszk¹
    void placePlayer(Entity *player, Position position);
};
