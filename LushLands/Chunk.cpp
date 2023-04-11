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
                //randomTickEntities.insert((Entity *)ground); // Fixme: Przywr�ci� metod� przydzielaj�c�!
                ce.groundTiles[pos.getTilePosition()] = ground;
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
                randomTickEntities.insert((Entity *)structure); // Fixme: Przywr�ci� metod� przydzielaj�c�!
                ce.structures[pos.getTilePosition()] = structure;
            }
        }
    }
}

Structure *Chunk::addStructure(entitytype entityType, Position &position) {
    Structure *structure = (Structure *)entityFactory->buildEntity(entityType, position);
    if (structure == 0)
        return 0;
    collisionManager.addCollider((Collider *)structure->getCollider());
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
                ce.animals.insert(animal);
                toUpdateEntities.insert((EntityUpdater *)animal->getEntityUpdater()); // Fixme: Przywr�ci� metod� przydzielaj�c�!
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
                ce.items.insert(item);
            }
        }
    }
}

Animal *Chunk::addAnimal(entitytype entityType, Position &position) {
    Animal *animal = (Animal *)entityFactory->buildEntity(entityType, position);
    if (animal == 0)
        return 0;
    collisionManager.addCollider((Collider *)animal->getCollider());
    EntityUpdater *eu = (EntityUpdater *)animal->getEntityUpdater();
    eu->registerParentEventSource(chunkEvents.getEventSource());
    return animal;
}

void Chunk::placeHumanoid(Humanoid *humanoid) {
    ce.humanoids.insert(humanoid);
    EntityUpdater *eu = (EntityUpdater *)humanoid->getEntityUpdater();
    eu->registerParentEventSource(chunkEvents.getEventSource());
    collisionManager.addCollider((Collider *)humanoid->getCollider());
}

Chunk::Chunk(ChunkPosition chunkPosition, ChunkPlan &chunkPlan, EntityFactory *entityFactory, ItemFactory *itemFactory) :
    collisionManager(), itemFactory(itemFactory), entityFactory(entityFactory), chunkPosition(chunkPosition),
    chunkEvents(&chunkPosition, &collisionManager, &ce, &randomTickEntities, &toUpdateEntities) {
    // Entities and Items
    generateTiles(chunkPlan);
    generateStructures(chunkPlan);
    generateAnimals(chunkPlan);
    generateItems(chunkPlan);

    Logger::log(lg::DEBUG_CHUNK, "Created Chunk [%i, %i]", chunkPosition.x, chunkPosition.z);
}

Entity *Chunk::getGround(TilePosition &tilePosition) {
    return ce.groundTiles[tilePosition];
}

Entity *Chunk::getStructure(TilePosition &tilePosition) {
    return ce.structures[tilePosition];
}

std::vector<Entity *> Chunk::getByPosition(Position *position) {
    auto clickList = std::vector<Entity *>();

    for (auto &pa : ce.groundTiles) {
        Body *b = (Body *)pa.second->getBody();
        if (b->getRectangle()->pointBelongs(*position))
            clickList.push_back(pa.second);
    }
    for (auto &pa : ce.structures) {
        Body *b = (Body *)pa.second->getBody();
        if (b->getRectangle()->pointBelongs(*position))
            clickList.push_back(pa.second);
    }
    for (auto *en : ce.animals) {
        Body *b = (Body *)en->getBody();
        if (b->getRectangle()->pointBelongs(*position))
            clickList.push_back(en);
    }
    for (auto *en : ce.humanoids) {
        Body *b = (Body *)en->getBody();
        if (b->getRectangle()->pointBelongs(*position))
            clickList.push_back(en);
    }
    return clickList;
}

ChunkEvents *Chunk::getChunkEvents() {
    return &chunkEvents;
}

CollisionManager *Chunk::getCollisionManager() {
    return &collisionManager;
}

ChunkElements *Chunk::getChunkElements() {
    return &ce;
}

ChunkPosition *Chunk::getChunkPosition() {
    return &chunkPosition;
}

int Chunk::entitiesLoadedCount() {
    return ce.groundTiles.size() + ce.structures.size();
}

