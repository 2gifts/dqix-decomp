#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x7e4
#define REGION_OFFSET_1 0x218
#define REGION_OFFSET_2 0x31c
#define REGION_OFFSET_3 0x3400
#else
#define REGION_OFFSET_0 0x5f4
#define REGION_OFFSET_1 0x29c
#define REGION_OFFSET_2 0x760
#define REGION_OFFSET_3 0x3000
#endif


struct StructAt3c_02162aac {
    signed char f0;
    signed char f1;
    char pad2;
    unsigned char f3;
    signed char f4;
    char pad5;
    short f6;
    unsigned short f8;
};

int GetClampedArrayField0xd3c(char* base, int index);
extern "C" void func_ov000_02174428(void* obj, int a, int f0, int f1, int bestIdxByte, int f6, int f4, int f8);

// USA: func_ov000_02162aac
ARM void ProcessCombatantSlot_02162aac(void* self, int a, struct StructAt3c_02162aac* s) {
    int flags = *(int*)((char*)self + 0x5000 + REGION_OFFSET_0);
    if (!(flags & 0x10000)) {
        return;
    }
    if (flags & 0x800000) {
        return;
    }
    void* mirrorPtr = *(void**)((char*)self + REGION_OFFSET_1);
    int val1 = *(int*)((char*)mirrorPtr + 0x8000 + 0xe20);
    if (val1 == 0) {
        if (*(unsigned char*)((char*)mirrorPtr + 0x8000 + 0xe49) == 2) {
            return;
        }
    }
    int bestIdx = -1;
    int i = 0;
    while (i < 12) {
        int val = GetClampedArrayField0xd3c((char*)self + REGION_OFFSET_2 + REGION_OFFSET_3, i);
        if (s->f3 == val) {
            bestIdx = i;
            break;
        }
        i++;
    }
    func_ov000_02174428((char*)self + REGION_OFFSET_2 + REGION_OFFSET_3, a, s->f0, s->f1, (signed char)bestIdx, s->f6, s->f4, s->f8);
}
