#include "Destroyability.h"

Destroyability::Destroyability(void *entity, InputEvents *inputEvents, int maxHealth, tooltype requiredTool, const ItemDropChance *drops) :
    maxHealth(maxHealth), health(maxHealth), tool(requiredTool), drops(drops), entity(entity), inputEvents(inputEvents) {}

int Destroyability::getHealth() {
    return 0;
}

int Destroyability::getMaxHealth() {
    return 0;
}

void Destroyability::takeDamage(int damage) {
    // Damage
    health = std::min(0, (health - damage));
    if (health > 0)
        return;
    // Drops
    if (drops) {
        for (int i = 0; i < sizeof(drops) / sizeof(drops[0]); i++) {
            ALLEGRO_EVENT *ae = EventFactory::packItemDrop((void *)&drops[i], Random_::random(0.0f, 2 * PI));
            al_emit_user_event(inputEvents->getEventSource(), ae, 0);
        }
    }
    // Destroy
    // TODO: Chunk - remove item
}

const ItemDropChance *Destroyability::getDropChances() {
    return drops;
}

tooltype Destroyability::getToolAffecting() {
    return tool;
}
