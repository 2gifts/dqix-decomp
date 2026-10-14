#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "System/OverlayId.h"

struct AllocatorUnion;
struct Obj020397cc;
struct Obj020d7aa0;
struct SearchStruct;
struct Layout02189284;
struct Manager0218936c;

extern "C" SearchStruct* func_0202ae18(void);
void CancelPendingAction020397cc(Obj020397cc* obj, int flag);
void SetBitsInField4_0203b4d8(unsigned int* field, unsigned int bits);
void ClearBitsInField4_0203b4e8(unsigned int* field, unsigned int bits);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void func_020a0c0c(void);
void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
Obj020d7aa0* GetGlobalResetObj020d7a50();
void TeardownAndResetState020d7aa0(Obj020d7aa0* obj);
void PushInputLogB_020a1ef0(int value);
void PopStack1AndTrigger_020a1f4c(int value);
extern "C" void func_020a1940(unsigned int id);
extern "C" void func_ov008_02188f5c(void* scene, int index, int arg);
void SetupAllocators_02189284(Layout02189284* layout, SafeAllocator* allocator);
unsigned char Dispatch0218936c(Manager0218936c* manager, unsigned int ticks);
int TestFlagBitAt0xe_0202c578(SearchStruct* search, int index);
extern "C" void func_ov008_0218b240(void* scene);
extern "C" void func_ov008_021894b8(void* scene);
void SetByteField0x253_020397c0(void* obj);
extern char data_02114e20;

struct Scene021a9768 {
    char pad[0x14];
    int planes;
};

struct Task021a9768 {
    char pad0;
    unsigned char failed;
    char pad1[8 - 2];
    unsigned char step;
    char pad2[0xc - 9];
    SafeAllocator allocator;
    Scene021a9768* scene;
    signed char index;
    char pad3[0x54 - 0x25];
    int f54;
};

extern "C" void func_ov017_021a9714(Task021a9768* task);

// USA: func_ov017_021a9768
extern "C" ARM void func_ov017_021a9768(Task021a9768* task) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = func_ov017_0218b5b0();
    GameObject* unknown = gs->GetUnknownGameObject();
    SearchStruct* search = func_0202ae18();
    CancelPendingAction020397cc((Obj020397cc*)unknown, 1);
    SetBitsInField4_0203b4d8((unsigned int*)res, 0xc0);
    if (task->step == 0) {
#if defined(jpn)
        func_020a0cc4(0x1c704);
        void* buffer = AllocateAligned4_02012d88((AllocatorUnion*)&data_02114e20, 0x1c704);
#else
        func_020a0cc4(0x1c70c);
        void* buffer = AllocateAligned4_02012d88((AllocatorUnion*)&data_02114e20, 0x1c70c);
#endif
        if (buffer == NULL) {
            func_020a0c0c();
            task->failed = 1;
            return;
        }
        TeardownAndResetState020d7aa0(GetGlobalResetObj020d7a50());
#if defined(jpn)
        task->allocator.CreateTypeA(buffer, 0x1c704);
#else
        task->allocator.CreateTypeA(buffer, 0x1c70c);
#endif
        task->allocator.Reset();
        PushInputLogB_020a1ef0(1);
        func_020a1940(OVERLAY_ID(8));
#if defined(jpn)
        task->scene = (Scene021a9768*)task->allocator.Allocate(0xec4);
#else
        task->scene = (Scene021a9768*)task->allocator.Allocate(0xecc);
#endif
        if (task->f54 == 0) {
            func_ov008_02188f5c(task->scene, task->index, 0);
        } else {
            func_ov008_02188f5c(task->scene, -1, task->f54);
        }
        SetupAllocators_02189284((Layout02189284*)task->scene, &task->allocator);
        task->step++;
        return;
    }
    if (task->step == 1) {
        if (Dispatch0218936c((Manager0218936c*)task->scene, gs->GetTickCount())) {
            task->step++;
        }
        if (TestFlagBitAt0xe_0202c578(search, 0)) {
            func_ov008_0218b240(task->scene);
        }
        int valid = 0;
        if (task->index >= 0 && task->index <= 3) {
            valid = 1;
        }
        if (!valid) {
            return;
        }
        if (gs->GetGameObjectByIndex(task->index) != NULL && !TestFlagBitAt0xe_0202c578(search, task->index)) {
            return;
        }
        func_ov008_0218b240(task->scene);
        return;
    }
    if (task->step == 2) {
        func_ov008_021894b8(task->scene);
        task->step++;
        return;
    }
    if (task->step != 3) {
        return;
    }
    SetByteField0x253_020397c0(GameState::GetInstance()->GetUnknownGameObject());
    *(volatile unsigned int*)0x4000000 = (task->scene->planes << 8) | (*(volatile unsigned int*)0x4000000 & ~0x1f00);
    task->scene = NULL;
    PopStack1AndTrigger_020a1f4c(1);
    func_ov017_021a9714(task);
    func_020a0c0c();
    ClearBitsInField4_0203b4e8((unsigned int*)res, 0x80);
    task->failed = 1;
}
