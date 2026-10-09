#include <globaldefs.h>

struct PaletteAnimation {
    unsigned char pad_00[0x4c];
    int palette;
    unsigned char pad_50[0x3e8];
    float phase;
    unsigned char flags;
};
extern unsigned short data_ov000_02184288;
extern unsigned short data_ov000_02184288_arg;
extern "C" double func_0200c578(float);
extern "C" double func_02009424(double);
void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" void LoadToSubBGStandardPalette(const void*, unsigned int, unsigned int);

// USA: func_ov000_02170b0c
extern "C" ARM void func_ov000_02170b0c(PaletteAnimation* animation, unsigned int elapsed) {
    if (!(animation->flags & 1)) return;
    if (animation->flags & 2) {
        animation->flags &= ~1;
        animation->flags &= ~2;
        animation->phase = 0;
        data_ov000_02184288 = 0x7fff;
    } else {
        animation->phase += 0.2f * (float)elapsed;
        while (3.1415925f <= animation->phase) animation->phase -= 3.1415925f;
        float amount = 1.0f - (float)func_02009424(func_0200c578(animation->phase));
        short red = (short)(int)(21.0f * amount);
        short green = (short)(int)(21.0f * amount);
        short blue = (short)(int)(-10.0f * amount);
        data_ov000_02184288 = (short)(red + 10) | ((short)(green + 10) << 5) | ((short)(blue + 10) << 10);
    }
    int offset = (animation->palette + 2) << 5;
    CleanInvalidateCacheRange(&data_ov000_02184288_arg, 2);
    LoadToSubBGStandardPalette(&data_ov000_02184288_arg, offset + 0x1e, 2);
}
