#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetPtrField0x2a04_02010828(GameState* battleStruct);

struct PartyRow020686e0 {
    char pad[0xf78];
    unsigned char id;
};

struct Sub0x130_020686e0 {
    unsigned int flags;
    unsigned short field4;
};

struct Obj020686e0 {
    char pad[0x31];
    signed char field31;
};

// USA: func_020686e0
ARM int CountFlag0x800Matches020686e0(GameState* battleStruct, struct Obj020686e0* obj2) {
    unsigned char* p = (unsigned char*)GetPtrField0x2a04_02010828(battleStruct);
    signed char count = obj2->field31;
    if (count < 0) {
        int i;
        count = 0;
        for (i = 0; i < p[0xf7c]; i++) {
            GameObject* c = battleStruct->GetPartyMemberByIndex(((struct PartyRow020686e0*)(p + i))->id);
            if (c != 0) {
                struct Sub0x130_020686e0* sub = *(struct Sub0x130_020686e0**)((char*)c + 0x130);
                if (!(sub->flags & 1)) {
                    if (sub->field4 != 0) {
                        count = count + 1;
                    }
                }
            }
        }
    }
    return count != 1;
}
