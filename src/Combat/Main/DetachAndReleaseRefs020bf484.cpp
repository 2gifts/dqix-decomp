#include <globaldefs.h>

struct Mutex;
int LockMutex(Mutex*);
extern "C" void func_020bf1a0(void* entry);

struct BattleTarget9a8;
void ClearTargetMask_020bc9a8(struct BattleTarget9a8* obj);

struct RefNode020c80f8;
void UnlockMutex(Mutex*);

struct Ctx0211_020bf484 { int f0; unsigned char* f4; };
extern struct Ctx0211_020bf484 data_021103b0;
extern int data_02110a28;

struct Ctx020bf484 {
    char pad0[0x120];
    int count0x120;
    unsigned char flag0x124;
    char pad1[0x12c - 0x125];
    int field0x12c;
    int field0x130;
};

// USA: func_020bf484
ARM void DetachAndReleaseRefs020bf484(int expected, void* unused1, struct Ctx020bf484* obj) {
    if (expected != obj->field0x12c) {
        return;
    }

    LockMutex((Mutex*)&data_02110a28);
    if (data_021103b0.f4 != 0) {
        LockMutex((Mutex*)(data_021103b0.f4 + 0x4c8));
    }

    func_020bf1a0(obj);
    obj->field0x12c = 0;
    obj->field0x130 = 0;
    obj->flag0x124 = 0;
    if (obj->count0x120 > 0) {
        ClearTargetMask_020bc9a8((struct BattleTarget9a8*)obj);
        obj->count0x120 = 0;
    }

    UnlockMutex((Mutex*)&data_02110a28);
    if (data_021103b0.f4 != 0) {
        UnlockMutex((Mutex*)(data_021103b0.f4 + 0x4c8));
    }
}
