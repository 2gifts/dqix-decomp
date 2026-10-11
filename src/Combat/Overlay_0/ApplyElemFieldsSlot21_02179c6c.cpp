#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x28
#define REGION_OFFSET_1 0x800
#else
#define REGION_OFFSET_0 0x5c
#define REGION_OFFSET_1 0x960
#endif

#include "std_library_functions.h"

int GetGlobalField0x1c020421a0();
struct Struct0217f8c0;
struct TableEntry0217f8c0;
struct TableEntry0217f8c0* FindMatchingTableEntry0217f8c0(struct Struct0217f8c0* s);
extern "C" void func_ov000_02179cdc(void* obj, int id);
extern "C" void func_ov000_02179ed8(void* obj, void* entry, void* buf);
struct StructA0205d5d0;
#if defined(jpn)
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0*, int, int, int);
#else
int TryApplyElemFields0205d5d0(struct StructA0205d5d0*, int, int, int, unsigned char);
#endif

// USA: func_ov000_02179c6c
ARM void ApplyElemFieldsSlot21_02179c6c(void* obj, int id) {
    void* entry = FindMatchingTableEntry0217f8c0((struct Struct0217f8c0*)obj);
    func_ov000_02179cdc(obj, id);
    void* buf = *(void**)(GetGlobalField0x1c020421a0() + REGION_OFFSET_0);
    memset(buf, 0, REGION_OFFSET_1);
    func_ov000_02179ed8(obj, entry, buf);
#if defined(jpn)
    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)((char*)obj + 0x188), 0x15, (int)buf, 1);
#else
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x188), 0x15, (int)buf, 1, 0);
#endif
}
