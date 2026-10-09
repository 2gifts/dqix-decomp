#include <globaldefs.h>
#include "std_library_functions.h"

struct SpriteContext0205ac40 {
    char padding[0x50];
    unsigned char subScreen;
};

struct B174Inner;

struct B174Outer {
    unsigned short count;
    unsigned short field_2;
    B174Inner* inner;
    char padding_8[0xc];
    int position[2];
    int field_1c;
    unsigned short matrixIndex;
    unsigned char firstObject;
    unsigned char transformed;
    unsigned char doubleSize;
    signed char palette;
    signed char priority;
};

struct OAM0205ac40 {
    unsigned int attributes;
    unsigned short tile;
    short matrix;
};

struct Matrix0205ac40 {
    int values[4];
};

extern "C" void* func_0203bd08();
extern "C" OAM0205ac40* func_0203be4c(void*);
extern "C" OAM0205ac40* func_0203be40(void*);
extern "C" void func_0205b0d8(SpriteContext0205ac40*, Matrix0205ac40*, Matrix0205ac40*, B174Outer*);
extern "C" void func_020b0a1c(OAM0205ac40*, unsigned short, B174Outer*, Matrix0205ac40*, int*, unsigned short, int);
int GetBits10And11(int, B174Outer*);

// USA: func_0205ac40
extern "C" ARM void func_0205ac40(SpriteContext0205ac40* context, B174Outer* sprite) {
    int palette;
    unsigned short count;
    int priority;
    void* manager;
    OAM0205ac40* objects;
    Matrix0205ac40* matrix;
    bool doubleSize;
    OAM0205ac40* target;
    Matrix0205ac40 transform;
    Matrix0205ac40 affine;
    int position[2];
    if (sprite != NULL) {
        manager = func_0203bd08();
        matrix = NULL;
        objects = func_0203be4c(manager);
        if (context->subScreen == 0) objects = func_0203be40(manager);
        doubleSize = false;
        if (sprite->transformed) {
            func_0205b0d8(context, &transform, &affine, sprite);
            matrix = &transform;
            if (sprite->doubleSize) doubleSize = true;
        }
        unsigned short first = sprite->firstObject & 0x7f;
        unsigned short available = 128 - first;
        if (matrix != NULL) {
            OAM0205ac40* target = objects + sprite->matrixIndex * 4;
            target[0].matrix = affine.values[0] >> 4;
            target[1].matrix = affine.values[1] >> 4;
            target[2].matrix = affine.values[2] >> 4;
            target[3].matrix = affine.values[3] >> 4;
        }
        COPY_ARRAY(position, sprite->position);
        if (position[1] < -0x40000 || position[1] >= 0xc0000) return;
        target = objects + first;
        func_020b0a1c(target, available, sprite, matrix, sprite->position, sprite->matrixIndex, doubleSize);
        palette = sprite->palette;
        priority = sprite->priority;
        if (palette < 0 && priority < 0) return;
        int mode = GetBits10And11((int)context, sprite);
        count = sprite->count;
        while (count != 0) {
            if (palette >= 0) {
                target->attributes = (target->attributes & ~0xc00) | (mode << 10);
                target->tile = (target->tile & ~0xf000) | (palette << 12);
            }
            if (priority >= 0)
                target->tile = (target->tile & ~0xc00) | (priority << 10);
            ++target;
            --count;
        }
    }
}
