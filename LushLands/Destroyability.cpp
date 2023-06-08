#include "Destroyability.h"

Destroyability::Destroyability(void *entity, InputEvents *inputEvents, int maxHealth, tag requiredTool, const EntityDrops &drops) :
    maxHealth(maxHealth), health(maxHealth), tool(requiredTool), drops(&drops), entity(entity), inputEvents(inputEvents) {}

int Destroyability::getHealth() {
    return 0;
}

int Destroyability::getMaxHealth() {
    return 0;
}

void Destroyability::takeDamage(int damage) {
    // Damage
    health = std::max(0, (health - damage));
    if (health > 0)
        return;
    // Drops
    if (drops) {
        for (int i = 0; i < drops->n; i++) {
            ItemDropChance *dc = &drops->dropChances[i];
            ALLEGRO_EVENT *ae = EventFactory::packItemGenerate((void *)dc, Random_::random(0.0f, 2 * PI), entity);
            al_emit_user_event(inputEvents->getEventSource(), ae, 0);
        }
    }
    // Destroy
    ALLEGRO_EVENT *ae = EventFactory::packEntityDestroy(entity);
    al_emit_user_event(inputEvents->getEventSource(), ae, 0);
}

const EntityDrops *Destroyability::getDropChances() {
    return drops;
}

tag Destroyability::getToolAffecting() {
    return tool;
}
