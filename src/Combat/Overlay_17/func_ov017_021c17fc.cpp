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

void CancelPendingAction020397cc(Obj020397cc* obj, int flag);
void SetBitsInField4_0203b4d8(unsigned int* field, unsigned int bits);
void ClearBitsInField4_0203b4e8(unsigned int* field, unsigned int bits);
int GetFieldIfFlag4_020100f8(char* obj);
void SetFlagsAt0x244_020a28a0(unsigned char* obj, unsigned char mask);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);
void SetByteField0x253_020397c0(void* obj);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void func_020a0c0c(void);
void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_020a1940(unsigned int id);
void PushInputLogA_020a1df8(int value);
void PushInputLogB_020a1ef0(int value);
extern "C" void func_ov012_021843d4(void* scene);
extern "C" void func_ov012_02184884(void* scene, SafeAllocator* allocator);
extern "C" int func_ov012_02184acc(void* scene, unsigned int tick);
extern "C" void func_ov012_02185af0(void* scene);
void SetCombatModeFromCase020dc2d0(int mode);
void CancelActionAndInsertNode_021a5530(char* obj);
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
    CancelPendingAction020397cc((Obj020397cc*)unknown, 1);
    SetBitsInField4_0203b4d8((unsigned int*)res, 0xc0);
    unsigned char* flags = (unsigned char*)GetFieldIfFlag4_020100f8((char*)gs);
    SetFlagsAt0x244_020a28a0(flags, 3);
    if (task->step == 0) {
        func_020a0cc4(ArenaSize);
        void* buffer = AllocateAligned4_02012d88((AllocatorUnion*)&data_02114e20, ArenaSize);
        if (buffer == NULL) {
            func_020a0c0c();
            task->failed = 1;
            return;
        }
        task->allocator.CreateTypeA(buffer, ArenaSize);
        task->allocator.Reset();
#if !defined(jpn)
        if (task->restore) {
            PushInputLogA_020a1df8(3);
        }
#endif
        func_020a1940(OVERLAY_ID(12));
        PushInputLogB_020a1ef0(1);
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
    SetCombatModeFromCase020dc2d0(0);
    if (task->restore) {
        if (ready) {
            SetByteField0x253_020397c0(unknown);
            ClearFlagBits_020a28b0(flags, 3);
            ClearBitsInField4_0203b4e8((unsigned int*)res, 0xc0);
        } else {
            CancelActionAndInsertNode_021a5530((char*)res);
        }
    } else {
        func_ov017_0218d77c(res, 1);
    }
    func_020a0c0c();
    task->failed = 1;
}
