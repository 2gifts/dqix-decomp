#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void*);
extern "C" void* func_ov017_021b8468(void*);
void* GetField6b0_021b8470(void*);
int GetField0x3acValue(GameState*);

struct EventInfo021c787c {
    unsigned char padding0[8];
    unsigned short eventId;
    unsigned char paddingA[0x20];
    signed char combatantIndex;
};
struct StatLevels021c787c {
    unsigned int level0:3, level1:3, level2:3, level3:3, level4:3;
    unsigned int level5:3, level6:3, level7:3, level8:3, level9:3;
};
struct StatPacket021c787c {
    unsigned int field0;
    unsigned short eventId;
    unsigned short combatantId;
    unsigned int lowLevels;
    unsigned int highLevels;
    unsigned short field10;
    unsigned char selector;
};
struct StatDisplay021c787c {
    unsigned char padding0[0x5c];
    unsigned char primaryLevels[20];
    unsigned char padding70[15];
    unsigned char secondaryLevels[20];
};

// USA: func_ov017_021c787c
extern "C" ARM void func_ov017_021c787c(int unused, StatPacket021c787c* packet, GameState* game, GameResources* resources) {
    void* handle = resources->unknown_ptr_3718;
    EventInfo021c787c* event = (EventInfo021c787c*)func_ov017_021b8478(handle);
    if (!event) return;
    if (!func_ov017_021b8468(handle)) return;
    if (!GetField6b0_021b8470(handle)) return;
    int index = GetField0x3acValue(game);
    if (event->combatantIndex == index) return;
    if (event->eventId != packet->eventId) return;
    GameObject* combatant = game->GetCombatantByIndex(packet->combatantId);
    if (!combatant) return;
    StatLevels021c787c* low = (StatLevels021c787c*)&packet->lowLevels;
    StatLevels021c787c* high = (StatLevels021c787c*)&packet->highLevels;
    StatDisplay021c787c* stats = (StatDisplay021c787c*)combatant->currentStats_;
    switch (packet->selector) {
    case 1: {
        stats->primaryLevels[0] = low->level0;
        stats->primaryLevels[1] = low->level1;
        stats->primaryLevels[2] = low->level2;
        stats->primaryLevels[3] = low->level3;
        stats->primaryLevels[4] = low->level4;
        stats->primaryLevels[5] = low->level5;
        stats->primaryLevels[6] = low->level6;
        stats->primaryLevels[7] = low->level7;
        stats->primaryLevels[8] = low->level8;
        stats->primaryLevels[9] = low->level9;
        stats->primaryLevels[10] = high->level0;
        stats->primaryLevels[11] = high->level1;
        stats->primaryLevels[12] = high->level2;
        stats->primaryLevels[13] = high->level3;
        stats->primaryLevels[14] = high->level4;
        stats->primaryLevels[15] = high->level5;
        stats->primaryLevels[16] = high->level6;
        stats->primaryLevels[17] = high->level7;
        stats->primaryLevels[18] = high->level8;
        stats->primaryLevels[19] = high->level9;
        break;
    }
    default: {
        stats->secondaryLevels[0] = low->level0;
        stats->secondaryLevels[1] = low->level1;
        stats->secondaryLevels[2] = low->level2;
        stats->secondaryLevels[3] = low->level3;
        stats->secondaryLevels[4] = low->level4;
        stats->secondaryLevels[5] = low->level5;
        stats->secondaryLevels[6] = low->level6;
        stats->secondaryLevels[7] = low->level7;
        stats->secondaryLevels[8] = low->level8;
        stats->secondaryLevels[9] = low->level9;
        stats->secondaryLevels[10] = high->level0;
        stats->secondaryLevels[11] = high->level1;
        stats->secondaryLevels[12] = high->level2;
        stats->secondaryLevels[13] = high->level3;
        stats->secondaryLevels[14] = high->level4;
        stats->secondaryLevels[15] = high->level5;
        stats->secondaryLevels[16] = high->level6;
        stats->secondaryLevels[17] = high->level7;
        stats->secondaryLevels[18] = high->level8;
        stats->secondaryLevels[19] = high->level9;
    }
    }
}
