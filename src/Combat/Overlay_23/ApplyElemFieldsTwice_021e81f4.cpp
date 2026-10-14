#include <globaldefs.h>
#include "std_library_functions.h"

struct Container021e8cc0;
void CallAppendStringIfSet_021e8cc0(struct Container021e8cc0* obj);
extern "C" void func_ov023_021e8cdc(void* obj);

struct StructA0205d5d0;
int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);

// USA: func_ov023_021e81f4
ARM void ApplyElemFieldsTwice_021e81f4(void* obj) {
    memset(*(void**)((char*)obj + 0x5d8), 0, 0x960);
    CallAppendStringIfSet_021e8cc0((struct Container021e8cc0*)obj);
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x78), 0xc, *(int*)((char*)obj + 0x5d8), 0, 1);

    memset(*(void**)((char*)obj + 0x5d8), 0, 0x960);
    func_ov023_021e8cdc(obj);
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x78), 0xd, *(int*)((char*)obj + 0x5d8), 0, 1);
}
