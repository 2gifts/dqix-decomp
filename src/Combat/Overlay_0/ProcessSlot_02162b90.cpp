#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x7e4
#define REGION_OFFSET_1 0x31c
#define REGION_OFFSET_2 0x3400
#else
#define REGION_OFFSET_0 0x5f4
#define REGION_OFFSET_1 0x760
#define REGION_OFFSET_2 0x3000
#endif


extern "C" void* func_ov000_02161318(void* obj, int id);
int GetClampedArrayField0xd3c(char* base, int index);

// USA: func_ov000_02162b90
ARM void ProcessSlot_02162b90(void* self, int unused1, int c, int unused3, int compareVal, signed char idx6, signed char p2) {
    int flags = *(int*)((char*)self + 0x5000 + REGION_OFFSET_0);
    if (!(flags & 0x10000)) {
        return;
    }
    if (flags & 0x800000) {
        return;
    }
    int bestIdx = -1;
    int i = 0;
    while (i < 12) {
        int val = GetClampedArrayField0xd3c((char*)self + REGION_OFFSET_1 + REGION_OFFSET_2, i);
        if (compareVal == val) {
            bestIdx = i;
            break;
        }
        i++;
    }
    void* entry = func_ov000_02161318((char*)self + REGION_OFFSET_1 + REGION_OFFSET_2, idx6);
    if (entry != NULL) {
        *(short*)((char*)entry + 0x26) = (short)c;
        *(unsigned char*)((char*)entry + 0x1d) = (unsigned char)bestIdx;
        *(unsigned char*)((char*)entry + 0x2e) = (unsigned char)p2;
    }
}
