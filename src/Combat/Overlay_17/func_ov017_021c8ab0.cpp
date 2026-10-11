#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
extern "C" void* _Z20GetField6b0_021b8470Pv(void* obj);
void SetSubstructByte0x1c(unsigned char* obj, unsigned char value);

struct Ret021c8ab0 {
    unsigned char pad[8];
    unsigned short field8;
};

struct Payload021c8ab0 {
    unsigned char arr1[4];
    unsigned char arr2[8];
    unsigned short fieldC;
};

struct Evt021c8ab0 {
    unsigned char pad0[4];
    struct Payload021c8ab0 payload;
};

// JPN: func_ov017_021c8f60
// USA: func_ov017_021c8ab0
extern "C" ARM void func_ov017_021c8ab0(int unused0, struct Evt021c8ab0* evt, GameState* bs, unsigned char* base) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
    void* table = *(void**)(base + 0x3000 + regionalOffset0);
    Ret021c8ab0* r = (Ret021c8ab0*)func_ov017_021b8478(table);
    if (r == NULL) return;
    if (!func_ov017_021b8468(table)) return;
    if (!_Z20GetField6b0_021b8470Pv(table)) return;

    struct Payload021c8ab0* p = &evt->payload;
    if (r->field8 != p->fieldC) return;

    int i;
    for (i = 0; i < 4; i++) {
        GameObject* c = bs->GetCombatantByIndex(i);
        if (c != NULL && p->arr1[i] != 0xff) {
            SetSubstructByte0x1c((unsigned char*)c, p->arr1[i]);
        }
    }
    int j;
    for (j = 0; j < 8; j++) {
        GameObject* c = bs->GetCombatantByIndex(j + 0xc0);
        if (c != NULL && p->arr2[j] != 0xff) {
            SetSubstructByte0x1c((unsigned char*)c, p->arr2[j]);
        }
    }
}
