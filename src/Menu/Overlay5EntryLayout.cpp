#if defined(jpn)
#define R(j,u) (j)
#define func_ov005_02158560 func_ov005_02159b58
#define func_ov005_021585fc func_ov005_02159bf4
#else
#define R(j,u) (u)
#endif
#include "globaldefs.h"

struct Overlay5BackingEntry { unsigned char unknown[0x70]; };
struct Overlay5VisualEntry {
    unsigned char unknown00[0x1c];
    int x, y, z;
    unsigned char unknown28[0x88 - 0x28];
};
struct Overlay5LayoutEntry {
    int unknown00;
    Overlay5BackingEntry* backing;
    Overlay5VisualEntry* visual;
    int x, y;
    unsigned char unknown14[8];
};
struct Overlay5Layout {
    unsigned char unknown00[0x304];
    Overlay5BackingEntry backingEntries[24];
    unsigned char unknownD84[R(0x2d08, 0x2d90) - 0x304 - 24 * 0x70];
    Overlay5LayoutEntry entries[24];
    Overlay5VisualEntry visuals[24];
};

extern "C" ARM void func_ov005_02155424(Overlay5Layout* layout) {
    for (int i = 0; i < 8; ++i) {
        Overlay5LayoutEntry* entry = &layout->entries[i];
        entry->backing = &layout->backingEntries[i];
        entry->visual = &layout->visuals[i];
        entry->x = 133 << 12;
        entry->y = 22 << 12;
        Overlay5VisualEntry* visual = entry->visual;
        visual->x = 133 << 12;
        visual->y = 22 << 12;
        visual->z = 0;
    }
    for (int i = 0; i < 16; ++i) {
        Overlay5LayoutEntry* entry = &layout->entries[i + 8];
        entry->backing = &layout->backingEntries[i + 8];
        entry->visual = &layout->visuals[i + 8];
        int column = (i % 16) % 4;
        int row = (i % 16) / 4;
        int x = (column * 26 + 141) << 12;
        int y = (row * 26 + 52) << 12;
        entry->x = x;
        entry->y = y;
        Overlay5VisualEntry* visual = entry->visual;
        visual->x = x;
        visual->y = y;
        visual->z = 0;
    }
}
