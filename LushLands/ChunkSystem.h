#pragma once
#include <map>
#include "Chunk.h"
#include "BaseWorldPlanner.h"

using namespace std;

class ChunkSystem {
    /** 
    * Implementacja systemu zarz�dzania chunkami. Pozwala na tworzenie i przechowywanie chunk�w.
    * 
    * Dzi�ki systemowi chunk�w mo�liwe jest wczytywanie wybranych obszar�w �wiata, na kt�rych znajduj� si� gracze oraz
    * tych, kt�re z innych powod�w powinny pozosta� aktywne.
    */
private:
    map<ChunkPosition, Chunk> chunks;
public:
    //ChunkSystem(BaseWorldPlanner worldPlanner, EntityFactory entityFactory);
    Chunk getChunk(ChunkPosition chunkPosition);
    void generateChunk(ChunkPosition chunkPosition);
};
