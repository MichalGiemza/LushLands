#pragma once
#include <vector>
#include "Position.h"
#include "ChunkSystem.h"
#include "BaseWorldPlanner.h"
#include "DataTypes.h"
#include "ConstantSets.h"
#include "FlatlandWorldPlanner.h"

class World {
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
public:
    World(worldtype worldType, seed seed_, EntityFactory *entityFactory);
    int getSeed();
    std::vector<Entity *> getByPosition(Position position);
    void placePlayer(Entity *player, Position position);
    int getSeaLevel();
    ChunkLoadManager *getChunkLoadManager();
};
