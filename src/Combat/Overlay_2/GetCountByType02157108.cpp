#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetPtrField0x2a04_02010828(GameState* battleStruct);

struct S_a0b8c;
int CountNonZeroValues020a0b8c(struct S_a0b8c* p);
int GetFieldAt0x150_02053c6c(unsigned char* obj);
struct Slots02083960;
int CountPositiveSlots02083960(struct Slots02083960* s);

// USA: func_ov002_02157108
ARM int GetCountByType02157108(void* unused, int id) {
    GameState* bs = GameState::GetInstance();
    int result = 0;
    if (id == 5) {
        void* p = (char*)GetPtrField0x2a04_02010828(bs) + 0xe04;
        result = CountNonZeroValues020a0b8c((struct S_a0b8c*)p);
    } else if (id == 4) {
        void* p = GetPtrField0x2a04_02010828(bs);
        result = CountNonZeroValues020a0b8c((struct S_a0b8c*)p);
    } else {
        GameObject* c = GetCombatantWithFlag0x100_0200ff1c(bs, id);
        if (c != NULL) {
            int ptrAsInt = GetFieldAt0x150_02053c6c((unsigned char*)c);
            result = CountPositiveSlots02083960((struct Slots02083960*)ptrAsInt);
        }
    }
    return result;
}
