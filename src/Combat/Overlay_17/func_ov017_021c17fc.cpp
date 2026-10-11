// JPN: func_ov017_021c1da4
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "System/OverlayId.h"

#if defined(jpn)
enum { ArenaSize = 0x2d0fc, ScenePlanes = 0x14, SceneReady = 0x14f8, SceneSize = 0x14fc };
#else
enum { ArenaSize = 0x2e4c0, ScenePlanes = 0x1c, SceneReady = 0x14bc, SceneSize = 0x14c0 };
#endif

struct AllocatorUnion;
struct Obj020397cc;

extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(Obj020397cc* obj, int flag);
void SetBitsInField4(unsigned int* field, unsigned int bits);
void ClearBitsInField4(unsigned int* field, unsigned int bits);
int GetFieldIfFlag4(char* obj);
void SetFlagsAt0x244(unsigned char* obj, unsigned char mask);
void ClearFlagBits(unsigned char* obj, int mask);
void SetByteField0x253(void* obj);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void func_020a0c0c(void);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_020a1940(unsigned int id);
void PushInputLogA(int value);
void PushInputLogB(int value);
extern "C" void func_ov012_021843d4(void* scene);
extern "C" void func_ov012_02184884(void* scene, SafeAllocator* allocator);
extern "C" int func_ov012_02184acc(void* scene, unsigned int tick);
extern "C" void func_ov012_02185af0(void* scene);
extern "C" void _Z29SetCombatModeFromCase020dc2d0i(int mode);
extern "C" void _Z34CancelActionAndInsertNode_021a5530Pc(char* obj);
extern "C" void func_ov017_0218d77c(GameResources* res, int flag);
extern char data_02114e20;

struct Scene021c17fc {
    char pad0[ScenePlanes];
    int planes;
    char pad1[SceneReady - ScenePlanes - 4];
    unsigned char ready;
};

struct Task021c17fc {
    char pad0;
    unsigned char failed;
    char pad1[8 - 2];
    SafeAllocator allocator;
    unsigned char step;
    unsigned char restore;
    char pad2[0x20 - 0x1e];
    Scene021c17fc* scene;
};

extern "C" void func_ov017_021c1a24(Task021c17fc* task);

// USA: func_ov017_021c17fc
extern "C" ARM void func_ov017_021c17fc(Task021c17fc* task) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = func_ov017_0218b5b0();
    GameObject* unknown = gs->GetUnknownGameObject();
    _Z27CancelPendingAction020397ccP11Obj020397cci((Obj020397cc*)unknown, 1);
    SetBitsInField4((unsigned int*)res, 0xc0);
    unsigned char* flags = (unsigned char*)GetFieldIfFlag4((char*)gs);
    SetFlagsAt0x244(flags, 3);
    if (task->step == 0) {
        func_020a0cc4(ArenaSize);
        void* buffer = AllocateAligned4((AllocatorUnion*)&data_02114e20, ArenaSize);
        if (buffer == NULL) {
            func_020a0c0c();
            task->failed = 1;
            return;
        }
        task->allocator.CreateTypeA(buffer, ArenaSize);
        task->allocator.Reset();
#if !defined(jpn)
        if (task->restore) {
            PushInputLogA(3);
        }
#endif
        func_020a1940(OVERLAY_ID(12));
        PushInputLogB(1);
        task->scene = (Scene021c17fc*)task->allocator.Allocate(SceneSize);
        func_ov012_021843d4(task->scene);
        func_ov012_02184884(task->scene, &task->allocator);
        task->step++;
        return;
    }
    if (task->step == 1) {
        if (func_ov012_02184acc(task->scene, gs->GetTickCount())) {
            task->step++;
        }
        return;
    }
    if (task->step == 2) {
        func_ov012_02185af0(task->scene);
        task->step++;
        return;
    }
    if (task->step != 3) {
        return;
    }
    unsigned char ready = task->scene->ready;
    *(volatile unsigned int*)0x4000000 = (task->scene->planes << 8) | (*(volatile unsigned int*)0x4000000 & ~0x1f00);
    func_ov017_021c1a24(task);
    _Z29SetCombatModeFromCase020dc2d0i(0);
    if (task->restore) {
        if (ready) {
            SetByteField0x253(unknown);
            ClearFlagBits(flags, 3);
            ClearBitsInField4((unsigned int*)res, 0xc0);
        } else {
            _Z34CancelActionAndInsertNode_021a5530Pc((char*)res);
        }
    } else {
        func_ov017_0218d77c(res, 1);
    }
    func_020a0c0c();
    task->failed = 1;
}
