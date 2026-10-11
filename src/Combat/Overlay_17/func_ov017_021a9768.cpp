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
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(Obj020397cc* obj, int flag);
void SetBitsInField4(unsigned int* field, unsigned int bits);
void ClearBitsInField4(unsigned int* field, unsigned int bits);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void func_020a0c0c(void);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" Obj020d7aa0* _Z25GetGlobalResetObj020d7a50v();
extern "C" void _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(Obj020d7aa0* obj);
void PushInputLogB(int value);
void PopStack1AndTrigger(int value);
extern "C" void func_020a1940(unsigned int id);
extern "C" void func_ov008_02188f5c(void* scene, int index, int arg);
extern "C" void _Z24SetupAllocators_02189284P14Layout02189284P13SafeAllocator(Layout02189284* layout, SafeAllocator* allocator);
extern "C" unsigned char _Z16Dispatch0218936cP15Manager0218936c(Manager0218936c* manager);
int TestFlagBitAt0xe(SearchStruct* search, int index);
extern "C" void func_ov008_0218b240(void* scene);
extern "C" void func_ov008_021894b8(void* scene);
void SetByteField0x253(void* obj);
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
// JPN: func_ov017_021a9f3c
extern "C" ARM void func_ov017_021a9768(Task021a9768* task) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = func_ov017_0218b5b0();
    GameObject* unknown = gs->GetUnknownGameObject();
    SearchStruct* search = func_0202ae18();
    _Z27CancelPendingAction020397ccP11Obj020397cci((Obj020397cc*)unknown, 1);
    SetBitsInField4((unsigned int*)res, 0xc0);
    if (task->step == 0) {
#if defined(jpn)
        func_020a0cc4(0x1c704);
        void* buffer = AllocateAligned4((AllocatorUnion*)&data_02114e20, 0x1c704);
#else
        func_020a0cc4(0x1c70c);
        void* buffer = AllocateAligned4((AllocatorUnion*)&data_02114e20, 0x1c70c);
#endif
        if (buffer == NULL) {
            func_020a0c0c();
            task->failed = 1;
            return;
        }
        _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(_Z25GetGlobalResetObj020d7a50v());
#if defined(jpn)
        task->allocator.CreateTypeA(buffer, 0x1c704);
#else
        task->allocator.CreateTypeA(buffer, 0x1c70c);
#endif
        task->allocator.Reset();
        PushInputLogB(1);
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
        _Z24SetupAllocators_02189284P14Layout02189284P13SafeAllocator((Layout02189284*)task->scene, &task->allocator);
        task->step++;
        return;
    }
    if (task->step == 1) {
        if (((unsigned char (*)(Scene021a9768*, unsigned int))_Z16Dispatch0218936cP15Manager0218936c)(task->scene, gs->GetTickCount())) {
            task->step++;
        }
        if (TestFlagBitAt0xe(search, 0)) {
            func_ov008_0218b240(task->scene);
        }
        int valid = 0;
        if (task->index >= 0 && task->index <= 3) {
            valid = 1;
        }
        if (!valid) {
            return;
        }
        if (gs->GetGameObjectByIndex(task->index) != NULL && !TestFlagBitAt0xe(search, task->index)) {
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
    SetByteField0x253(GameState::GetInstance()->GetUnknownGameObject());
    *(volatile unsigned int*)0x4000000 = (task->scene->planes << 8) | (*(volatile unsigned int*)0x4000000 & ~0x1f00);
    task->scene = NULL;
    PopStack1AndTrigger(1);
    func_ov017_021a9714(task);
    func_020a0c0c();
    ClearBitsInField4((unsigned int*)res, 0x80);
    task->failed = 1;
}
