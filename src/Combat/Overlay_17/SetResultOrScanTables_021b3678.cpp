// JPN: func_ov017_021b3d6c
#if defined(jpn)
enum { RegionOffset150 = 0x144 };
#else
enum { RegionOffset150 = 0x150 };
#endif

#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

struct Obj150_021b354c;
unsigned char GetSubByteField56e_021b354c(Obj150_021b354c* obj);
int GetFieldAt0x150(unsigned char* obj);

extern int data_ov017_021d7ab6;
extern short data_ov017_021d6b56;
extern short data_ov017_021d6b54;

struct Obj_021b3678 {
    unsigned char pad0[8];
    short id;
    unsigned char pad1[4];
    int result;
};

// USA: func_ov017_021b3678  (semantic: SetResultOrScanTables_021b3678)
extern "C" ARM int func_ov017_021b3678(struct Obj_021b3678* obj) {
    GameState* bs = GameState::GetInstance();
    int field4 = (int)BackgroundLoader::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100(bs, obj->id);
    if (!combatant) {
        return 0;
    }
    if (!GetFieldAt0x150((unsigned char*)combatant)) {
        return 0;
    }

    if (GetSubByteField56e_021b354c((Obj150_021b354c*)combatant)) {
        char* sub = *(char**)((char*)combatant + RegionOffset150);
        if (sub) {
            *(unsigned char*)(sub + 0x56e) = 0;
        }
        obj->result = ((BackgroundLoader*)(field4))->QueueLoadFile((const char*)((int)&data_ov017_021d7ab6), (SafeAllocator*)(0));
        return 1;
    }

    char* subBase = *(char**)((char*)combatant + RegionOffset150);
    char* arrA = subBase + 0x194;
    char* arrB = subBase + 0x2f4;
    unsigned char i;
    for (i = 0; i < 8; i = (i + 1) & 0xff) {
        short t2 = *(short*)((char*)&data_ov017_021d6b54 + i * 4);
        if (t2 < 0) {
            continue;
        }
        short t1 = *(short*)((char*)&data_ov017_021d6b56 + i * 4);
        short valA = *(short*)(arrA + t2 * 0x20 + 0x18);
        short valB = *(short*)(arrB + t1 * 0x2c + 0x28);
        if (valA == valB) {
            continue;
        }
        obj->result = ((BackgroundLoader*)(field4))->QueueLoadFile((const char*)((int)&data_ov017_021d7ab6), (SafeAllocator*)(0));
        return 1;
    }
    return 1;
}
