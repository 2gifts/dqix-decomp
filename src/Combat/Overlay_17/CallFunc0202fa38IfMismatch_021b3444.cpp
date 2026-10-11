#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

struct Obj150_021b354c;
unsigned char GetSubByteField56e_021b354c(Obj150_021b354c* obj);
extern "C" void func_02072afc(int id, int* arr, short* arr2);

extern int data_020f2a38;
extern int data_020f2a30;

struct Obj_021b3444 {
    unsigned char pad0[8];
    short id;
    unsigned char pad1;
    unsigned char flagByte;
    unsigned char pad2[4];
    int result;
};

// JPN: func_ov017_021b3b4c
// USA: func_ov017_021b3444  (semantic: CallFunc0202fa38IfMismatch_021b3444)
extern "C" ARM int func_ov017_021b3444(struct Obj_021b3444* obj) {
    GameState* bs = GameState::GetInstance();
    int field4 = (int)BackgroundLoader::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100(bs, obj->id);
    if (combatant != 0) {
        if (GetSubByteField56e_021b354c((Obj150_021b354c*)combatant) != 0) {
#if defined(jpn)
            obj->result = ((BackgroundLoader*)(field4))->QueueLoadGP1((const char*)(data_020f2a38), (SafeAllocator*)(0));
#else
            obj->result = ((BackgroundLoader*)(field4))->QueueLoadFileInGP2((const char*)(data_020f2a38), (const char*)(data_020f2a30), (SafeAllocator*)(0));
#endif
            return 1;
        }
    }

    int arr1[11];
    short arr2[11];
    func_02072afc(obj->id, arr1, arr2);
    int flag = obj->flagByte & 1;

    int i;
    for (i = 0; i < 0xb; i++) {
        GameObject* c = bs->GetGameObjectByIndex(arr1[i]);
        if (c == 0) {
            continue;
        }
        short* p2 = (short*)((char*)c + 0x2);
        if (flag) {
            *p2 = -1;
        }
        short bVal = arr2[i];
        short aVal = *p2;
        if (bVal == aVal) {
            continue;
        }
#if defined(jpn)
        obj->result = ((BackgroundLoader*)(field4))->QueueLoadGP1((const char*)(data_020f2a38), (SafeAllocator*)(0));
#else
        obj->result = ((BackgroundLoader*)(field4))->QueueLoadFileInGP2((const char*)(data_020f2a38), (const char*)(data_020f2a30), (SafeAllocator*)(0));
#endif
        return 1;
    }
    return 0;
}
