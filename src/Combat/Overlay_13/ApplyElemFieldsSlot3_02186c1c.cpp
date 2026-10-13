#include <globaldefs.h>
#include "std_library_functions.h"

struct StructA0205d5d0;
#if defined(jpn)
#define func_ov013_02185be0 func_ov013_02186db0
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(StructA0205d5d0*, int, int, int);
#else
int TryApplyElemFields0205d5d0(StructA0205d5d0*, int, int, int, unsigned char);
#endif
extern "C" void func_ov013_02185be0(void*, void*);

// USA: func_ov013_02186c1c
extern "C" ARM void func_ov013_02186c1c(void* obj) {
#if defined(jpn)
    memset(*(void**)((char*)obj + 0x5e0), 0, 0x800);
    func_ov013_02185be0(obj, *(void**)((char*)obj + 0x5e0));
    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((StructA0205d5d0*)((char*)obj + 0x34), 3, *(int*)((char*)obj + 0x5e0), 1);
#else
    memset(*(void**)((char*)obj + 0x658), 0, 0x960);
    func_ov013_02185be0(obj, *(void**)((char*)obj + 0x658));
    TryApplyElemFields0205d5d0((StructA0205d5d0*)((char*)obj + 0x38), 3, *(int*)((char*)obj + 0x658), 1, 1);
#endif
}
