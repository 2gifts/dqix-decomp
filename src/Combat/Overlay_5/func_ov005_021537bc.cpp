#if defined(jpn)
#define R(j,u) (j)
#define _Z25ForwardTableValue02075db0P14Struct02075db0ii func_02076ccc
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "System/Graphics.h"

extern "C" void func_02047554(void* object, int index, int mode);
struct Struct02075db0;
#if defined(jpn)
#define ForwardTableValue02075db0 func_02076ccc
extern "C" int ForwardTableValue02075db0(Struct02075db0* object, int x, int y);
#else
int ForwardTableValue02075db0(Struct02075db0* object, int x, int y);
#endif

struct View021537bc {
    unsigned char* backing;
    unsigned int step4;
    unsigned char pad8[0x28 - 8];
    unsigned int x28;
    unsigned int y2c;
    unsigned int width30;
    unsigned int height34;
    int z38;
};

// USA: func_ov005_021537bc
extern "C" ARM void func_ov005_021537bc(void* object, int mode, unsigned short value) {
    View021537bc* self = (View021537bc*)object;
    if (self->backing == 0) return;
    unsigned int x = self->x28;
    unsigned int y = self->y2c;
    int startX = (int)(x & ~0xfffU);
    int startY = (int)(y & ~0xfffU);
    int endX = (int)((x + self->width30 - self->step4) & ~0xfffU);
    int endY = (int)((y + self->height34 - self->step4) & ~0xfffU);
    int coords[4][2] = {
        { startX, startY },
        { endX, startY },
        { startX, endY },
        { endX, endY }
    };
    for (int i = 0; i < 4; ++i) {
        int px = coords[i][0];
        int py = coords[i][1];
        switch (mode) {
        case 0: {
            GXFIFO_MATRIX_PUSH = 0;
            int z = self->z38;
            GXFIFO_MATRIX_TRANSLATE = px;
            GXFIFO_MATRIX_TRANSLATE = py;
            GXFIFO_MATRIX_TRANSLATE = z;
            *(unsigned short*)(self->backing + i * 0x88 + 0x80) = value;
            func_02047554(self->backing + i * 0x88, 0, 1);
            GXFIFO_MATRIX_POP = 1;
            break;
        }
        case 1:
            ForwardTableValue02075db0((Struct02075db0*)(self->backing + i * 0x70),
                px >> 12, py >> 12);
            break;
        case 2: {
            unsigned char* entry = self->backing + i * 0x28;
            *(int*)(entry + 0x14) = px;
            *(int*)(entry + 0x18) = py;
            break;
        }
        }
    }
}
