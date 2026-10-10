#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

struct Cont0207fe44;
struct Container0205a3d0;
struct Elem0205a3d0 {
    char pad0[0x15];
    unsigned char flags;
};
struct Struct020a9ea4;
struct Obj020397cc;
struct FlagWord020466f4;

struct Global02109030 {
    unsigned char pad_0x0[0x3c9];
    unsigned char flag3c9 : 1;
};

struct Battle02165278 {
    char pad0[0x324];
    struct Cont0207fe44* model;
    char pad328[0x38c - 0x328];
    struct Container0205a3d0* container;
    char pad390[0x464 - 0x390];
    unsigned int flags;
    char pad468[0x484 - 0x468];
    short field484;
    short field486;
    short field488;
    char pad48a[0x4a3 - 0x48a];
    unsigned char code;
    unsigned char step;
};

void* GetDataPtr02114e04_020d6c00(void);
Global02109030* GetGlobal02109030(void);
extern "C" void func_ov003_021612c0(struct Battle02165278* obj);
extern "C" int func_ov003_02161344(struct Battle02165278* obj);
void CallFunc0204c804OverAllElems(struct Cont0207fe44* model);
void OrBitsIntoField0(unsigned int* p, unsigned int mask);
void ClearStruct020a9ea4(struct Struct020a9ea4* p);
extern "C" int func_020aad1c(void* a, void* b, int c, int d);
extern int data_0211e33c;
struct Elem0205a3d0* FindEntryByHalfword0205a3d0(struct Container0205a3d0* c, int key);
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
void ResetAndSetFlag0x3c9Bit0_020939dc(void* p);
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg);
extern "C" void func_ov017_021c35ac(void);

// USA: func_ov003_02165278
extern "C" ARM void func_ov003_02165278(struct Battle02165278* obj) {
    void* data = GetDataPtr02114e04_020d6c00();
    Global02109030* global = GetGlobal02109030();
    unsigned char step = obj->step;
    struct Cont0207fe44* model = obj->model;

    if (step == 0xb) {
        obj->field484 = 0x19;
        obj->step++;
    } else if (step == 0xc) {
        func_ov003_021612c0(obj);
        obj->step++;
    } else if (step == 0xd) {
        int result = func_ov003_02161344(obj);
        if (result != -1) {
            if (result != 1) {
                return;
            }
            CallFunc0204c804OverAllElems(model);
            obj->field484 = 0x1a;
            obj->step++;
            global->flag3c9 = 0;
        } else {
            obj->field488 = -1;
            obj->field484 = 0x3b;
            obj->field486 = 1;
            CallFunc0204c804OverAllElems(model);
            obj->code = 10;
            obj->step = 0;
        }
    } else if (step == 0xe) {
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() != 0) {
            return;
        }
        OrBitsIntoField0((unsigned int*)GetDataPtr02114e04_020d6c00(), 0x80);
        ClearStruct020a9ea4((struct Struct020a9ea4*)((char*)obj + 0x4b4));
        obj->step++;
    } else if (step == 0xf) {
        obj->flags |= 0x2000000;
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        if (func_020aad1c((char*)obj + 0x4b4, &data_0211e33c, 10, 0) == 1) {
            struct Elem0205a3d0* entry = FindEntryByHalfword0205a3d0(obj->container, 0);
            if (entry != NULL) {
                entry->flags |= 8;
            }
            entry = FindEntryByHalfword0205a3d0(obj->container, 1);
            if (entry != NULL) {
                entry->flags &= ~8;
            }
            obj->flags &= ~0x2000000;
            obj->field484 = 0x30;
            obj->step++;
            ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0x80);
        }
        BackgroundLoader::RemoveLockGlobal();
    } else if (step == 0x10) {
        func_ov017_021c35ac();
        ResetAndSetFlag0x3c9Bit0_020939dc(global);
        ClearFlags020466f4((struct FlagWord020466f4*)data, 0x20);
        obj->field484 = 0x1b;
        obj->step++;
        GameObject* protagonist = GameState::GetInstance()->GetProtagonist();
        if (protagonist == NULL) {
            return;
        }
        CancelPendingAction020397cc((struct Obj020397cc*)protagonist, 1);
    } else if (step == 0x11) {
        func_ov003_021612c0(obj);
        obj->step++;
    } else if (step == 0x12) {
        int result = func_ov003_02161344(obj);
        if (result != -1) {
            if (result != 1) {
                return;
            }
            obj->field484 = 0x1c;
            obj->code = 0x10;
            obj->step = 0;
        } else {
            obj->field484 = 0x1d;
            obj->code = 0x10;
            obj->step = 0;
        }
    }
}
