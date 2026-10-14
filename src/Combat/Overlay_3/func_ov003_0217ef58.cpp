#include <globaldefs.h>
#if defined(jpn)
enum { kRegion1414 = 0x12a4 };
#else
enum { kRegion1414 = 0x1414 };
#endif
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "Resource/GameResources.h"

struct Obj020397cc;

struct Scene0217ef58 {
    char pad0[4];
    short kind;
    char pad6[4];
    short id;
};

struct Obj0217ef58 {
    char pad0;
    unsigned char done;
    char pad2[6];
    int id;
    Scene0217ef58* scene;
    int state;
    SafeAllocator allocator;
    char pad28[2];
    char controlBackup[0x10];
};

extern "C" void func_02074af4(void* obj);
void SetBitsInField4_0203b4d8(unsigned int* obj, unsigned int mask);
void ClearBitsInField4_0203b4e8(unsigned int* obj, unsigned int mask);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void func_020a0c0c(void);
void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
extern "C" void VectorizedMemset(void* dst, int val, unsigned int len);
void PushInputLogA_020a1df8(int id);
extern "C" void func_ov003_0216d63c(Scene0217ef58* scene);
extern "C" void func_ov003_0216ae0c(Scene0217ef58* scene, SafeAllocator* allocator);
extern "C" int func_ov003_0216af14(Scene0217ef58* scene);
void CancelPendingAction020397cc(Obj020397cc* obj, int arg1);
int GetFieldIfFlag4_020100f8(char* obj);
void ClearIntAt0x23c_020a27b8(unsigned char* obj);
extern "C" int func_ov017_021959b4(void);
extern "C" void func_ov003_0217f194(Obj0217ef58* obj);
extern "C" void func_ov003_0217f118(Obj0217ef58* obj);
void SetByteField0x253_020397c0(void* obj);
void SetField0x23cTrue_020a27ac(void* obj);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);
void InitObjAndClearFlags_0217f1b8(unsigned char* obj);
extern AllocatorUnion data_02114e20;

// USA: func_ov003_0217ef58
extern "C" ARM void func_ov003_0217ef58(Obj0217ef58* self) {
    GameState* gs = GameState::GetInstance();

    if (self->state == 0) {
        func_02074af4(self->controlBackup);
        SetBitsInField4_0203b4d8((unsigned int*)func_ov017_0218b5b0(), 0xc0);
        func_020a0cc4(0x1e800);
        void* buffer = AllocateAligned4_02012d88(&data_02114e20, 0xb000);
        if (buffer == 0) {
            func_020a0c0c();
            self->done = 1;
            return;
        }
        VectorizedMemset(buffer, 0, 0xb000);
        self->allocator.CreateTypeA(buffer, 0xb000);
        self->allocator.Reset();
        self->scene = (Scene0217ef58*)self->allocator.Allocate(kRegion1414);
        if (self->scene == 0) {
            func_020a0c0c();
            self->done = 1;
            return;
        }
        PushInputLogA_020a1df8(3);
        func_ov003_0216d63c(self->scene);
        func_ov003_0216ae0c(self->scene, &self->allocator);
        self->scene->id = self->id;
        CancelPendingAction020397cc((Obj020397cc*)gs->GetUnknownGameObject(), 1);
        ClearIntAt0x23c_020a27b8((unsigned char*)GetFieldIfFlag4_020100f8((char*)gs));
        self->state = 1;
    } else if (self->state == 1) {
        if (func_ov003_0216af14(self->scene) == 0) {
            self->state = 2;
        }
        func_ov017_021959b4();
        if (func_ov017_021959b4() != 0 && self->scene->kind != 5) {
            func_ov003_0217f194(self);
            self->state = 3;
        }
    } else if (self->state == 2) {
        func_ov003_0217f118(self);
        SetByteField0x253_020397c0(gs->GetUnknownGameObject());
        int flags = GetFieldIfFlag4_020100f8((char*)gs);
        SetField0x23cTrue_020a27ac((void*)flags);
        ClearFlagBits_020a28b0((unsigned char*)flags, 2);
        ClearBitsInField4_0203b4e8((unsigned int*)func_ov017_0218b5b0(), 0xc0);
        self->state = -1;
    } else if (self->state == 3) {
        if (func_ov003_0216af14(self->scene) == 0) {
            InitObjAndClearFlags_0217f1b8((unsigned char*)self);
        }
    }
}
