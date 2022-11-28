#include "BaseWorldPlanner.h"

ChunkPlan *BaseWorldPlanner::getChunkPlan(ChunkPosition &chunkPosition) {
    auto cp = new ChunkPlan();
    auto referencePosition = Position(chunkPosition);
    auto pos = Position(referencePosition);

    for (int i = 0; i < chunkSize; i++) {
        for (int j = 0; j < chunkSize; j++) {
            for (int k = 0; k < worldHeight; k++) {
                pos.setX(referencePosition.x() + i);
                pos.setZ(referencePosition.z() + j);
                pos.setY(referencePosition.y() + k);
                (*cp).fieldPlans[i][j][k] = getFieldPlan(pos);
            }
        }
    }
    return cp;
}
