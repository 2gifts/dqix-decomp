#include <globaldefs.h>
#include "GameState/GameState.h"

struct StatPayload021c7b8c {
    unsigned short eventId;
    unsigned short combatantId;
    union {
        struct {
            unsigned int level0:3, level1:3, level2:3, level3:3, level4:3;
            unsigned int level5:3, level6:3, level7:3, level8:3, level9:3;
            unsigned int :0;
            unsigned int level10:3, level11:3, level12:3, level13:3, level14:4;
        };
        struct { unsigned int lowWord; unsigned int highWord; };
    };
    unsigned char selector;
};
struct StatMessage021c7b8c {
    unsigned char kind;
    unsigned char padding[3];
    StatPayload021c7b8c payload;
};
struct StatSource021c7b8c {
    unsigned char padding0[0x26];
    unsigned char active;
    unsigned char padding27[0x70 - 0x27];
    unsigned char primary[15];
    unsigned char padding7f[0x93 - 0x7f];
    unsigned char secondary[15];
};
struct EventInfo021c7b8c {
    unsigned char padding0[8];
    unsigned short eventId;
};
extern "C" void* func_ov017_021b8478(void*);
void* GetData02100044();
int TestBitAt0x34(unsigned char*, unsigned int);
extern "C" void func_0205e330(void*, StatMessage021c7b8c*, int);

// USA: func_ov017_021c7b8c
extern "C" ARM void func_ov017_021c7b8c() {
    GameState* game = GameState::GetInstance();
    EventInfo021c7b8c* event = (EventInfo021c7b8c*)func_ov017_021b8478(func_ov017_0218b5b0()->unknown_ptr_3718);
    void* queue = GetData02100044();
    StatPayload021c7b8c* payload;
    StatMessage021c7b8c message;
    payload = &message.payload;
    message.kind = 0x73;
    for (int index = 0; index < 4; ++index) {
        if (!TestBitAt0x34((unsigned char*)event, index & 255)) continue;
        GameObject* combatant = game->GetCombatantByIndex(index);
        if (!combatant || !((StatSource021c7b8c*)combatant->currentStats_)->active) continue;
        unsigned int high = payload->highWord & ~7u;
        payload->eventId = event->eventId;
        payload->combatantId = index;
        StatSource021c7b8c* stats = (StatSource021c7b8c*)combatant->currentStats_;
        payload->selector = 1;
        payload->level0 = stats->primary[0];
        payload->level1 = stats->primary[1];
        payload->level2 = stats->primary[2];
        payload->level3 = stats->primary[3];
        payload->level4 = stats->primary[4];
        payload->level5 = stats->primary[5];
        payload->level6 = stats->primary[6];
        payload->level7 = stats->primary[7];
        payload->level8 = stats->primary[8];
        payload->level9 = stats->primary[9];
        payload->highWord = high | (stats->primary[10] & 7);
        payload->level11 = stats->primary[11];
        payload->level12 = stats->primary[12];
        payload->level13 = stats->primary[13];
        payload->level14 = stats->primary[14];
        func_0205e330(queue, &message, 0);
        stats = (StatSource021c7b8c*)combatant->currentStats_;
        payload->selector = 0;
        payload->level0 = stats->secondary[0];
        payload->level1 = stats->secondary[1];
        payload->level2 = stats->secondary[2];
        payload->level3 = stats->secondary[3];
        payload->level4 = stats->secondary[4];
        payload->level5 = stats->secondary[5];
        payload->level6 = stats->secondary[6];
        payload->level7 = stats->secondary[7];
        payload->level8 = stats->secondary[8];
        payload->level9 = stats->secondary[9];
        payload->level10 = stats->secondary[10];
        payload->level11 = stats->secondary[11];
        payload->level12 = stats->secondary[12];
        payload->level13 = stats->secondary[13];
        payload->level14 = stats->secondary[14];
        func_0205e330(queue, &message, 0);
    }
}
