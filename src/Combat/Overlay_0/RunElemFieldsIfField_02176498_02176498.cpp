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
extern "C" void func_ov000_02176500(void* obj, void* buf, int flag);

struct StructA0205d5d0;
#if defined(jpn)
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0*, int, int, int);
#else
int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);
#endif

// USA: func_ov000_02176498
ARM void RunElemFieldsIfField_02176498_02176498(void* obj, int flag) {
    if (*(void**)((char*)obj + 0x38) != 0) {
        void* buf = *(void**)(GetGlobalField0x1c020421a0() + REGION_OFFSET_0);
        memset(buf, 0, REGION_OFFSET_1);
        func_ov000_02176500(obj, buf, flag);
#if defined(jpn)
        _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)*(void**)((char*)obj + 0x38), 0xd, (int)buf, 1);
#else
        TryApplyElemFields0205d5d0((struct StructA0205d5d0*)*(void**)((char*)obj + 0x38), 0xd, (int)buf, 1, 0);
#endif
    }
}
