#include <globaldefs.h>
#if defined(jpn)
#define REGION_FIELD_0 0x6f8
#define REGION_FIELD_1 0x114
#define REGION_FIELD_2 0x6ac
#else
#define REGION_FIELD_0 0x77c
#define REGION_FIELD_1 0x118
#define REGION_FIELD_2 0x730
#endif


struct Struct02074bd0;
struct Struct02074bf4;
void ClearFlag0x10IfSet(struct Struct02074bd0* obj);
void ClearFlag0x11IfSet(struct Struct02074bf4* obj);

// USA: func_ov023_021dcd18  (semantic: SetCaptureRegField730_021dcd18)
#pragma optimize_for_size off
extern "C" ARM void func_ov023_021dcd18(void* obj) {
    signed char mode = *(signed char*)((char*)obj + REGION_FIELD_0);
    if (mode == 1) {
        ClearFlag0x11IfSet((struct Struct02074bf4*)((char*)obj + REGION_FIELD_1));
        unsigned int* reg = (unsigned int*)0x4001000;
        *reg = (*reg & ~0x1f00) | (*(unsigned int*)((char*)obj + REGION_FIELD_2) << 8);
    } else {
        ClearFlag0x10IfSet((struct Struct02074bd0*)((char*)obj + REGION_FIELD_1));
        unsigned int* reg = (unsigned int*)0x4000000;
        *reg = (*reg & ~0x1f00) | (*(unsigned int*)((char*)obj + REGION_FIELD_2) << 8);
    }
}
