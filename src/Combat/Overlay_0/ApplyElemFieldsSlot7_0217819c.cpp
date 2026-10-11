#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x28
#define REGION_OFFSET_1 0x800
#else
#define REGION_OFFSET_0 0x5c
#define REGION_OFFSET_1 0x960
#endif

#include "std_library_functions.h"

struct Struct0217f8c0;
void* FindMatchingTableEntry0217f8c0(struct Struct0217f8c0* s);
extern "C" void func_ov000_021781f8(void*, void*);
int GetGlobalField0x1c020421a0();
extern "C" void func_ov000_0217831c(void*, void*);
struct StructA0205d5d0;
#if defined(jpn)
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0*, int, int, int);
#else
int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);
#endif

// USA: func_ov000_0217819c
ARM void ApplyElemFieldsSlot7_0217819c(void* obj) {
    void* entry = FindMatchingTableEntry0217f8c0((struct Struct0217f8c0*)obj);
    func_ov000_021781f8(obj, entry);
    void* buf = *(void**)(GetGlobalField0x1c020421a0() + REGION_OFFSET_0);
    memset(buf, 0, REGION_OFFSET_1);
    func_ov000_0217831c(obj, buf);
#if defined(jpn)
    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)((char*)obj + 0x188), 7, (int)buf, 1);
#else
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x188), 7, (int)buf, 1, 0);
#endif
}
