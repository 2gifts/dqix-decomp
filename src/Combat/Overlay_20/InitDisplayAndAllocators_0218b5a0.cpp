#if defined(jpn)
#define func_0200f3a4 func_0200f268
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

extern "C" void* func_0202ae18(void);
extern "C" void func_0200f3a4(void*);
extern "C" void MapVRAMBanksToMainBG(int v);
void SetDispcntModeAndFlags020c391c(int mode, int flagsA, int valB);
void SetSubBgMode(unsigned int mode);
void Set3DClearColor(int color, int alpha, int depth, int polygonId, int fogEnable);
unsigned char GetByte0x4(char* obj);
void ComputeAndLoadMatrix020c5770(int a0, int a1, int a2, int a3, int b0, int b1, int b2, int gate, void* outBuf);

struct Ov020DisplayState_0218b5a0 {
    char pad0[0x8];
    int f8;
    #if defined(jpn)
    char pad1[0x400 - 0xc];
#else
    char pad1[0x470 - 0xc];
#endif
    SafeAllocator allocator1;
    SafeAllocator allocator2;
    char pad2[0x4ec - 0x498];
    int f4ec;
    int f4f0;
    int f4f4;
    char pad3[0x4fc - 0x4f8];
    int f4fc;
    int f500;
};

// USA: func_ov020_0218b5a0  (semantic: InitDisplayAndAllocators_0218b5a0)
extern "C" ARM void func_ov020_0218b5a0(struct Ov020DisplayState_0218b5a0* obj) {
    char* battleStruct = (char*)GameState::GetInstance();
    func_0202ae18();
    func_0200f3a4(battleStruct);
    MapVRAMBanksToMainBG(4);

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    *dispcnt = *dispcnt & ~0x7000000;
    *dispcnt = *dispcnt & ~0x38000000;
    SetDispcntModeAndFlags020c391c(1, 0, 1);
    SetSubBgMode(0);

    volatile unsigned short* bgcnt = (volatile unsigned short*)0x4000008;
    bgcnt[0] = bgcnt[0] & ~0x3;
    bgcnt[1] = (bgcnt[1] & ~0x3) | 0x1;
    Set3DClearColor(0, 0, 0x7fff, 0x3f, 0);

    if (GetByte0x4(battleStruct) == 6) {
        Set3DClearColor(0, 0x1f, 0x7fff, 0, 0);
    }

    ComputeAndLoadMatrix020c5770(0, 0xc0000, 0, 0x100000, -0x400000, 0x400000, 0x400000, 1, 0);

    *(volatile unsigned int*)0x400044c = 0;
    *(volatile unsigned short*)0x4000304 = *(volatile unsigned short*)0x4000304 & ~0x8000;
    *(volatile unsigned int*)0x4000580 = 0xbfff0000;

    obj->allocator1.ResetAllocatorPointer();
    obj->allocator2.ResetAllocatorPointer();

    obj->f8 = 0;
    obj->f500 = 0;
#if !defined(jpn)
    obj->f4f0 = 0;
    obj->f4ec = 0;
    obj->f4fc = 0;
    obj->f4f4 = 0;
#endif
}
