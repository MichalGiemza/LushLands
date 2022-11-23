#pragma once
#include <unordered_map>
#include "Chunk.h"
#include "BaseWorldPlanner.h"
#include "ChunkLoadManager.h"

class ChunkSystem {
    /** 
    * FIXME: Z tego co widzê, to bêdzie interfejs na zewn¹trz do zarz¹dzania wieloma narzêdziami i punkt zbieraj¹cy wsio w ca³oœæ.
    * 
    * Implementacja systemu zarz¹dzania chunkami. Pozwala na tworzenie i przechowywanie chunków.
    * 
    * Dziêki systemowi chunków mo¿liwe jest wczytywanie wybranych obszarów œwiata, na których znajduj¹ siê gracze oraz
    * tych, które z innych powodów powinny pozostaæ aktywne.
    */
    std::unordered_map<ChunkPosition, Chunk *> chunks;
    BaseWorldPlanner *worldPlanner;
    //EntityFactory entityFactory;
    ChunkLoadManager *chunkLoadManager;
public:
    ChunkSystem(BaseWorldPlanner *worldPlanner);
    Chunk *getChunk(ChunkPosition chunkPosition);
    ChunkLoadManager *getChunkLoadManager();
     
};
