#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/VRAMStaging.h"
#include "Combat/MapDisplay.h"

extern char data_02107800;

extern "C" void* func_ov017_0218b5b0(void*);
void ResetList0204af64(struct List0204af64*);
extern "C" void func_0204b174(void* list, void* rec, void* alloc, int size);
extern "C" unsigned int GetMainBG1ScreenBase(void);
extern "C" void ColorEffect_ConfigureAlphaBlend(void* reg, int a, int b, int c, int d);

#if defined(jpn)
#define BG_UPLOAD_SOURCE_OFFSET 0x3c0
#define BG_UPLOAD_SIZE 0x280
#else
#define BG_UPLOAD_SOURCE_OFFSET 0x280
#define BG_UPLOAD_SIZE 0x900
#endif

// USA: func_02044d0c
extern "C" ARM void func_02044d0c(void) {
    volatile unsigned int* reg32 = (volatile unsigned int*)0x04000000;
    volatile unsigned short* reg16 = (volatile unsigned short*)0x04000000;

    reg32[0] = (reg32[0] & ~0x1f00u) | 0x1100u;
    reg32[6] = 0;
    reg32[7] = 0;
    reg16[5] = (reg16[5] & 0x43) | 0x1d00;
    reg16[6] = (reg16[6] & 0x43) | 0x1e00;
    reg16[7] = (reg16[7] & 0x43) | 0x308 | 0x1c00;

#if defined(jpn)
    char* base = *(char**)(&data_02107800 + 0x30);
#else
    char* base = *(char**)&data_02107800;
#endif
    char* rec = *(char**)((char*)func_ov017_0218b5b0(&data_02107800) + 0x2c);

    struct List0204af64 local;
    ResetList0204af64(&local);
    local.b1c_lo = 0;
    local.b1c_hi = 3;
    func_0204b174(&local, rec, 0, 0);

    if (base != 0) {
        unsigned char i;
        memset(base, 0, 0x1000);
        for (i = 0; i < 6; i++) {
            StageMemoryToVRAM(VRAMSubregion_MainBG3Character, base, i << 12, 0x1000, 1, 0);
        }
        char* p = *(char**)(&data_02107800 + 4);
        if (p + BG_UPLOAD_SOURCE_OFFSET != 0) {
            StageMemoryToVRAM(VRAMSubregion_MainBG2Character, p + BG_UPLOAD_SOURCE_OFFSET, 0x20, BG_UPLOAD_SIZE, 1, 0);
        }
    }

    if (base != 0) {
        unsigned short* w;
        unsigned short v;
        memset(base, 0, 0x1000);
        StageMemoryToVRAM(VRAMSubregion_MainBG2Screen, base, 0, 0x800, 1, 0);
        w = (unsigned short*)(base + 0x800);
        for (v = 0; v < 0x300; v++) {
            *w = v;
            w++;
        }
        StageMemoryToVRAM(VRAMSubregion_MainBG3Screen, base, 0, 0x800, 1, 0);
        unsigned int bg = GetMainBG1ScreenBase();
        if (bg != 0) {
            memset((void*)bg, 0, 0x800);
        }
    }

    ColorEffect_ConfigureAlphaBlend((void*)0x04000050, 4, 1, 0xa, 6);

    volatile unsigned short* bgcnt = (volatile unsigned short*)0x04000008;
    bgcnt[0] = (bgcnt[0] & ~3u) | 3u;
    bgcnt[1] = (bgcnt[1] & ~3u) | 2u;
    bgcnt[2] = (bgcnt[2] & ~3u) | 1u;
    bgcnt[3] = bgcnt[3] & ~3u;
}
