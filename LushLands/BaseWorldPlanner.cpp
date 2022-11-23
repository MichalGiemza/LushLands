#include "BaseWorldPlanner.h"

ChunkPlan BaseWorldPlanner::getChunkPlan(ChunkPosition chunkPosition) {
    auto cp = ChunkPlan();
    auto referencePosition = Position(chunkPosition);
    auto pos = Position(referencePosition);

    for (int i = 0; i < chunkSize; i++) {
        for (int j = 0; j < chunkSize; j++) {
            pos.setX(referencePosition.x() + i);
            pos.setZ(referencePosition.z() + j);
            cp.fieldPlans[i][j] = getFieldPlan(pos);
        }
    }
    return cp;
}
