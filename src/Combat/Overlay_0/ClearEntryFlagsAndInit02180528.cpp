#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x488
#define REGION_OFFSET_1 0x1f00
#define REGION_OFFSET_2 0x96
#else
#define REGION_OFFSET_0 0x448
#define REGION_OFFSET_1 0x1d00
#define REGION_OFFSET_2 0x5e
#endif


struct Entry02180528 {
    char pad0[0x24];
    unsigned char flags0x24;
    char pad1[REGION_OFFSET_0 - 0x25];
};

extern "C" int func_ov000_02174b14(void* obj);

// USA: func_ov000_02180528
ARM int ClearEntryFlagsAndInit02180528(char* obj) {
    int idx;
    for (idx = 0; idx < 4; idx++) {
        signed char e = *(signed char*)(obj + idx + 0x6c);
        struct Entry02180528* entry = (struct Entry02180528*)(obj + 0x958) + e;
        entry->flags0x24 &= ~0x4;
    }
    *(short*)(obj + REGION_OFFSET_1 + REGION_OFFSET_2) = 0x10;
    *(int*)(obj + 0x920) = 0x100;
    *(int*)(obj + 0x92c) = 8;
    *(int*)(obj + 0x924) = 0x100;
    *(int*)(obj + 0x928) = 0x100;
    return func_ov000_02174b14(obj);
}
