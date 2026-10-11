#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0xe44
#define REGION_OFFSET_1 0x58
#define REGION_OFFSET_2 0x371c
#define REGION_OFFSET_3 0x57bc
#define REGION_OFFSET_4 0x57c0
#define REGION_OFFSET_5 0x57e4
#define REGION_OFFSET_6 0x57e8
#define REGION_OFFSET_7 0x7901
#define REGION_ALLOCATOR_COUNT 4
#else
#define REGION_OFFSET_0 0xec8
#define REGION_OFFSET_1 0x6c
#define REGION_OFFSET_2 0x3760
#define REGION_OFFSET_3 0x55cc
#define REGION_OFFSET_4 0x55d0
#define REGION_OFFSET_5 0x55f4
#define REGION_OFFSET_6 0x55f8
#define REGION_OFFSET_7 0x7711
#define REGION_ALLOCATOR_COUNT 5
#endif

#include "Memory/SafeAllocator.h"

extern "C" void _Z25ForwardField0xc0_0205eb80Pv(void* obj);
extern "C" void _Z22ResetBigStruct02013750Pvi(void* obj, int flag);
extern "C" void func_ov000_02172720(void* obj);
char* GetData02108e10(void);
extern "C" void _Z23ClearTwoRegions02079f9cPc(char* obj);
extern "C" void* func_02057924(void);
extern "C" void func_02057f00(void* obj, int index);
extern "C" void func_ov023_021eb26c(void* obj);

extern char data_02108760[];
extern int data_ov000_02182fe0[];

struct CombatWork_021604f0 {
    char pad0[8];
    SafeAllocator allocators[REGION_ALLOCATOR_COUNT];
    char pad6c[REGION_OFFSET_0 - REGION_OFFSET_1];
    char zone[REGION_OFFSET_2 - REGION_OFFSET_0];
    char field_3760[REGION_OFFSET_3 - REGION_OFFSET_2];
    void* scene;
    char pad55d0[REGION_OFFSET_5 - REGION_OFFSET_4];
    int flags;
    char pad55f8[REGION_OFFSET_7 - REGION_OFFSET_6];
    unsigned char displayActive;
};

// USA: func_ov000_021604f0
extern "C" ARM void func_ov000_021604f0(struct CombatWork_021604f0* work) {
    if (work->displayActive) {
        _Z25ForwardField0xc0_0205eb80Pv(data_02108760);
        work->displayActive = 0;
    }
    _Z22ResetBigStruct02013750Pvi(work->zone, 1);
    if (!(work->flags & 0x800)) {
        func_ov000_02172720(work->field_3760);
    }
    _Z23ClearTwoRegions02079f9cPc(GetData02108e10());
    void* slots = func_02057924();
    for (int* p = data_ov000_02182fe0; *p >= 0; p++) {
        func_02057f00(slots, *p);
    }
    if (work->scene != NULL) {
        func_ov023_021eb26c(work->scene);
    }
    for (int i = 0; i < REGION_ALLOCATOR_COUNT; i++) {
        if (work->allocators[i].GetSignedAllocator() != NULL) {
            work->allocators[i].Destroy();
        }
    }
}
