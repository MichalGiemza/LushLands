#pragma once
#include <unordered_map>
#include "Chunk.h"
#include "BaseWorldPlanner.h"
#include "ChunkLoadManager.h"

class ChunkSystem {
    /** 
    * FIXME: Z tego co widz�, to b�dzie interfejs na zewn�trz do zarz�dzania wieloma narz�dziami i punkt zbieraj�cy wsio w ca�o��.
    * 
    * Implementacja systemu zarz�dzania chunkami. Pozwala na tworzenie i przechowywanie chunk�w.
    * 
    * Dzi�ki systemowi chunk�w mo�liwe jest wczytywanie wybranych obszar�w �wiata, na kt�rych znajduj� si� gracze oraz
    * tych, kt�re z innych powod�w powinny pozosta� aktywne.
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
