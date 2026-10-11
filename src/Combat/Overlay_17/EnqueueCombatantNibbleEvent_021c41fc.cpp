// JPN: func_ov017_021c46c4
#include <globaldefs.h>

#if defined(jpn)
enum { kRegionalFieldOffset = 0x150 };
#else
enum { kRegionalFieldOffset = 0x15c };
#endif
#include "GameState/GameState.h"

void* GetData02100044(void);
struct U16Field0x6_020375f8;
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Payload021c41fc {
    unsigned char flags;
    unsigned char lowNibble : 4;
    unsigned char highNibble : 4;
    unsigned short field6;
    unsigned short field8;
};

struct Evt021c41fc {
    unsigned char tag;
    unsigned char pad1[3];
    struct Payload021c41fc payload;
    unsigned char pad2[0xa];
};

// USA: func_ov017_021c41fc  (semantic: EnqueueCombatantNibbleEvent_021c41fc)
extern "C" ARM void func_ov017_021c41fc(int combatantId, int mode) {
    GameState* battleStruct = GameState::GetInstance();
    ((int)func_ov017_0218b5b0());
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(combatantId);
    if (combatant == NULL) return;

    void* data = GetData02100044();

    struct Evt021c41fc evt;
    struct Payload021c41fc* p = &evt.payload;
    evt.tag = 0;
    p->lowNibble = combatantId;
    p->field6 = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)combatant);
    p->flags = 0;
    if (mode >= 0) {
        p->highNibble = mode;
        p->flags |= 1;
    } else {
        p->highNibble = 0;
    }

    int v = *(int*)((char*)combatant + kRegionalFieldOffset);
    if (v < 0) {
        p->field8 = 0;
    } else {
        p->field8 = (unsigned short)v;
        p->flags |= 2;
    }

    GameObject* target = battleStruct->GetUnknownGameObject();
    if (target != NULL && combatantId == *(short*)((char*)target + 4)) {
        if (p->field6 == 0x2710) {
            p->field6 = 0x170c;
        } else if (p->field6 == 0x2710 + 0x64) {
            p->field6 = 0x1901;
        }

        if (p->field8 != 0) {
            if (p->field8 == 0x2710) {
                p->field8 = 0x170c;
            } else if (p->field8 == 0x2710 + 0x64) {
                p->field8 = 0x1901;
            }
        }
    }

    func_0205e330(data, &evt, 0);
}
