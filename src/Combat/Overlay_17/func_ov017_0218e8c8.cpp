#include <globaldefs.h>
#include "GameState/GameState.h"

struct Flags0218e8c8 {
    unsigned char pad0[2];
    unsigned char enabled;
    unsigned char active;
};

struct OvCtx0218e8c8 {
    unsigned char pad0[0x3718];
    Flags0218e8c8* table;
    unsigned char pad371c[0x3b30 - 0x371c];
    Flags0218e8c8* state;
};

extern "C" char* func_02012fe4(void);
extern "C" int _Z19IsIdInRange020981e4ii(void* obj, int id);
extern "C" unsigned short _Z20GetField6b4_021b8480Pv(void* obj);
extern "C" unsigned char* func_ov017_021b8478(void* obj);
extern "C" int _Z27GetByteAtPtrOrZero_02191b58v(OvCtx0218e8c8* ov, int idx);
unsigned int GetBitsInField8(unsigned int* obj, unsigned int mask);
int TestBitAt0x34(unsigned char* obj, unsigned int index);
extern "C" void func_ov017_0218eafc(OvCtx0218e8c8* ov, int idx);
int CheckFlag0x1ceBit2Set(unsigned char* obj);
extern "C" int func_02032fdc(void* obj, int a, int b);
extern "C" void func_ov017_0218dba0(int id);

// USA: func_ov017_0218e8c8
extern "C" ARM void func_ov017_0218e8c8(OvCtx0218e8c8* ov, int id, int mode) {
    GameState* gs = GameState::GetInstance();
    char* base = func_02012fe4();
    int inRange = 0;
    if (_Z19IsIdInRange020981e4ii(base + 0x840, id)) {
        inRange = 1;
    }

    unsigned char* mask = NULL;
    if ((ov->table->active != 0 && _Z20GetField6b4_021b8480Pv(ov->table) == 0) ||
        (ov->state->active != 0 && ov->table->enabled != 0)) {
        mask = func_ov017_021b8478(ov->table);
    }

    for (int i = 0; i < 4; i++) {
        unsigned char b = _Z27GetByteAtPtrOrZero_02191b58v(ov, i) | 2;
        if (mode == 1) {
            if (b != 0) continue;
        } else if (mode == 2 && b == 0) {
            continue;
        }

        int skip = 0;
        GameObject* c = GetCombatantWithFlag0x100(gs, i);
        GameObject* obj = gs->GetGameObjectByIndex(i * 0xc + 0x14);
        if (c == NULL) continue;

        if (GetBitsInField8((unsigned int*)ov, 2) == 0 && c->obj3D_.GetFlag(0x800000) == 0) {
            if (id != c->obj3D_.GetField06()) continue;
        } else if (GetBitsInField8((unsigned int*)ov, 4) != 0) {
            if (id != c->obj3D_.GetField06()) continue;
        }

        if (mask != NULL && TestBitAt0x34(mask, (unsigned char)i) == 0) continue;

        if (inRange && obj != NULL) {
            if (obj->obj3D_.unknown_2_ == 0x2347 || obj->obj3D_.unknown_2_ == 0x2348 ||
                obj->obj3D_.unknown_2_ == 0x2349) {
                skip = 1;
            }
        }
        if (skip) continue;

        func_ov017_0218eafc(ov, i);
    }

    GameObject* member = gs->GetPartyMemberByIndex(0xce);
    if (member != NULL && !CheckFlag0x1ceBit2Set((unsigned char*)member) && func_02032fdc(member, 1, 0)) {
        func_ov017_0218dba0(0xce);
    }
}
