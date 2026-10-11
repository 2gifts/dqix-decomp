#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
#define ScaleStatsIfType12_021f6f10 func_ov023_021f6f10
extern "C" int func_ov023_021f6f10(void* self);
#else
int ScaleStatsIfType12_021f6f10(void* self);
#endif
extern "C" void* func_ov004_021551a8(void*);
extern int TestBitInByteArray(int unused, unsigned char* arr, int index);
extern "C" void* func_0205ec34(void);
int TailCallOffset20_021fbdcc(void*, int, int, int);

// USA: func_ov004_021552b8
ARM int CheckType16ThenTestBit_021552b8(void* a) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), 0x2e);
    if (!node) return 0;
    if (ScaleStatsIfType12_021f6f10(node) != 0x10) return 0;

    void* r = func_ov004_021551a8(a);
    short val = -1;
    if (r) {
        int field = *(int*)((char*)r + 0xc);
        val = *(short*)((char*)r + 0x18);
        unsigned int t = ((unsigned int)field << 9) >> 0x15;
        unsigned short bits16 = (unsigned short)t;
        int bits = bits16;
        if (bits > 0) {
            unsigned char* base = (unsigned char*)func_0205ec34();
            if (!TestBitInByteArray((int)base, base + 0x8c, bits + 0x76 + 0xc00)) {
                val = -1;
            }
        }
    }

    typedef int (*TailFn2)(void*, int);
    ((TailFn2)&TailCallOffset20_021fbdcc)(node, val);
    return 0;
}
