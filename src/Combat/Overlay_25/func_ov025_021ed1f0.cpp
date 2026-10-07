#include <globaldefs.h>

// Local width/offset view only; member labels identify observed offsets.
struct View021ed1f0 {
    unsigned short u16_00[16];
    short s16_20[16];
    short s16_40[16];
    short s16_60[16];
    unsigned short u16_80[16];
    unsigned char u8_a0[16];
    unsigned int u32_b0[16];
    unsigned int u32_f0[16];
    unsigned char pad130[0x20];
    unsigned char count150;
    unsigned char pad151[0xb];
    short s16_15c;
};

// USA: func_ov025_021ed1f0
extern "C" ARM void func_ov025_021ed1f0(void* self) {
    struct View021ed1f0* view = (struct View021ed1f0*)self;
    unsigned char count = view->count150;
    if (count == 0) return;
    view->count150 = count - 1;

    // Move the remaining entries from index i+1 to i; the ROM rereads the count at each test.
    for (int i = 0; i < view->count150; i++) {
        view->u16_00[i] = view->u16_00[i + 1];
        view->s16_20[i] = view->s16_20[i + 1];
        view->u8_a0[i] = view->u8_a0[i + 1];
        view->u32_b0[i] = view->u32_b0[i + 1];
        view->s16_60[i] = view->s16_60[i + 1];
        view->s16_40[i] = view->s16_40[i + 1];
        view->u16_80[i] = view->u16_80[i + 1];
    }

    // Reload after the narrow store so the clamp tests the signed 16-bit result.
    view->s16_15c--;
    if (view->s16_15c < 0) view->s16_15c = 0;
}
