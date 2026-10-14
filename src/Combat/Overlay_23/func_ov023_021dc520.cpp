#include <globaldefs.h>
#include "Graphics/SpriteAffineTransform.h"
#include "System/Cache.h"
#include "System/LoadToVRAM.h"
#include <std_library_functions.h>

#if defined(jpn)
#define REGION(j,u) (j)
#define data_ov023_021fd565 data_ov023_021fc854
#else
#define REGION(j,u) (u)
#endif

struct ParentFlags021dc520 { int field0; unsigned int unknown0:27; unsigned int first:1; unsigned int second:1; unsigned int unknown1:3; };
struct Obj020dee58 { ParentFlags021dc520* parent; int field4; unsigned int lowNibble:4; unsigned int midField:5; unsigned int rowCount:3; unsigned int unknown:20; };
struct Struct02075db0 { char pad0[0x14]; void* objects; char pad18[0xc]; int** rows; char pad28[0x34]; unsigned short field5c; char pad5e[2]; int columnIndex, rowIndex; };
struct ObjectBuffer021dc520 { char pad0[0x2a0]; char reservedObjects[1]; };
struct Gauge021dc520 { short value; short unknown2; short x, y; };
struct GaugeData021dc520 { char pad0[0x4c]; short paletteValue; char pad4e[2]; unsigned char enabled; };
struct View021dc520 {
    char pad0[0x4c];
    Obj020dee58* selection;
    char pad50[0x74];
    Struct02075db0* table;
    char padc8[REGION(0x60,0x64)];
    SpriteContext0205ac40 renderer;
    B174Outer sprites[30];
    char pad630[REGION(0xc4,0x144)];
    unsigned short flags;
    char pad776[5];
    signed char mode, subScreen;
    char pad77d[0x1e];
    unsigned char unknown0:1;
    unsigned char allowActive:1;
    unsigned char unknown1:6;
};
extern GaugeData021dc520 data_ov023_021ff9e0;
extern Gauge021dc520 data_ov023_021ffa0c[3];
extern unsigned char data_ov023_021fd565[2][2];
extern "C" void* func_0203bd08();
extern "C" ObjectBuffer021dc520* func_0203be40(void*);
extern "C" ObjectBuffer021dc520* func_0203be4c(void*);
extern "C" void func_0205ac40(SpriteContext0205ac40*, B174Outer*);
short LookupValueFromField8(Obj020dee58*);
int ForwardTableValue02075db0(Struct02075db0*, int, int);
inline int PaletteOffset021dc520(int index) { return index * 2; }
inline int IsStandardCategory021dc520(Obj020dee58* selection) {
    return selection->lowNibble <= 7;
}

// USA: func_ov023_021dc520
extern "C" ARM void func_ov023_021dc520(View021dc520* view) {
    if (view->mode == 1) {
        if (!view->allowActive || !(view->flags & 0x2000)) return;
    }
    if (!(view->flags & 2) || !view->selection) return;
    B174Outer* sprite;
    ObjectBuffer021dc520* objects;
    if (view->subScreen == 0) {
        ObjectBuffer021dc520* screenObjects = func_0203be40(func_0203bd08());
        objects = screenObjects;
    } else {
        ObjectBuffer021dc520* screenObjects = func_0203be4c(func_0203bd08());
        objects = screenObjects;
    }
    if (data_ov023_021ff9e0.enabled) {
        for (int i = 0; i < 3; ++i) {
            short gaugeValue = data_ov023_021ffa0c[i].value;
            Gauge021dc520* gauge = &data_ov023_021ffa0c[i];
            int style = 0;
            float progress;
            if (i == 2) {
                progress = 0.0001f + (float)(20 - (gaugeValue - 3)) / 20.0f;
                if (progress < 0.2f) style = 1;
                else if (progress < 0.4f) style = 2;
                else if (progress < 0.6f) style = 3;
                else if (progress < 0.8f) style = 2;
                else if (progress < 1.0f) style = 1;
            } else {
                progress = 0.0001f + (float)(10 - (gaugeValue - 5)) / 10.0f;
                if (progress < 0.25f) style = 1;
                else if (progress < 0.75f) style = 2;
                else if (progress < 1.0f) style = 1;
            }
            if (style > 0) {
                if (style == 1) sprite = &view->sprites[26];
                else if (style == 2) sprite = &view->sprites[27];
                else sprite = &view->sprites[28];
                int y = (gauge->y + 10) << 12;
                int x = (gauge->x + REGION(190,202)) << 12;
                sprite->position[0] = x;
                sprite->position[1] = y;
                sprite->firstObject = i + 0x48;
                func_0205ac40(&view->renderer, sprite);
            }
        }
    }
    if (!(view->flags & 0x1000)) {
        int x = REGION(191,203);
        unsigned char index = 0;
        while (index < view->selection->rowCount) {
            sprite = &view->sprites[21];
            int offset = 0;
            if (view->selection->rowCount == 5) {
                sprite = &view->sprites[24];
                offset = 1;
                int intensity = abs(20 - data_ov023_021ff9e0.paletteValue) - 5;
                if (intensity < 0) intensity = 0;
                else if (intensity > 10) intensity = 10;
                for (int paletteIndex = 2; paletteIndex <= 6; ++paletteIndex) {
                    int value = intensity + paletteIndex * 3 - 14;
                    int red = (value * 10) / 10 + 14;
                    int green = (value * 3) / 10 + 29;
                    if (red > 31) red = 31;
                    if (green > 31) green = 31;
                    if (red < 0) red = 0;
                    if (green < 0) green = 0;
                    unsigned short color = red | (green << 5) | (green << 10);
                    int paletteOffset = PaletteOffset021dc520(paletteIndex);
                    CleanInvalidateCacheRange(&color, 2);
                    int destination = 0xe0 + paletteOffset;
                    if (view->subScreen == 0) LoadToMainObjStandardPalette(&color, destination, 2);
                    else LoadToSubObjStandardPalette(&color, destination, 2);
                }
            }
            sprite->position[0] = (x + offset) << 12;
            sprite->position[1] = (offset + 11) << 12;
            sprite->firstObject = index + 0x4c;
            func_0205ac40(&view->renderer, sprite);
            x += 8;
            ++index;
        }
    }
    int lookup = LookupValueFromField8(view->selection);
    sprite = &view->sprites[lookup + 1];
    sprite->position[0] = REGION(0x18000,0x10000);
    sprite->position[1] = 0x8000;
    sprite->firstObject = 0x52;
    func_0205ac40(&view->renderer, sprite);
    if (IsStandardCategory021dc520(view->selection)) {
        int first = 0, second = 0;
        ParentFlags021dc520* parent = view->selection->parent;
        if (parent) {
            if (parent->first == 1) first = 1;
            if (parent->second == 1) second = 1;
        }
        unsigned char indicator = data_ov023_021fd565[first][second];
        if (indicator) {
            sprite = &view->sprites[indicator];
            sprite->position[0] = REGION(0x9a000,0x90000);
            sprite->position[1] = 0x8000;
            sprite->firstObject = 0x53;
            func_0205ac40(&view->renderer, sprite);
        }
        if (!(view->flags & 8)) {
            func_0203bd08();
            view->table->objects = objects->reservedObjects;
            ForwardTableValue02075db0(view->table, 0x1c, 0x34);
        }
    } else {
        if (!(view->flags & 8)) {
            view->table->objects = objects->reservedObjects;
            ForwardTableValue02075db0(view->table, 0x1c, 0x34);
        }
    }
}
