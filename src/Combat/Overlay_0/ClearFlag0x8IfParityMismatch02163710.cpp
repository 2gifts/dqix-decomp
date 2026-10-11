#include <globaldefs.h>

extern "C" void func_02019678(void* ptr, int flag);

#if defined(jpn)
enum { flagsOffset = 0x5b41, effectsOffset = 0xe44, parityOffset = 0x57c8 };
#else
enum { flagsOffset = 0x5951, effectsOffset = 0xec8, parityOffset = 0x55d8 };
#endif

struct Flags0951_02163710 {
    unsigned char pad0 : 3;
    unsigned char bit3 : 1;
    unsigned char bit4 : 1;
    unsigned char pad1 : 3;
};

// USA: func_ov000_02163710
ARM void ClearFlagIfParityMismatch02163710_02163710(void* obj, int flag) {
    struct Flags0951_02163710* f = (struct Flags0951_02163710*)((char*)obj + flagsOffset);
    if (!f->bit3) {
        return;
    }
    if (flag == 0) {
        int val = *(int*)((char*)obj + parityOffset);
        if ((int)f->bit4 == val % 2) {
            return;
        }
    }
    func_02019678((char*)obj + effectsOffset, 1);
    volatile unsigned char* p = (unsigned char*)obj + flagsOffset;
    *p = *p & ~8;
}
