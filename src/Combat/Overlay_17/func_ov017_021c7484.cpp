#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct StatLevels_021c7484 {
    unsigned int s0 : 3, s1 : 3, s2 : 3, s3 : 3, s4 : 3, s5 : 3, s6 : 3, s7 : 3, s8 : 3, s9 : 3;
};

struct LevelStats_021c7484 {
    char pad0[0x26];
    unsigned char active;
    char pad27[0x35];
    unsigned char current[20];
    char pad70[0xf];
    unsigned char base[20];
};

struct LevelPayload_021c7484 {
    unsigned short event;
    unsigned short index;
    StatLevels_021c7484 low;
    StatLevels_021c7484 high;
    char padc[2];
    unsigned char selector;
    char padf;
};

struct LevelMessage_021c7484 {
    unsigned char type;
    char pad1[3];
    LevelPayload_021c7484 payload;
};

struct LevelSelection_021c7484 { char pad0[8]; unsigned short event; };

extern "C" LevelSelection_021c7484* func_ov017_021b8478(void*);
void* GetData02100044();
int TestBitAt0x34(unsigned char*, unsigned int);
extern "C" void func_0205e330(void*, void*, int);

// USA: func_ov017_021c7484
extern "C" ARM void func_ov017_021c7484() {
    GameState* game = GameState::GetInstance();
#if defined(jpn)
    LevelSelection_021c7484* selection = func_ov017_021b8478(*(void**)((char*)func_ov017_0218b5b0() + 0x3508));
#else
    LevelSelection_021c7484* selection = func_ov017_021b8478(func_ov017_0218b5b0()->unknown_ptr_3718);
#endif
    void* context = GetData02100044();
    LevelMessage_021c7484 message;
    message.type = 0x72;
    LevelPayload_021c7484* payload = &message.payload;
    for (int i = 0; i < 4; ++i) {
        if (!TestBitAt0x34((unsigned char*)selection, (unsigned char)i)) continue;
        GameObject* combatant = game->GetCombatantByIndex(i);
        if (!((LevelStats_021c7484*)combatant->currentStats_)->active) continue;
        payload->event = selection->event;
        payload->index = i;
        LevelStats_021c7484* stats = (LevelStats_021c7484*)combatant->currentStats_;
        payload->selector = 1;
        payload->low.s0 = stats->current[0];
        payload->low.s1 = stats->current[1];
        payload->low.s2 = stats->current[2];
        payload->low.s3 = stats->current[3];
        payload->low.s4 = stats->current[4];
        payload->low.s5 = stats->current[5];
        payload->low.s6 = stats->current[6];
        payload->low.s7 = stats->current[7];
        payload->low.s8 = stats->current[8];
        payload->low.s9 = stats->current[9];
        payload->high.s0 = stats->current[10];
        payload->high.s1 = stats->current[11];
        payload->high.s2 = stats->current[12];
        payload->high.s3 = stats->current[13];
        payload->high.s4 = stats->current[14];
        payload->high.s5 = stats->current[15];
        payload->high.s6 = stats->current[16];
        payload->high.s7 = stats->current[17];
        payload->high.s8 = stats->current[18];
        payload->high.s9 = stats->current[19];
        func_0205e330(context, &message, 0);
        stats = (LevelStats_021c7484*)combatant->currentStats_;
        payload->selector = 0;
        payload->low.s0 = stats->base[0];
        payload->low.s1 = stats->base[1];
        payload->low.s2 = stats->base[2];
        payload->low.s3 = stats->base[3];
        payload->low.s4 = stats->base[4];
        payload->low.s5 = stats->base[5];
        payload->low.s6 = stats->base[6];
        payload->low.s7 = stats->base[7];
        payload->low.s8 = stats->base[8];
        payload->low.s9 = stats->base[9];
        payload->high.s0 = stats->base[10];
        payload->high.s1 = stats->base[11];
        payload->high.s2 = stats->base[12];
        payload->high.s3 = stats->base[13];
        payload->high.s4 = stats->base[14];
        payload->high.s5 = stats->base[15];
        payload->high.s6 = stats->base[16];
        payload->high.s7 = stats->base[17];
        payload->high.s8 = stats->base[18];
        payload->high.s9 = stats->base[19];
        func_0205e330(context, &message, 0);
    }
}
