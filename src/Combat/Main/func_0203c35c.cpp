#include <globaldefs.h>
#include "std_library_functions.h"
#include "System/Cache.h"
#include "System/LoadToVRAM.h"

struct PaletteState0203c35c {
    unsigned char padding[0x504];
    int engine;
    int field_508;
    unsigned int paletteOffset;
};
struct PaletteWork0203c35c {
    unsigned char padding[0x60];
    unsigned short* palette;
};
struct PaletteColor0203c35c {
    float red;
    float green;
    float blue;
};
int GetGlobalField0x1c020421a0();
extern PaletteColor0203c35c data_020e78c4[] __attribute__((aligned(4)));
extern float data_020e78b0[];
extern unsigned short data_020e78a0[];

// USA: func_0203c35c
extern "C" ARM void func_0203c35c(PaletteState0203c35c* state) {
    int green;
    int blue;
    int red;
    const float* weights;
    unsigned short* palette;
    unsigned int i;
    int shade;
    unsigned short colors[16] = {};
    palette = ((PaletteWork0203c35c*)GetGlobalField0x1c020421a0())->palette;
    unsigned short paletteBytes = 0xe0;
    memset(palette, 0, paletteBytes);
    for (i = 0; i < 7; i++) {
        colors[1] = 0x294a;
        if (i == 6) colors[1] = 0x18c6;
        const PaletteColor0203c35c* color = &data_020e78c4[i];
        const float& redScale = color->red;
        const float& greenScale = color->green;
        for (shade = 0, weights = data_020e78b0; shade < 5; shade++) {
            float factor = weights[shade];
            factor *= redScale;
            red = (int)factor;
            factor = weights[shade];
            factor *= greenScale;
            green = (int)factor;
            factor = weights[shade];
            factor *= color->blue;
            blue = (int)factor;
            int redBits = red >> 3;
            int greenBits = green >> 3;
            int blueBits = blue >> 3;
            int packed = greenBits << 5;
            packed |= redBits;
            packed |= blueBits << 10;
            colors[shade + 2] = packed;
        }
        colors[15] = data_020e78a0[i];
        memcpy(palette + i * 16, colors, 0x20);
    }
    CleanInvalidateCacheRange(palette, 0xe0);
    if (state->engine == 0) LoadToMainObjStandardPalette(palette, state->paletteOffset, 0xe0);
    else if (state->engine == 1) LoadToSubObjStandardPalette(palette, state->paletteOffset, 0xe0);
}
