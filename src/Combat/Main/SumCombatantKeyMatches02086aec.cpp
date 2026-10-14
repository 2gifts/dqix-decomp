#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02086aec {
    char pad[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

int GetFieldAt0x150_02053c6c(unsigned char* obj);

struct Slots02083994;
int CountMatchingUntilNegative02083994(struct Slots02083994* s, int value);

struct Container02083554;
struct Entry02083554;
struct Entry02083554* FindEntryByShortField02083554(struct Container02083554* c, int id);

short SumKeyedLookups02086bf4(char* obj, int key);

// USA: func_02086aec
ARM short SumCombatantKeyMatches02086aec(struct Obj02086aec* obj, int key) {
    short acc;
    GameState* bs;
    unsigned char i;
    GameObject* c;
    void* x;
    if (key < 0) {
        return 0;
    }
    acc = 0;
    bs = GameState::GetInstance();
    for (i = 0; i < obj->count; i++) {
        c = GetCombatantWithFlag0x100_0200ff1c(bs, obj->ids[i]);
        if (c != NULL) {
            x = (void*)GetFieldAt0x150_02053c6c((unsigned char*)c);
            if (x != NULL) {
                acc = acc + CountMatchingUntilNegative02083994((struct Slots02083994*)x, key);
                if (FindEntryByShortField02083554((struct Container02083554*)x, key) != NULL) {
                    acc = acc + 1;
                }
            }
        }
    }
    return acc + SumKeyedLookups02086bf4((char*)obj, key);
}
