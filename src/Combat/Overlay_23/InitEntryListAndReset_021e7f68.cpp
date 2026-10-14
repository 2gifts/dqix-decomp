#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry_0205d6a0;
void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);
extern "C" void func_ov023_021e7cec(void* obj, int a, int b, int c);
extern "C" void func_ov023_021e868c(void* obj);
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);

// USA: func_ov023_021e7f68
ARM void InitEntryListAndReset_021e7f68(void* obj) {
    ResetEntryList0205d6a0((struct Entry_0205d6a0*)((char*)obj + 0x78), 1);
    func_ov023_021e7cec(obj, 0xb, 3, 5);
    memset(*(void**)((char*)obj + 0x5d8), 0, 0x960);
    if (*(void**)((char*)obj + 0x5f4) != NULL) {
        func_ov023_021e868c(obj);
    }
    func_0205d304((char*)obj + 0x78, *(void**)((char*)obj + 0x5d8), 0, 0, 0, 1, 0, 0);
}
