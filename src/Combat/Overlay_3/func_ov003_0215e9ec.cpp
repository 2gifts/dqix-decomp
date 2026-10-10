#include <globaldefs.h>

struct Table0215e9a4 {
    char pad0;
    signed char width;
    signed char height;
    char pad3;
    short* data;
};

struct LookupTable0215e930 {
    char pad0;
    signed char divisor;
    char pad2;
    signed char count;
    short* entries;
};

struct List0215e824;

struct Cell0215e8f4 {
    char pad0[0x10];
    short id;
};

struct Self0215e8f4 {
    struct Cell0215e8f4* cell;
    struct List0215e824* list;
    char pad8[0x19];
    unsigned char wrap;
};

extern "C" struct Table0215e9a4* _Z24FindEntryByMask_0215e8f4P12Self0215e8f4(struct Self0215e8f4*);
extern "C" ARM int func_ov003_0215e930(struct LookupTable0215e930* obj, short target, unsigned char* outMod, unsigned char* outDiv);
extern "C" int _Z21GetTableEntry0215e9a4P13Table0215e9a4ii(struct Table0215e9a4*, int, int);
extern "C" struct Cell0215e8f4* _Z22FindElemByKey_0215e824P12List0215e824i(struct List0215e824*, int);

// USA: func_ov003_0215e9ec
extern "C" ARM void func_ov003_0215e9ec(struct Self0215e8f4* self, int dx, int dy) {
    struct Table0215e9a4* table = _Z24FindEntryByMask_0215e8f4P12Self0215e8f4(self);
    short target;
    signed char x;
    signed char y;
    unsigned char wrap;
    int v;

    if (table == 0 || self->cell == 0) return;
    target = self->cell->id;
    if (func_ov003_0215e930((struct LookupTable0215e930*)table, target, (unsigned char*)&x, (unsigned char*)&y) != 0) return;

    wrap = self->wrap;
    x += dx;
    y += dy;
    v = _Z21GetTableEntry0215e9a4P13Table0215e9a4ii(table, x, y);
    if (y < 0) {
        y = 0;
        if (wrap) y = table->height - 1;
        dx = -1;
        dy = 0;
        if (v == -2) dx = 1;
    } else if (table->height <= y) {
        y = table->height - 1;
        if (wrap) y = 0;
        dx = -1;
        dy = 0;
        if (v == -2) dx = 1;
    }

    v = _Z21GetTableEntry0215e9a4P13Table0215e9a4ii(table, x, y);
    if (dy != 0) {
        if (v == -2) {
            while (v < 0) {
                x++;
                if (table->width <= x) break;
                v = _Z21GetTableEntry0215e9a4P13Table0215e9a4ii(table, x, y);
            }
            while (v < 0) {
                x--;
                if (x < 0) break;
                v = _Z21GetTableEntry0215e9a4P13Table0215e9a4ii(table, x, y);
            }
        } else {
            while (v < 0) {
                x--;
                if (x < 0) break;
                v = _Z21GetTableEntry0215e9a4P13Table0215e9a4ii(table, x, y);
            }
            while (v < 0) {
                x++;
                if (table->width <= x) break;
                v = _Z21GetTableEntry0215e9a4P13Table0215e9a4ii(table, x, y);
            }
        }
    }

    wrap = 0;
    while (v < 0) {
        if (dx < 0) {
            x--;
            if (x < 0) x = table->width - 1;
            v = _Z21GetTableEntry0215e9a4P13Table0215e9a4ii(table, x, y);
        } else if (dx > 0) {
            x++;
            if (table->width <= x) x = wrap;
            v = _Z21GetTableEntry0215e9a4P13Table0215e9a4ii(table, x, y);
        }
    }

    self->cell = _Z22FindElemByKey_0215e824P12List0215e824i(self->list, v);
}
