#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02012fe4(void);
extern "C" void func_020dc548(int a, signed char* arr, signed char* count);

struct Obj_021bd3a4;
int HasFlag3orFlag2And9a_021bd3a4(struct Obj_021bd3a4* obj);
struct U16Field0x6_020375f8;
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);
extern "C" void _ZN8Object3D11MakeVisibleEv(unsigned char* obj);
extern "C" void _ZN8Object3D10MakeHiddenEv(unsigned char* obj);

struct TagObj_021bd4d0 {
    unsigned char pad0[0x16];
    unsigned short field16;
#if defined(jpn)
    unsigned char pad1[0xfd - 0x18];
#else
    unsigned char pad1[0x101 - 0x18];
#endif

    unsigned char field101;
};

// JPN: func_ov017_021bdac8
// USA: func_ov017_021bd4d0  (semantic: DispatchAndPropagateFlag_021bd4d0)
extern "C" ARM void func_ov017_021bd4d0(struct TagObj_021bd4d0* obj, int id, int clearFlag, int checkFlag2) {
    GameState* battleStruct;
    GameObject* combatant;
    GameObject* combatant2;
    signed char arr[7];
    signed char count;
    int i;
    int keep;
    unsigned short g;
    unsigned short u;

    battleStruct = GameState::GetInstance();
    combatant = battleStruct->GetPartyMemberByIndex(id);
    if (combatant != 0) {
        keep = 1;
        g = *(unsigned short*)func_02012fe4();
        u = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)combatant);
        if (u != g) {
            if (clearFlag == 0) {
                keep = 0;
            }
        }
        if (HasFlag3orFlag2And9a_021bd3a4((struct Obj_021bd3a4*)obj)) {
            if (obj->field16 == 0x2972 || obj->field101 == 0) {
                checkFlag2 = 0;
            }
        }
        if (keep != 0) {
            if (checkFlag2 == 0 || !HasFlag3orFlag2And9a_021bd3a4((struct Obj_021bd3a4*)obj)) {
                func_020dc548((signed char)id, arr, &count);
                for (i = 0; i < count; i++) {
                    combatant2 = battleStruct->GetPartyMemberByIndex(arr[i]);
                    if (combatant2 != 0) {
                        if (clearFlag) {
                            _ZN8Object3D11MakeVisibleEv((unsigned char*)combatant2);
                        } else {
                            _ZN8Object3D10MakeHiddenEv((unsigned char*)combatant2);
                        }
                    }
                }
            }
        }
    }
}
