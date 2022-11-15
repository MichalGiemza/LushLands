#pragma once
#include <map>
#include "Chunk.h"
#include "BaseWorldPlanner.h"

using namespace std;

class ChunkSystem {
    /** 
    * Implementacja systemu zarz¹dzania chunkami. Pozwala na tworzenie i przechowywanie chunków.
    * 
    * Dziêki systemowi chunków mo¿liwe jest wczytywanie wybranych obszarów œwiata, na których znajduj¹ siê gracze oraz
    * tych, które z innych powodów powinny pozostaæ aktywne.
    */
private:
    map<ChunkPosition, Chunk> chunks;
public:
    //ChunkSystem(BaseWorldPlanner worldPlanner, EntityFactory entityFactory);
    Chunk getChunk(ChunkPosition chunkPosition);
    void generateChunk(ChunkPosition chunkPosition);
};
