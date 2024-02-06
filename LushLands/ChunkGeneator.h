#pragma once
#include "JsonHandler.h"
#include <BaseWorldPlanner.h>


class ChunkGenerator {
	/**
	* Passed to chunk as planning guide.
	*/
public:
	typedef entitytype(*entityTypeGetter)(ChunkGenerator *self, TilePosition &p);
	typedef entitytypeset(*entityTypeSetGetter)(ChunkGenerator *self, ChunkPosition &p);
private:
	BaseWorldPlanner *planner = 0;
	json *save = 0;

	entityTypeGetter getGround_ = 0;
	entityTypeGetter getStructure_ = 0;
	entityTypeSetGetter getAnimals_ = 0;
public:
	ChunkGenerator(BaseWorldPlanner *wp);
	ChunkGenerator(json *chunkData);

	entitytype getGround(TilePosition &p);
	entitytype getStructure(TilePosition &p);
	entitytypeset getAnimals(ChunkPosition &p);

	friend entitytype getGroundByPlanner(ChunkGenerator *self, TilePosition &p);
	friend entitytype getStructureByPlanner(ChunkGenerator *self, TilePosition &p);
	friend entitytypeset getAnimalsByPlanner(ChunkGenerator *self, ChunkPosition &p);

	friend entitytype getGroundBySave(ChunkGenerator *self, TilePosition &p);
	friend entitytype getStructureBySave(ChunkGenerator *self, TilePosition &p);
	friend entitytypeset getAnimalsBySave(ChunkGenerator *self, ChunkPosition &p);
};

entitytype getGroundByPlanner(ChunkGenerator *self, TilePosition &p);
entitytype getStructureByPlanner(ChunkGenerator *self, TilePosition &p);
entitytypeset getAnimalsByPlanner(ChunkGenerator *self, ChunkPosition &p);

// TODO: Implement loading from saves
entitytype getGroundBySave(ChunkGenerator *self, TilePosition &p);
entitytype getStructureBySave(ChunkGenerator *self, TilePosition &p);
entitytypeset getAnimalsBySave(ChunkGenerator *self, ChunkPosition &p);
