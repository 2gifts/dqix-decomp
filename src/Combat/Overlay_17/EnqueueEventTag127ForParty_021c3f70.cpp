#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetPtrField0x2a04_02010828(GameState*);
void EnqueueEventTag127_021cbeb0(unsigned char a, unsigned short b);

struct PartyIdList_021c3f70 {
    char pad[0xf78];
    signed char id[4];
    unsigned char count;
};

// USA: func_ov017_021c3f70
ARM void EnqueueEventTag127ForParty_021c3f70(unsigned short tag) {
    GameState* battleStruct = GameState::GetInstance();
    struct PartyIdList_021c3f70* p = (struct PartyIdList_021c3f70*)GetPtrField0x2a04_02010828(battleStruct);
    int i;
    for (i = 0; i < p->count; i++) {
        ((void (*)(int, unsigned short))EnqueueEventTag127_021cbeb0)(p->id[i], tag);
    }
}
