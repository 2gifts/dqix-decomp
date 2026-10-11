#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "System/OverlayId.h"

#include "Resource/GameResources.h"

struct Obj_02243690;

extern "C" void func_020a1940(unsigned int id);
extern "C" void func_ov031_02243518(void* state, int mode);
void RunStateTableEntry_02243690(Obj_02243690* obj);
void ShutdownAndReinit0205e92c(void* obj);
void ResetAndReinit0209c278(void* obj);
void Dispatch0203a974With0x57000(void* obj);
void SetupContextForMode0205ea20(void* obj, int mode);
extern char data_02108760;
extern char data_02109bf4;

struct State021b1e24 {
    char pad0[0x28];
    SafeAllocator* allocator;
    char pad1[0x30 - 0x2c];
    int done;
    char pad2[0x37c - 0x34];
    int f37c;
    int f380;
};

struct Task021b1e24 {
    char pad0;
    unsigned char failed;
    char pad1[8 - 2];
    SafeAllocator* heap;
    SafeAllocator allocator;
    unsigned char step;
    unsigned char mode;
    char pad2[0x24 - 0x22];
    State021b1e24* state;
    char pad3[0x32 - 0x28];
    unsigned char busy;
    char pad4;
    int f34;
    int f38;
};

static inline void SetPair(State021b1e24* state, int first, int second) {
    state->f37c = first;
    state->f380 = second;
}

// USA: func_ov017_021b1e24
extern "C" ARM void func_ov017_021b1e24(Task021b1e24* task) {
    GameState::GetInstance();
    func_ov017_0218b5b0();
    if (task->step == 0) {
        if (task->heap == NULL || task->busy != 0) {
            task->failed = 1;
            return;
        }
        task->state = (State021b1e24*)task->heap->Allocate(0xa3c);
        if (task->state == NULL) {
            task->failed = 1;
            return;
        }
        unsigned int size = task->heap->GetMaxPossibleAllocation();
        task->allocator.CreateTypeA(task->heap->Allocate(size), size);
        task->allocator.Reset();
        ShutdownAndReinit0205e92c(&data_02108760);
        ResetAndReinit0209c278(&data_02109bf4);
        func_020a1940(OVERLAY_ID(31));
        func_ov031_02243518(task->state, task->mode);
        task->state->allocator = &task->allocator;
        SetPair(task->state, task->f34, task->f38);
        RunStateTableEntry_02243690((Obj_02243690*)task->state);
        task->step++;
        return;
    }
    if (task->step != 1) {
        return;
    }
    RunStateTableEntry_02243690((Obj_02243690*)task->state);
    if (task->state->done == 0) {
        return;
    }
    func_020a1940(OVERLAY_ID(32));
    ResetAndReinit0209c278(&data_02109bf4);
    Dispatch0203a974With0x57000(&data_02109bf4);
    ShutdownAndReinit0205e92c(&data_02108760);
    SetupContextForMode0205ea20(&data_02108760, 100);
    SignedAllocatorHeader* block = task->allocator.GetSignedAllocator();
    if (block != NULL) {
        task->allocator.Destroy();
        task->heap->Free(block);
    }
    task->failed = 1;
}
