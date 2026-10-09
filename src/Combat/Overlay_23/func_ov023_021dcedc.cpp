#include <globaldefs.h>
#include "System/Cache.h"
#include "System/LoadToVRAM.h"

struct StatusTextState {
    unsigned char padding0[0x77c];
    signed char paletteReady;
    signed char expanded;
    unsigned char padding77e[6];
    const char* names[3];
    unsigned char quantities[3];
    unsigned char limits[3];
    unsigned char costs[3];
    unsigned char multiplier;
};
struct StatusTextGlobals { int field0; int enabled; int field8; int palette; };
extern StatusTextGlobals data_ov023_021ff9e0;
extern char data_ov023_021fdb2d[];
extern char data_ov023_021fdb31[];
extern char data_ov023_021fdb35[];
extern char data_ov023_021fdb39[];
extern char data_ov023_021fdb3b[];
extern char data_ov023_021fdb3e[];
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" int sprintf(char*, const char*, ...);
extern "C" void _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(const char*, char*, int);
extern "C" void func_02046608(void*, int, const char*, char*, int, int, int);
extern "C" void func_0204f41c(void*, short, short, const char*, int, int, short*, short*, int);
static inline void DrawStatusText(void* canvas, short x, short y, const char* text, int font, int color) {
    short height;
    short width;
    func_0204f41c(canvas, x, y, text, font, color, &width, &height, 0);
}

// USA: func_ov023_021dcedc
extern "C" ARM void func_ov023_021dcedc(StatusTextState* state, void* canvas) {
    if (!data_ov023_021ff9e0.enabled) return;
    if (state->paletteReady == 0) {
        unsigned short color = 0x110f;
        unsigned int offset = data_ov023_021ff9e0.palette * 32;
        CleanInvalidateCacheRange(&color, 2);
        LoadToMainBGStandardPalette(&color, offset + 0x12, 2);
    }
    char text[64] = {};
    void* formatter = _Z26GetGlobalField0x1c020421a0v();
    for (int i = 0; i < 3; i++) {
        const char* name = state->names[i];
        if (!name) continue;
        unsigned char quantity = state->multiplier * state->quantities[i];
        unsigned char limit = state->limits[i];
        unsigned char cost = state->costs[i];
        int color = 15;
        if (quantity > limit) color = 9;
        if (!quantity) continue;
        if (state->expanded == 1) {
            short y = i * 14 + 7;
            char source[256] = {};
            char converted[256] = {};
            _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(name, source, 0);
            func_02046608(formatter, 10, source, converted, 0x400, 0, 0);
            DrawStatusText(canvas, 0, y, converted, 10, color);
            sprintf(text, data_ov023_021fdb2d);
            DrawStatusText(canvas, 0x72, y, text, 8, color);
            sprintf(text, data_ov023_021fdb31, quantity);
            DrawStatusText(canvas, 0x7d, y, text, 8, color);
            sprintf(text, data_ov023_021fdb35, limit);
            DrawStatusText(canvas, 0xa1, y, text, 8, color);
            sprintf(text, data_ov023_021fdb39);
            DrawStatusText(canvas, 0xc0, y, text, 10, color);
            sprintf(text, data_ov023_021fdb3b, cost);
            DrawStatusText(canvas, 0xc3, y, text, 8, color);
            sprintf(text, data_ov023_021fdb3e);
            DrawStatusText(canvas, 0xc8, y, text, 10, color);
        } else {
            short y = i * 14;
            char source[256] = {};
            char converted[256] = {};
            _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(name, source, 0);
            func_02046608(formatter, 10, source, converted, 0x400, 0, 0);
            DrawStatusText(canvas, 0x40, y, converted, 10, color);
            sprintf(text, data_ov023_021fdb2d);
            DrawStatusText(canvas, 0xc0, y, text, 8, color);
            sprintf(text, data_ov023_021fdb31, quantity);
            DrawStatusText(canvas, 0xc8, y, text, 8, color);
        }
    }
}
