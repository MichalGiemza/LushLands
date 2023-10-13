#include "stdafx.h"
#include "BaseWorldPlanner.h"

ChunkPlan *BaseWorldPlanner::getChunkPlan(ChunkPosition &chunkPosition) {
    auto cp = new ChunkPlan();
    auto referencePosition = Position(chunkPosition);
    auto pos = Position(referencePosition);

    for (int i = 0; i < chunkSizeByTiles; i++) {
        for (int j = 0; j < chunkSizeByTiles; j++) {
            for (int k = 0; k < worldHeight; k++) {
                pos.setX(referencePosition.getX() + i);
                pos.setZ(referencePosition.getZ() + j);
                pos.setY(referencePosition.getY() + k);
                (*cp).fieldPlans[i][j][k] = getFieldPlan(pos);
            }
        }
    }
    return cp;
}
