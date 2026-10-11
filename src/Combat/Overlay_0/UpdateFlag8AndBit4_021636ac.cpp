#include <globaldefs.h>

void ProcessBattlerEffects02019568(void* a, int b);

#if defined(jpn)
enum { flagsOffset = 0x5b41, effectsOffset = 0xe44, parityOffset = 0x57c8 };
#else
enum { flagsOffset = 0x5951, effectsOffset = 0xec8, parityOffset = 0x55d8 };
#endif

struct Flags5951_021636ac {
    unsigned char lowBits : 3;
    unsigned char isActive : 1;
    unsigned char parityFlag : 1;
    unsigned char highBits : 3;
};

// USA: func_ov000_021636ac
// JPN: func_ov000_02164e10
ARM void UpdateFlag8AndBit4_021636ac(void* objRaw) {
    if (((struct Flags5951_021636ac*)((char*)objRaw + flagsOffset))->isActive) {
        return;
    }
    ProcessBattlerEffects02019568((char*)objRaw + effectsOffset, 1);
    ((struct Flags5951_021636ac*)((char*)objRaw + flagsOffset))->isActive = 1;
    int v = *(int*)((char*)objRaw + parityOffset);
    ((struct Flags5951_021636ac*)((char*)objRaw + flagsOffset))->parityFlag = (unsigned char)(v % 2);
}
