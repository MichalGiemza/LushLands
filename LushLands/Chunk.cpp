#include "Chunk.h"

void Chunk::generateTiles(ChunkPlan &chunkPlan) {
    auto referencePosition = Position(chunkPosition);
    auto pos = Position(referencePosition);

    for (int i = 0; i < chunkSizeByTiles; i++) {
        for (int j = 0; j < chunkSizeByTiles; j++) {
            for (int k = 0; k < worldHeight; k++) {
                pos.setX(referencePosition.getX() + i);
                pos.setZ(referencePosition.getZ() + j);
                pos.setY(referencePosition.getY() + k);
                auto plannedEntityType = chunkPlan.fieldPlans[i][j][k].ground;
                Ground *ground = (Ground *)entityFactory->buildEntity(plannedEntityType, pos);
                if (ground == 0)
                    continue;
                //randomTickEntities.insert((Entity *)ground); // Fixme: Przywróciæ metodê przydzielaj¹c¹!
                groundTiles[pos.getTilePosition()] = ground;
            }
        }
    }
}

void Chunk::generateStructures(ChunkPlan &chunkPlan) {
    auto referencePosition = Position(chunkPosition);
    auto pos = Position(referencePosition);

    for (int i = 0; i < chunkSizeByTiles; i++) {
        for (int j = 0; j < chunkSizeByTiles; j++) {
            for (int k = 0; k < worldHeight; k++) {
                pos.setPX(referencePosition.getPX() + i * meter + meter / 2);
                pos.setPZ(referencePosition.getPZ() + j * meter + meter / 2);
                pos.setPY(referencePosition.getPY() + k * meter);
                auto plannedEntityType = chunkPlan.fieldPlans[i][j][k].structure;
                auto structure = addStructure(plannedEntityType, pos);
                if (structure == 0)
                    continue;
                randomTickEntities.insert((Entity *)structure); // Fixme: Przywróciæ metodê przydzielaj¹c¹!
                structures[pos.getTilePosition()] = structure;
            }
        }
    }
}

Structure *Chunk::addStructure(entitytype entityType, Position &position) {
    Structure *structure = (Structure *)entityFactory->buildEntity(entityType, position);
    if (structure == 0)
        return 0;
    collisionManager.addCollider(structure->getCollider());
    return structure;
}

void Chunk::generateAnimals(ChunkPlan &chunkPlan) {
    auto referencePosition = Position(chunkPosition);
    auto pos = Position(referencePosition);

    for (int i = 0; i < chunkSizeByTiles; i++) {
        for (int j = 0; j < chunkSizeByTiles; j++) {
            for (int k = 0; k < worldHeight; k++) {
                pos.setPX(referencePosition.getPX() + i * meter + meter / 2);
                pos.setPZ(referencePosition.getPZ() + j * meter + meter / 2);
                pos.setPY(referencePosition.getPY() + k * meter);
                auto plannedEntityType = chunkPlan.fieldPlans[i][j][k].animal;
                Animal *animal = addAnimal(plannedEntityType, pos);
                if (animal == 0)
                    continue;
                animals.insert(animal);
                toUpdateEntities.insert(animal->getEntityUpdater()); // Fixme: Przywróciæ metodê przydzielaj¹c¹!
            }
        }
    }
}

void Chunk::generateItems(ChunkPlan &chunkPlan) {
    auto referencePosition = Position(chunkPosition);
    auto pos = Position(referencePosition);

    for (int i = 0; i < chunkSizeByTiles; i++) {
        for (int j = 0; j < chunkSizeByTiles; j++) {
            for (int k = 0; k < worldHeight; k++) {
                pos.setPX(referencePosition.getPX() + i * meter + meter / 2);
                pos.setPZ(referencePosition.getPZ() + j * meter + meter / 2);
                pos.setPY(referencePosition.getPY() + k * meter);
                auto plannedItemType = chunkPlan.fieldPlans[i][j][k].item;
                auto plannedItemAmount = chunkPlan.fieldPlans[i][j][k].itemAmount;
                if (not plannedItemType)
                    continue;
                Item *item = itemFactory->buildItem(plannedItemType, plannedItemAmount);
                item->getPosition()->updatePosition(pos);
                items.insert(item);
            }
        }
    }
}

Animal *Chunk::addAnimal(entitytype entityType, Position &position) {
    Animal *animal = (Animal *)entityFactory->buildEntity(entityType, position);
    if (animal == 0)
        return 0;
    collisionManager.addCollider(animal->getCollider());
    animal->getEntityUpdater()->registerParentEventSource(chunkEvents.getEventSource());
    return animal;
}

void Chunk::placeHumanoid(Humanoid *humanoid) {
    humanoids.insert(humanoid);
    humanoid->getEntityUpdater()->registerParentEventSource(chunkEvents.getEventSource());
    collisionManager.addCollider(humanoid->getCollider());
}

Chunk::Chunk(ChunkPosition chunkPosition, ChunkPlan &chunkPlan, EntityFactory *entityFactory, ItemFactory *itemFactory) :
    collisionManager(), itemFactory(itemFactory), entityFactory(entityFactory), chunkPosition(chunkPosition),
    chunkEvents(&chunkPosition, &collisionManager, &randomTickEntities, &toUpdateEntities) {
    // Entities and Items
    generateTiles(chunkPlan);
    generateStructures(chunkPlan);
    generateAnimals(chunkPlan);
    generateItems(chunkPlan);

    Logger::log(lg::DEBUG_CHUNK, "Created Chunk [%i, %i]", chunkPosition.x, chunkPosition.z);
}

Entity *Chunk::getGround(TilePosition &tilePosition) {
    return groundTiles[tilePosition];
}

Entity *Chunk::getStructure(TilePosition &tilePosition) {
    return structures[tilePosition];
}

ChunkEvents *Chunk::getChunkEvents() {
    return &chunkEvents;
}

CollisionManager *Chunk::getCollisionManager() {
    return &collisionManager;
}

std::unordered_map<TilePosition, Entity *> *Chunk::getGround() {
    return &groundTiles;
}

std::unordered_set<Item *> *Chunk::getItems() {
    return &items;
}

std::unordered_map<TilePosition, Entity *> *Chunk::getStructures() {
    return &structures;
}

std::unordered_set<Entity *> *Chunk::getAnimals() {
    return &animals;
}

std::unordered_set<Entity *> *Chunk::getHumanoids() {
    return &humanoids;
}

ChunkPosition *Chunk::getChunkPosition() {
    return &chunkPosition;
}

int Chunk::entitiesLoadedCount() {
    return groundTiles.size() + structures.size();
}

