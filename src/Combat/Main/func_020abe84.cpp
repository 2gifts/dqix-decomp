#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Entry020abe84 {
    unsigned int fieldA : 10;
    unsigned int rest : 22;
};

struct S_a0460 {
    char pad[0x14];
    unsigned int val : 9;
    unsigned int hi : 23;
    char pad2[0xb0 - 0x18];
};

static inline unsigned int FieldA(const Entry020abe84* e) { return e->fieldA; }

extern "C" int _Z23LoadBattleBlock020ac4c0Pv(void*);
void AddClamped9BitField(struct S_a0460*, unsigned int);
int CopyInBattleField0x7540(void*);

// USA: func_020abe84
extern "C" ARM int func_020abe84(void* unused, short* indices, Entry020abe84* values, int count) {
    S_a0460 block;
    Entry020abe84* table = (Entry020abe84*)((char*)GameState::GetInstance() + 0x75f0);
    int added = 0;
    int i;
    for (i = 0; i < count; i++) {
        short idx = (short)(indices[i] - 1);
        Entry020abe84* src = &values[i];
        if (idx < 0) continue;
        if (idx >= 0x134) continue;
        if (FieldA(&table[idx]) == 0 && src->fieldA != 0) {
            added++;
        }
        memcpy(&table[idx], src, sizeof(int));
    }
    _Z23LoadBattleBlock020ac4c0Pv(&block);
    AddClamped9BitField(&block, added);
    CopyInBattleField0x7540(&block);
    return 1;
}
