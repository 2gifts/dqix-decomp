#include <globaldefs.h>
#include "System/Memory.h"
#include "System/Cache.h"
#include "System/Graphics.h"
#include "System/LoadToVRAM.h"
struct Palette02229124 { unsigned char banks[16][0x20]; };
struct State02229124 { void* field0; Palette02229124* palette; int field8; };
typedef void (*VRAMLoader02229124)(const void*, unsigned int, unsigned int);
extern "C" void func_ov031_022234d8(const char*, VRAMLoader02229124);
extern "C" int func_ov031_02223478(const char*);
extern "C" Palette02229124* func_ov031_0223b61c(int, int, int);
extern "C" void func_ov031_0221ae00(unsigned int*);
extern "C" void func_ov031_0223b710(void*);
extern unsigned char data_ov031_02248dcc[22];
extern unsigned char data_ov031_02248de2[23];
extern char data_ov031_0224b8f4[];
extern char data_ov031_0224b90c[];
extern State02229124 data_ov031_02290c5c;
// USA: func_ov031_02229124
extern "C" ARM void func_ov031_02229124() {
    unsigned char* paletteSource;
    unsigned char* paletteDestination;
    int index;
    Palette02229124* palette;
    char mainPath[22];
    char secondaryPath[23];
    unsigned int settings[5];
    {
        int pairs = 11;
        char* destination = mainPath;
        const unsigned char* source = data_ov031_02248dcc;
        do {
            unsigned char first = source[0];
            unsigned char second = source[1];
            source += 2;
            destination[0] = first;
            destination[1] = second;
            destination += 2;
        } while (--pairs);
    }
    {
        char* destination = secondaryPath;
        int pairs = 11;
        const unsigned char* source = data_ov031_02248de2;
        do {
            unsigned char first = source[0];
            unsigned char second = source[1];
            source += 2;
            destination[0] = first;
            destination[1] = second;
            destination += 2;
        } while (--pairs);
        destination[0] = source[0];
    }
    func_ov031_022234d8(data_ov031_0224b8f4, LoadToMainBG2CharacterData);
    func_ov031_022234d8(data_ov031_0224b90c, LoadToMainBG2ScreenData);
    data_ov031_02290c5c.palette = func_ov031_0223b61c(func_ov031_02223478(secondaryPath), 0, 4);
    palette = func_ov031_0223b61c(func_ov031_02223478(mainPath), 0, 4);
    func_ov031_0221ae00(settings);
    unsigned int high = settings[1];
    unsigned int low = settings[0];
    index = 0;
    if (high == 0 && low == 0) {
        paletteSource = palette->banks[6];
        paletteDestination = palette->banks[2];
        do {
            VectorizedInvertedMemcpy(paletteSource, paletteDestination, 0x20);
            ++index;
            paletteSource += 0x20;
            paletteDestination += 0x20;
        } while (index < 2);
    }
    CleanInvalidateCacheRange(palette, 0x200);
    LoadToMainBGStandardPalette(palette, 0, 0x200);
    func_ov031_0223b710(palette);
    BG0CNTSUB = (BG0CNTSUB & ~3) | 3;
    BG1CNTSUB = (BG1CNTSUB & ~3) | 3;
    BG1CNT = (BG1CNT & ~3) | 3;
    BG2CNT = (BG2CNT & ~3) | 3;
}
