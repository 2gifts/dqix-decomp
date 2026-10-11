#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct StatusBits {
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char count : 4;
};
struct StatusStats {
    char pad0[0x26];
    unsigned char active;
    char pad27[0x13];
    unsigned char flag;
    StatusBits status;
};
struct StatusPayload {
    unsigned short event;
    unsigned short index;
    char pad8[9];
    StatusBits status;
    char pad12;
    unsigned char unused : 7;
    unsigned char flag : 1;
};
struct StatusMessage { unsigned char type; char pad1[3]; unsigned int payload[4]; };
struct StatusSelection { char pad0[8]; unsigned short event; };
static inline unsigned int GetBit0(StatusStats* stats) { return stats->status.bit0; }
static inline unsigned int GetBit1(StatusStats* stats) { return stats->status.bit1; }
static inline unsigned int GetBit2(StatusStats* stats) { return stats->status.bit2; }
static inline unsigned int GetBit3(StatusStats* stats) { return stats->status.bit3; }
static inline unsigned int GetCount(StatusStats* stats) { return stats->status.count; }
extern "C" StatusSelection* func_ov017_021b8478(void*);
void* GetData02100044();
int TestBitAt0x34(unsigned char*, unsigned int);
extern "C" void func_0205e330(void*, void*, int);

// JPN: func_ov017_021c7654
// USA: func_ov017_021c71a4
extern "C" ARM void func_ov017_021c71a4() {
    GameState* game = GameState::GetInstance();
#if defined(jpn)
    StatusSelection* selection = func_ov017_021b8478(*(void**)((char*)func_ov017_0218b5b0() + 0x3508));
#else
    StatusSelection* selection = func_ov017_021b8478(func_ov017_0218b5b0()->unknown_ptr_3718);
#endif
    void* context = GetData02100044();
    StatusMessage message;
    message.type = 0x71;
    StatusPayload* payload = (StatusPayload*)message.payload;
    for (int i = 0; i < 4; ++i) {
        if (!TestBitAt0x34((unsigned char*)selection, (unsigned char)i)) continue;
        GameObject* combatant = game->GetCombatantByIndex(i);
        if (!combatant || !((StatusStats*)combatant->currentStats_)->active) continue;
        payload->event = selection->event;
        payload->index = i;
        payload->status.bit0 = (unsigned char)GetBit0((StatusStats*)combatant->currentStats_);
        payload->status.bit1 = (unsigned char)GetBit1((StatusStats*)combatant->currentStats_);
        payload->status.bit2 = (unsigned char)GetBit2((StatusStats*)combatant->currentStats_);
        payload->status.bit3 = (unsigned char)GetBit3((StatusStats*)combatant->currentStats_);
        payload->status.count = (unsigned char)GetCount((StatusStats*)combatant->currentStats_);
        payload->flag = ((StatusStats*)combatant->currentStats_)->flag;
        func_0205e330(context, &message, 0);
    }
}
