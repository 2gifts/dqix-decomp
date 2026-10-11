#if defined(jpn)
#define R(j,u) (j)
#define _Z23EmptyDestructor0205cb60Pv func_0205deb8
#define _Z25ResetDisplayState02155480P11Obj02155480 func_ov006_02156b68
#define data_ov011_021889a0 data_ov011_02189700
#define data_ov013_02187dd8 data_ov013_02188cf0
#define func_ov006_02154fe4 func_ov006_02156730
#define func_ov006_021570fc func_ov006_02158704
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

// USA: func_ov013_02184cf0  (semantic: InitAllocators02184cf0)
extern "C" ARM void func_ov013_02184cf0(void* self, SafeAllocator* other) {
    if (other == 0) return;

    if (*(unsigned char*)((char*)self + R(0x5cc,0x640)) != 0) {
        void* buf = other->Allocate(0xc00);
        ((SafeAllocator*)((char*)self + R(0x598,0x60c)))->CreateTypeA(buf, 0xc00);
        return;
    }

    unsigned int maxAlloc = other->GetMaxPossibleAllocation();
    void* buf = other->Allocate(maxAlloc);
    ((SafeAllocator*)self)->CreateTypeA(buf, maxAlloc);
    ((SafeAllocator*)self)->Reset();
    void* buf2 = ((SafeAllocator*)self)->Allocate(0xc00);
    ((SafeAllocator*)((char*)self + R(0x598,0x60c)))->CreateTypeA(buf2, 0xc00);
}
