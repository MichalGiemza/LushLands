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
    * Klasa reprezentuj�ca �wiat gry.
    * 
    * Wymaga utworzenia instancji, w przysz�o�ci b�d� mog�y istnie� dodatkowe �wiaty w ramach jednego zapisu,
    * np. powierzchnia, podziemia. O ile zostanie to zaimplementowane w ten w�a�nie spos�b.
    * 
    * Uwagi:
    *  - Nie mo�na tu dodawa� systemu event�w, stworzy to oddzieln� pul� event�w (niezale�n� od chunkowej).
    */
    int seed;
    BaseWorldPlanner worldPlanner;
    ChunkSystem chunkSystem;
    ControlManager controlManager;  // FIXME: Sterowanie za pomoc� inputu, czy to b�dzie tutaj?
public:
    World(string worldType, int seed, ControlManager controlManager);
    int getSeed();
    vector<Entity> getByPosition(Position position);
    void addPlayer(Entity player, Position position);
};
