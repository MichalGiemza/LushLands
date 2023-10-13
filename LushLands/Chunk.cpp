#include "stdafx.h"
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
                chunkUpdater.registerEntity(ground);
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
                pos.setX(referencePosition.getX() + i);
                pos.setZ(referencePosition.getZ() + j);
                pos.setY(referencePosition.getY() + k);
                auto plannedEntityType = chunkPlan.fieldPlans[i][j][k].structure;
                auto structure = addStructure(plannedEntityType, pos);
                if (structure == 0)
                    continue;
                chunkUpdater.registerEntity(structure);
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

Entity *Chunk::rmStructure(Entity *entity) {
    if (not entity)
        return entity;
    TilePosition *tPos = (TilePosition *)entity->getTilePosition();
    auto msr = ce.structures.find(*tPos);
    if (msr != ce.structures.end() and msr->second == entity) {
        Structure *structure = (Structure *)entity;
        collisionManager.rmCollider((Collider *)entity->getCollider());
        ce.structures.erase(msr);
        delete structure;
        entity = 0;
    }
    return entity;
}

void Chunk::generateAnimals(ChunkPlan &chunkPlan) {
    auto referencePosition = Position(chunkPosition);
    auto pos = Position(referencePosition);

    for (int i = 0; i < chunkSizeByTiles; i++) {
        for (int j = 0; j < chunkSizeByTiles; j++) {
            for (int k = 0; k < worldHeight; k++) {
                pos.setX(referencePosition.getX() + i);
                pos.setZ(referencePosition.getZ() + j);
                pos.setY(referencePosition.getY() + k);
                auto plannedEntityType = chunkPlan.fieldPlans[i][j][k].animal;
                Animal *animal = addAnimal(plannedEntityType, pos);
                if (animal == 0)
                    continue;
                ce.animals.insert(animal);
                chunkUpdater.registerEntity(animal);
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
                auto plannedEntityType = chunkPlan.fieldPlans[i][j][k].item;
                auto plannedItemAmount = chunkPlan.fieldPlans[i][j][k].itemAmount;
                if (not plannedEntityType)
                    continue;
                Item *item = itemFactory->buildItem(plannedEntityType, plannedItemAmount, &pos);
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
    eu->registerParentEventSource(inputEvents->getEventSource());
    return animal;
}

Entity *Chunk::rmAnimal(Entity *entity) {
    if (not entity)
        return entity;
    auto sr = ce.animals.find(entity);
    if (sr != ce.animals.end()) {
        Animal *animal = (Animal *)entity;
        collisionManager.rmCollider((Collider *)entity->getCollider());
        ce.animals.erase(entity);
        delete animal;
        entity = 0;
    }
    return entity;
}

Entity *Chunk::rmHumanoid(Entity *entity) {
    if (not entity)
        return entity;
    auto sr = ce.humanoids.find(entity);
    if (sr != ce.humanoids.end()) {
        Humanoid *humanoid = (Humanoid *)entity;
        collisionManager.rmCollider((Collider *)entity->getCollider());
        ce.humanoids.erase(entity);
        delete humanoid;
        entity = 0;
    }
    return entity;
}

Entity *Chunk::rmGround(Entity *entity) {
    if (not entity)
        return entity;
    TilePosition *tPos = (TilePosition *)entity->getTilePosition();
    auto msr = ce.groundTiles.find(*tPos);
    if (msr != ce.groundTiles.end() and *msr->second == *entity) {
        Ground *ground = (Ground *)entity;
        ce.groundTiles.erase(msr);
        delete ground;
        entity = 0;
    }
    
    return entity;
}

void Chunk::placeHumanoid(Humanoid *humanoid) {
    ce.humanoids.insert(humanoid);
    EntityUpdater *eu = (EntityUpdater *)humanoid->getEntityUpdater();
    eu->registerParentEventSource(inputEvents->getEventSource());
    collisionManager.addCollider((Collider *)humanoid->getCollider());
}

void Chunk::placeItem(Item *item) {
    ce.items.insert(item);
}

void Chunk::removeEntity(Entity *entity) {
    entity = rmHumanoid(entity);
    entity = rmAnimal(entity);
    entity = rmStructure(entity);
    entity = rmGround(entity);
}

Chunk::Chunk(ChunkPosition chunkPosition, ChunkPlan &chunkPlan, EntityFactory *entityFactory, ItemFactory *itemFactory, InputEvents *inputEvents) :
    collisionManager(), itemFactory(itemFactory), entityFactory(entityFactory), chunkPosition(chunkPosition), inputEvents(inputEvents), chunkUpdater(inputEvents) {
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
    ll level = position->getY();

    for (auto &pa : ce.groundTiles) {
        Body *b = (Body *)pa.second->getBody();
        if (b->getPosition()->getY() == level and b->getRectangle()->pointBelongs(*position))
            clickList.push_back(pa.second);
    }
    for (auto &pa : ce.structures) {
        Body *b = (Body *)pa.second->getBody();
        if (b->getPosition()->getY() == level and b->getRectangle()->pointBelongs(*position))
            clickList.push_back(pa.second);
    }
    for (auto *en : ce.animals) {
        Body *b = (Body *)en->getBody();
        if (b->getPosition()->getY() == level and b->getRectangle()->pointBelongs(*position))
            clickList.push_back(en);
    }
    for (auto *en : ce.humanoids) {
        Body *b = (Body *)en->getBody();
        if (b->getPosition()->getY() == level and b->getRectangle()->pointBelongs(*position))
            clickList.push_back(en);
    }
    return clickList;
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

void Chunk::handleItemCollection() {
    // FIXME: M*N complexity, can it be done better?
    std::vector<std::pair<Item *, Entity *>> collection;
    for (auto &i : ce.items) {
        for (auto &h : ce.humanoids) {
            Position *pI = i->getPosition();
            Position *pH = (Position *)((Humanoid *)h)->getPosition();
            if (pI->getY() != pH->getY())
                continue;
            if (pI->distance2D(*pH) <= itemMagnetRadius * meter)
                collection.push_back(std::make_pair(i, h));
        }
    }
    // Assign collected items to humanoids
    std::vector<Item *> leftoverItems;
    for (auto &p : collection) {
        Inventory *inv = (Inventory *)((Humanoid *)p.second)->getInventory();
        Item *leftover = inv->putItemAuto(p.first);
        if (leftover)
            leftoverItems.push_back(leftover);
    }
    // Remove collected items from map
    for (auto &p : collection)
        ce.items.erase(p.first);
    // Put back leftover items
    for (auto &l : leftoverItems)
        ce.items.insert(l);
}

