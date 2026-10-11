#include <globaldefs.h>
#if defined(jpn)
enum { kRegion960 = 0x800 };
#else
enum { kRegion960 = 0x960 };
#endif

#include "std_library_functions.h"

struct Struct_0205d81c;
struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);

struct StructA0205d5d0;
#if defined(jpn)
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(StructA0205d5d0*, int, int, int);
#endif
int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);

extern "C" void func_ov003_0215b6f0(char* base, char* dst, int flag);
extern "C" void func_ov003_0215b964(void* self, void* p, int flag);
extern "C" void func_ov003_0215be70(char* base, char* dst, int flag);

// JPN: func_ov003_0215d334
// USA: func_ov003_0215c01c
extern "C" ARM void func_ov003_0215c01c(unsigned char* obj, int mode, int flag) {
    unsigned char* elem = (unsigned char*)FindElementByC40205d81c((struct Struct_0205d81c*)(obj + 0xf4), mode);
    if (elem == 0) return;

    if (flag) elem[0xc5] |= 0x40;
    else elem[0xc5] &= ~0x40;
    flag = 0;

    if (*(volatile unsigned char*)(elem + 0xc5) & 2) flag = 1;
    memset(*(void**)(obj + 0x7c), 0, kRegion960);

    switch (mode) {
    case 1: func_ov003_0215b6f0((char*)obj, *(char**)(obj + 0x7c), flag); break;
    case 2: func_ov003_0215b964(obj, *(void**)(obj + 0x7c), flag); break;
    case 3: func_ov003_0215be70((char*)obj, *(char**)(obj + 0x7c), flag); break;
    }
#if defined(jpn)
    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)(obj + 0xf4), mode, *(int*)(obj + 0x7c), 1);
#else
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)(obj + 0xf4), mode, *(int*)(obj + 0x7c), 1, 0);
#endif
}
