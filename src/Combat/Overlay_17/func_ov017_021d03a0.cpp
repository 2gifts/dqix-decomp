// JPN: func_ov017_021d0850
#if defined(jpn)
enum { RegionOffset4355 = 0x4135 };
#else
enum { RegionOffset4355 = 0x4355 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_020dc548(int a, signed char* arr, signed char* count);
extern "C" void _ZN8Object3D10EnableFlagEi(unsigned char* obj, unsigned int mask);
void SetFlags0x1ce(unsigned char* obj, unsigned int mask);
extern "C" void _ZN8Object3D11DisableFlagEi(unsigned char* obj, unsigned int mask);
int GetByteFieldMasked0x1ce(void* obj, int mask);
void ClearFlags0x1ce(unsigned char* obj, unsigned int mask);

struct TagObj_021d03a0 {
    unsigned char pad0[4];
    unsigned char flag4;
    unsigned char id5;
    unsigned char flag6;
};

// USA: func_ov017_021d03a0
extern "C" ARM void func_ov017_021d03a0(int bit, struct TagObj_021d03a0* tag, GameState* battleStruct, unsigned char* base) {
    GameObject* combatant;
    GameObject* c2;
    signed char arr[7];
    signed char count;
    int i;

    combatant = battleStruct->GetPartyMemberByIndex(tag->id5);
    if (combatant == 0) {
        return;
    }
    if (tag->flag4 != 0) {
        _ZN8Object3D10EnableFlagEi((unsigned char*)combatant, 0x400);
        if (tag->flag6 != 0) {
            SetFlags0x1ce((unsigned char*)combatant, 0x20);
        }
        return;
    }

    func_020dc548((signed char)bit, arr, &count);
    for (i = 0; i < count; i++) {
        c2 = battleStruct->GetPartyMemberByIndex(arr[i]);
        if (c2 != 0) {
            _ZN8Object3D11DisableFlagEi((unsigned char*)c2, 0x400);
            if (GetByteFieldMasked0x1ce((void*)c2, 0x20) != 0) {
                ClearFlags0x1ce((unsigned char*)c2, 0x20);
                *(base + RegionOffset4355) |= 1 << (bit & 0xff);
            }
        }
    }
}
