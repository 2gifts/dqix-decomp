#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x21c
#else
#define REGION_OFFSET_0 0x2a0
#endif

#include "GameState/GameState.h"

struct S02163b90 { char pad[REGION_OFFSET_0]; unsigned char* bitsPtr; };

int TestBitAt0x34(unsigned char* obj, unsigned int index);
extern "C" void _ZN8Object3D11MakeVisibleEv(unsigned char* obj);
void SetSubstructByte0x56(unsigned char* obj);
extern "C" void _ZN8Object3D10MakeHiddenEv(unsigned char* obj);
void ClearSubstructByte0x56(unsigned char* obj);

// USA: func_ov000_02163b90  (semantic: UpdateAllCombatantsFlagField6c_02163b90)
extern "C" ARM void func_ov000_02163b90(struct S02163b90* self, int clear) {
    GameState* bs = GameState::GetInstance();
    int id;
    for (id = 0; id <= 3; id++) {
        GameObject* c = GetCombatantWithFlag0x100(bs, id);
        if (!c) continue;
        if (!TestBitAt0x34(self->bitsPtr, id & 0xff)) continue;
        if (clear) {
            _ZN8Object3D11MakeVisibleEv((unsigned char*)c);
            SetSubstructByte0x56((unsigned char*)c);
        } else {
            _ZN8Object3D10MakeHiddenEv((unsigned char*)c);
            ClearSubstructByte0x56((unsigned char*)c);
        }
    }
}
