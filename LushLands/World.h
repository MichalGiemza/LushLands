#pragma once
#include <vector>
#include "Position.h"
#include "ChunkSystem.h"
#include "BaseWorldPlanner.h"
#include "Entity.h"
#include "ControlManager.h"

using namespace std;

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
    int seed;
    BaseWorldPlanner worldPlanner;
    ChunkSystem chunkSystem;
    ControlManager controlManager;  // FIXME: Sterowanie za pomoc¹ inputu, czy to bêdzie tutaj?
public:
    World(string worldType, int seed, ControlManager controlManager);
    int getSeed();
    vector<Entity> getByPosition(Position position);
    void addPlayer(Entity player, Position position);
};
