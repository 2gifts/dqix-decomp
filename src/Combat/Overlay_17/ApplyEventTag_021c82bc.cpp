#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
extern "C" void func_ov017_021c812c(int a, int b);
void SetSubstructByte0x1c(unsigned char* obj, unsigned char value);
extern "C" void* func_ov017_021b8468(void* obj);
void SetCombatWorkFlags0x55f4(void* work, int mask);

struct Evt021c82bc {
    unsigned char pad0[4];
    unsigned char lowNibble : 4;
    unsigned char flag4 : 1;
    unsigned char pad4_5_7 : 3;
    unsigned char arr1[4];
    unsigned char arr2[8];
};

// JPN: func_ov017_021c876c
// USA: func_ov017_021c82bc  (semantic: ApplyEventTag_021c82bc)
extern "C" ARM void func_ov017_021c82bc(int p0, struct Evt021c82bc* evt, int unused2, int table, struct SearchStruct0202c1a4* search) {
#if defined(jpn)
 enum {regionalOffset=0x508};
#else
 enum {regionalOffset=0x718};
#endif
    signed char cur = GetSearchStructCurrentArrEntry(search);
    if (evt->lowNibble != cur) return;
    if (evt->flag4) {
        func_ov017_021c812c((unsigned char)p0, 0);
        return;
    }

    GameState* bs = GameState::GetInstance();
    int i;
    for (i = 0; i < 4; i++) {
        GameObject* c = bs->GetCombatantByIndex(i);
        if (c != NULL && evt->arr1[i] != 0xff) {
            SetSubstructByte0x1c((unsigned char*)c, evt->arr1[i]);
        }
    }
    int j;
    for (j = 0; j < 8; j++) {
        GameObject* c = bs->GetCombatantByIndex(j + 0xc0);
        if (c != NULL && evt->arr2[j] != 0xff) {
            SetSubstructByte0x1c((unsigned char*)c, evt->arr2[j]);
        }
    }

    void* field6d0 = *(void**)((char*)table + 0x3000 + regionalOffset);
    void* work = func_ov017_021b8468(field6d0);
    if (!work) return;
    SetCombatWorkFlags0x55f4(work, 0x200000);
}
