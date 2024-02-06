#include "ChunkGeneator.h"

ChunkGenerator::ChunkGenerator(BaseWorldPlanner *wp) : planner(wp) {
    getGround_ = getGroundByPlanner;
    getStructure_ = getStructureByPlanner;
    getAnimals_ = getAnimalsByPlanner;
}

ChunkGenerator::ChunkGenerator(json *chunkData) : save(chunkData) {
    getGround_ = getGroundBySave;
    getStructure_ = getStructureBySave;
    getAnimals_ = getAnimalsBySave;
}

entitytype ChunkGenerator::getGround(TilePosition &p) {
    return getGround_(this, p);
}

entitytype ChunkGenerator::getStructure(TilePosition &p) {
    return getStructure_(this, p);
}

entitytypeset ChunkGenerator::getAnimals(ChunkPosition &p) {
    return getAnimals_(this, p);
}

entitytype getGroundByPlanner(ChunkGenerator *self, TilePosition &p) {
    return self->planner->getGround(p);
}

entitytype getStructureByPlanner(ChunkGenerator *self, TilePosition &p) {
    return self->planner->getStructure(p);
}

entitytypeset getAnimalsByPlanner(ChunkGenerator *self, ChunkPosition &p) {
    return self->planner->getAnimals(p);
}

entitytype getGroundBySave(ChunkGenerator *self, TilePosition &p) {
    return entitytype();  // TODO
}

entitytype getStructureBySave(ChunkGenerator *self, TilePosition &p) {
    return entitytype();  // TODO
}

entitytypeset getAnimalsBySave(ChunkGenerator *self, ChunkPosition &p) {
    return entitytypeset();  // TODO
}
