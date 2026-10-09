#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
struct Entry020ac104 {
    short id;
    unsigned short active : 1;
    unsigned short flag : 1;
    unsigned short padding : 14;
};
struct Stored020ac104 {
    unsigned short packed;
};
struct State020ac104 {
    unsigned char pad0[0x7ac4];
    Stored020ac104 entries[0x1d7];
};
struct S_a0434 {
    unsigned char pad0[0x10];
    unsigned int low : 23;
    unsigned int value : 9;
    unsigned char pad1[0xb0 - 0x14];
};
extern "C" int _Z23LoadBattleBlock020ac4c0Pv(void*);
void AddClamped9BitFieldTopAt0x10(S_a0434*, unsigned int);
int CopyInBattleField0x7540(void*);
// USA: func_020ac104
extern "C" ARM int func_020ac104(int unused, Entry020ac104* input, int count) {
    State020ac104* state = (State020ac104*)GameState::GetInstance();
    int added = 0;
    Stored020ac104* entries = state->entries;
    for (int i = 0; i < count; i++) {
        Entry020ac104* entry = &input[i];
        if (entry->id < 0) continue;
        Stored020ac104* cursor = entries;
        unsigned int slot = 0;
        unsigned int j;
        int id = entry->id;
        for (j = 0; j < 0x1d7; j++) {
            slot = j;
            int storedId = (cursor->packed & 0xfffc) >> 2;
            if (storedId <= 0) {
                if (entry->active == 1) added++;
                break;
            }
            if (storedId == id) {
                if (!((cursor->packed & 2) >> 1) && entry->active == 1) added++;
                break;
            }
            cursor++;
        }
        Stored020ac104 stored;
        stored.packed = (id << 2) | (entry->active << 1) | entry->flag;
        memcpy(&state->entries[slot], &stored, 2);
    }
    S_a0434 block;
    _Z23LoadBattleBlock020ac4c0Pv(&block);
    AddClamped9BitFieldTopAt0x10(&block, added);
    CopyInBattleField0x7540(&block);
    return 1;
}
