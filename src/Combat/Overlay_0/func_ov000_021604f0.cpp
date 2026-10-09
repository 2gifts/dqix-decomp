#include <globaldefs.h>
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
    SafeAllocator allocators[5];
    char pad6c[0xec8 - 0x6c];
    char zone[0x3760 - 0xec8];
    char field_3760[0x55cc - 0x3760];
    void* scene;
    char pad55d0[0x55f4 - 0x55d0];
    int flags;
    char pad55f8[0x7711 - 0x55f8];
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
    for (int i = 0; i < 5; i++) {
        if (work->allocators[i].GetSignedAllocator() != NULL) {
            work->allocators[i].Destroy();
        }
    }
}
