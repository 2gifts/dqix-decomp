#include <globaldefs.h>

struct SpriteRect_020e1b2c {
    unsigned int attr;
    unsigned int offset;
    unsigned char x;
    unsigned char y;
    unsigned char width;
    unsigned char height;
};

struct Struct020e1384 {
    int field0;
    int field4;
    char pad8[4];
    int field0xc;
    char pad10[4];
    unsigned char field0x14;
};

struct Panel020e1b2c {
    char pad0[8];
    struct SpriteRect_020e1b2c* rects;
    char pad_c[0x30 - 0xc];
    int field30;
    int field34;
    unsigned char x;
    unsigned char y;
    unsigned char width;
    unsigned char height;
    unsigned char count;
    unsigned char pad3d;
    unsigned char display;
};

struct Obj020e1b2c {
    char pad0[4];
    struct Panel020e1b2c* panel;
};

struct Obj020e1674;
struct HasDims020e1288;

extern "C" unsigned int func_020e1438(struct SpriteRect_020e1b2c* out, unsigned int maxCount,
                                      unsigned int x, unsigned int yBase,
                                      unsigned int width, unsigned int height);
extern "C" unsigned int _Z26GetDisplayModeCode0209378ci(int engine);
extern "C" int func_020937f0(int engine);
int GetHalfProductField8(struct HasDims020e1288* obj);
void RunCacheHookForField0x14(struct Struct020e1384* obj);
extern "C" void _Z39TransferBattleObjPaletteEntries020e16f4P11Obj020e1674(struct Obj020e1674* self);

// USA: func_020e1b2c
extern "C" ARM int func_020e1b2c(struct Obj020e1b2c* obj, int arg) {
    if (obj->panel == 0) return 0;

    _Z39TransferBattleObjPaletteEntries020e16f4P11Obj020e1674((struct Obj020e1674*)obj);

    struct SpriteRect_020e1b2c* rects = obj->panel->rects;
    unsigned int h = obj->panel->height;
    unsigned int cap = obj->panel->count;
    unsigned int w = obj->panel->width;
    unsigned int chunk;
    int count;
    unsigned int y;
    unsigned int total;
    unsigned int height;

    if (rects == 0 || cap == 0 || w == 0 || h == 0) {
        count = 0;
    } else {
        count = 0;
        total = (w + 7) & ~7u;
        y = 0;
        height = (h + 7) & ~7u;
        while (y < total) {
            if (count >= cap) break;
            chunk = 0x40;
            unsigned int rem = total - y;
            while (chunk > 8 && chunk > rem) chunk >>= 1;
            count += func_020e1438(&rects[count], cap - count, y, 0, chunk, height);
            y += chunk;
        }
    }
    obj->panel->count = count;

    unsigned int offset = 0;
    unsigned char display = obj->panel->display;
    int prod;
    struct SpriteRect_020e1b2c* arr;
    unsigned int n = obj->panel->count;
    arr = obj->panel->rects;
    for (count = 0; count < n; count++) {
        struct SpriteRect_020e1b2c* e = &arr[count];
        e->offset = offset;
        prod = e->width * e->height;
        unsigned int mask = 1 << _Z26GetDisplayModeCode0209378ci(display);
        if (mask != 0) mask--;
        offset += (~mask) & (mask + (prod >> 1));
    }
    obj->panel->field34 = offset;

    int size = func_020937f0(obj->panel->display);
    if (arg != -1) size = arg;
    obj->panel->field30 =
        size - (obj->panel->field34 + GetHalfProductField8((struct HasDims020e1288*)obj->panel));
    RunCacheHookForField0x14((struct Struct020e1384*)((char*)obj->panel + 0xc));
    return obj->panel->field30;
}
