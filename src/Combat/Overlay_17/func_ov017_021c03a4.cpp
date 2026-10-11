#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "System/OverlayId.h"

struct AllocatorUnion;
struct Obj020979c0;

extern "C" void func_020a0cc4(unsigned int size);
extern "C" void func_020a0c0c(void);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void _Z18InitStruct020979c0P11Obj020979c0h(Obj020979c0* obj, unsigned char flag);
extern "C" void func_020a1940(unsigned int id);
void PushInputLogB(int value);
void PopStack1AndTrigger(int value);
extern "C" void func_ov014_02186a70(void* obj);
extern "C" void func_ov014_021868b8(void* obj, SafeAllocator* allocator);
extern "C" int func_ov014_02186bc8(void* obj, unsigned int tick);
extern "C" void func_ov014_02186b30(void* obj);
extern "C" int func_02097a04(void* obj);
extern "C" void func_02097b34(void* obj);
extern char data_02114e20;

struct Task021c03a4 {
    char pad0;
    unsigned char failed;
    char pad1[8 - 2];
    SafeAllocator allocator;
    void* f1c;
    void* f20;
    unsigned char step;
};

extern "C" void func_ov017_021c0364(Task021c03a4* task);

// USA: func_ov017_021c03a4
extern "C" ARM void func_ov017_021c03a4(Task021c03a4* task) {
    if (task->step == 0) {
        *(unsigned short*)0x4000304 |= 0x8000;
        func_020a0cc4(0x3f000);
        void* buffer = AllocateAligned4((AllocatorUnion*)&data_02114e20, 0x3f000);
        if (buffer == NULL) {
            func_020a0c0c();
            task->failed = 1;
            return;
        }
        task->allocator.CreateTypeA(buffer, 0x3f000);
        task->allocator.Reset();
        task->f1c = task->allocator.Allocate(0x20);
        task->f20 = task->allocator.Allocate(0x194);
        if (task->f1c == NULL || task->f20 == NULL) {
            func_020a0c0c();
            task->failed = 1;
            return;
        }
        _Z18InitStruct020979c0P11Obj020979c0h((Obj020979c0*)task->f1c, 1);
        func_020a1940(OVERLAY_ID(14));
        PushInputLogB(1);
        func_ov014_02186a70(task->f20);
        func_ov014_021868b8(task->f20, &task->allocator);
        task->step++;
        return;
    }
    if (task->step == 1) {
        if (func_02097a04(task->f1c)) {
            task->step++;
        }
        return;
    }
    if (task->step == 2) {
        if (func_ov014_02186bc8(task->f20, GameState::GetInstance()->GetTickCount())) {
            task->step++;
        }
        return;
    }
    if (task->step != 3) {
        return;
    }
    func_ov014_02186b30(task->f20);
    func_02097b34(task->f1c);
    func_ov017_021c0364(task);
    func_020a0c0c();
    PopStack1AndTrigger(1);
    task->failed = 1;
}
