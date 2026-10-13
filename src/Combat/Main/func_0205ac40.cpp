#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/SpriteAffineTransform.h"

struct OAM0205ac40 {
    unsigned int attributes;
    unsigned short tile;
    short matrix;
};

extern "C" void* func_0203bd08();
extern "C" OAM0205ac40* func_0203be4c(void*);
extern "C" OAM0205ac40* func_0203be40(void*);
extern "C" void func_020b0a1c(OAM0205ac40*, unsigned short, B174Outer*, Matrix2x2*, int*, unsigned short, int);

// USA: func_0205ac40
extern "C" ARM void func_0205ac40(SpriteContext0205ac40* context, B174Outer* sprite) {
    int palette;
    unsigned short count;
    int priority;
    void* manager;
    OAM0205ac40* objects;
    Matrix2x2* matrix;
    bool doubleSize;
    OAM0205ac40* target;
    Matrix2x2 transform;
    Matrix2x2 affine;
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
