#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" unsigned int func_ov023_021f6f10(void* self);
#define NODE_KIND_CALL func_ov023_021f6f10
#else
int ScaleStatsIfType12_021f6f10(void* self);
#define NODE_KIND_CALL ScaleStatsIfType12_021f6f10
#endif
extern char* data_ov004_02171010;

// USA: func_ov004_021651c8
ARM int ToggleFlag8OnTwoObjs_021651c8(void* a1) {
#if defined(jpn)
 enum { countOffset = 0x9f4, flagOffset = 0x9fc };
#else
 enum { countOffset = 0x8f4, flagOffset = 0x8fc };
#endif
    if (*(unsigned char*)(data_ov004_02171010 + 0x1000 + countOffset) == 0) return 0;
    void* obj = func_ov023_021f6880(func_ov011_021849c8(a1), 0x1f5);
    if (obj == NULL) return 0;
    if (NODE_KIND_CALL(obj) != 1) return 0;

    unsigned char v = *(unsigned char*)(data_ov004_02171010 + 0x1000 + flagOffset);
    if (v == 0) {
        *((unsigned char*)obj + 0xc) |= 0x8;
    } else if (v == 1) {
        *((unsigned char*)obj + 0xc) &= ~0x8;
    }

    void* obj2 = func_ov023_021f6880(func_ov011_021849c8(a1), 0x1f6);
    if (obj2 == NULL) return 0;
    if (NODE_KIND_CALL(obj2) != 1) return 0;

    unsigned char v2 = *(unsigned char*)(data_ov004_02171010 + 0x1000 + flagOffset);
    if (v2 == 0) {
        *((unsigned char*)obj2 + 0xc) &= ~0x8;
    } else if (v2 == 1) {
        *((unsigned char*)obj2 + 0xc) |= 0x8;
    }
    return 0;
}
