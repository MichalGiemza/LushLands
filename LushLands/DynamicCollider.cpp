#include "DynamicCollider.h"

int DynamicCollider::checkWalkableDistance(int accurateDistance, std::unordered_set<Collider *> colliders) {
    int distance = accurateDistance;
    for (auto c = colliders.begin(); c != colliders.end(); ++c) {
        if (not isCloseBy(*c))
            continue;
        if ((Body)(*this) == (Body)(**c))
            continue;
        distance = std::min(distance, accurateDistanceTo2D(**c));
    }
    return distance;
}
