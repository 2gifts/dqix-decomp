#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021dcedc func_ov023_021dd7e0
#endif
#include "System/Cache.h"
#include "System/LoadToVRAM.h"

struct StatusTextState {
#if defined(jpn)
    unsigned char padding0[0x6f8];
#else
    unsigned char padding0[0x77c];
#endif
    signed char paletteReady;
    signed char expanded;
    unsigned char padding77e[6];
    const char* names[3];
    unsigned char quantities[3];
    unsigned char limits[3];
    unsigned char costs[3];
    unsigned char multiplier;
};
#if defined(jpn)
struct StatusTextGlobals { int field0; int field4; int field8; int palette; int field10; int enabled; };
#define data_ov023_021fdb2d data_ov023_021fce07
#define data_ov023_021fdb31 data_ov023_021fce0a
#define data_ov023_021fdb35 data_ov023_021fce0e
#define data_ov023_021fdb39 data_ov023_021fce12
#define data_ov023_021fdb3b data_ov023_021fcdec
#define data_ov023_021fdb3e data_ov023_021fce15
enum { ExpandedNameX = 5, ExpandedOpenX = 0xb9, ExpandedCloseX = 0xcb,
       CollapsedNameX = 0x46, CollapsedTimesX = 0xaa, CollapsedQuantityX = 0xb9,
       NumberYOffset = 1 };
#else
struct StatusTextGlobals { int field0; int enabled; int field8; int palette; };
enum { ExpandedNameX = 0, ExpandedOpenX = 0xc0, ExpandedCloseX = 0xc8,
       CollapsedNameX = 0x40, CollapsedTimesX = 0xc0, CollapsedQuantityX = 0xc8,
       NumberYOffset = 0 };
#endif
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
#if defined(jpn)
extern "C" void func_02050678(void*, short, short, const char*, int, int, short*, short*);
#else
extern "C" void func_0204f41c(void*, short, short, const char*, int, int, short*, short*, int);
#endif
static inline void DrawStatusText(void* canvas, short x, short y, const char* text, int font, int color) {
    short height;
    short width;
#if defined(jpn)
    func_02050678(canvas, x, y, text, font, color, &width, &height);
#else
    func_0204f41c(canvas, x, y, text, font, color, &width, &height, 0);
#endif
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
#if !defined(jpn)
    void* formatter = _Z26GetGlobalField0x1c020421a0v();
#endif
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
#if defined(jpn)
            short numberY = y + NumberYOffset;
            DrawStatusText(canvas, ExpandedNameX, y, name, 10, color);
#else
            char source[256] = {};
            char converted[256] = {};
            _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(name, source, 0);
            func_02046608(formatter, 10, source, converted, 0x400, 0, 0);
            DrawStatusText(canvas, ExpandedNameX, y, converted, 10, color);
#endif
            sprintf(text, data_ov023_021fdb2d);
#if defined(jpn)
            DrawStatusText(canvas, 0x72, numberY, text, 8, color);
#else
            DrawStatusText(canvas, 0x72, y, text, 8, color);
#endif
            sprintf(text, data_ov023_021fdb31, quantity);
#if defined(jpn)
            DrawStatusText(canvas, 0x7d, numberY, text, 8, color);
#else
            DrawStatusText(canvas, 0x7d, y, text, 8, color);
#endif
            sprintf(text, data_ov023_021fdb35, limit);
#if defined(jpn)
            DrawStatusText(canvas, 0xa1, numberY, text, 8, color);
#else
            DrawStatusText(canvas, 0xa1, y, text, 8, color);
#endif
            sprintf(text, data_ov023_021fdb39);
            DrawStatusText(canvas, ExpandedOpenX, y, text, 10, color);
            sprintf(text, data_ov023_021fdb3b, cost);
#if defined(jpn)
            DrawStatusText(canvas, 0xc3, numberY, text, 8, color);
#else
            DrawStatusText(canvas, 0xc3, y, text, 8, color);
#endif
            sprintf(text, data_ov023_021fdb3e);
            DrawStatusText(canvas, ExpandedCloseX, y, text, 10, color);
        } else {
            short y = i * 14;
#if defined(jpn)
            short numberY = y + NumberYOffset;
            DrawStatusText(canvas, CollapsedNameX, y, name, 10, color);
#else
            char source[256] = {};
            char converted[256] = {};
            _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(name, source, 0);
            func_02046608(formatter, 10, source, converted, 0x400, 0, 0);
            DrawStatusText(canvas, CollapsedNameX, y, converted, 10, color);
#endif
            sprintf(text, data_ov023_021fdb2d);
#if defined(jpn)
            DrawStatusText(canvas, CollapsedTimesX, numberY, text, 8, color);
#else
            DrawStatusText(canvas, CollapsedTimesX, y, text, 8, color);
#endif
            sprintf(text, data_ov023_021fdb31, quantity);
#if defined(jpn)
            DrawStatusText(canvas, CollapsedQuantityX, numberY, text, 8, color);
#else
            DrawStatusText(canvas, CollapsedQuantityX, y, text, 8, color);
#endif
        }
    }
}
