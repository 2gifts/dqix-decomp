#include <globaldefs.h>

#if defined(jpn)
#include "Resource/CharacterCreationUI.h"
#include "Graphics/SpriteAffineTransform.h"

int GetField0_0205bafc(void*);
extern "C" void func_0205ac40(SpriteContext0205ac40*, B174Outer*);

extern "C" ARM void func_ov023_021dab5c(CharacterCreationUI* self, int x, int y, int width, int height) {
    int fixedHeight = height << 12;
    int fx = x << 12;
    int fy = y << 12;
    int minX, maxX, minY, maxY;
    if (self->state == 1) {
        int sumX = fx + (width << 12);
        int sumY = fy + fixedHeight;
        minX = fx - 0x7000;
        minY = fy - 0x7000;
        maxX = sumX - 0x1000;
        maxY = sumY - 0x1000;
        if (GetField0_0205bafc(&self->navigation) == 8 && self->navigation.rows == 1) {
            minX = fx - 0x4000;
            minY = fy - 0x4000;
            maxX = sumX - 0x4000;
            maxY = sumY - 0x4000;
        }
    } else {
        int sumX = fx + (width << 12);
        int sumY = fy + fixedHeight;
        minX = fx - 0x4000;
        minY = fy - 0x4000;
        maxX = sumX - 0x4000;
        maxY = sumY - 0x4000;
    }
    fix32_t* position = self->sprites[21].position;
    position[0] = minX;
    position[1] = minY;
    position = self->sprites[22].position;
    position[0] = maxX;
    position[1] = minY;
    position = self->sprites[23].position;
    position[0] = minX;
    position[1] = maxY;
    position = self->sprites[24].position;
    position[0] = maxX;
    position[1] = maxY;
    for (int i = 0; i < 4; ++i)
        func_0205ac40(self->spriteContext, &self->sprites[i + 21]);
}
#else
int GetField0_0205bafc(void* obj);
extern "C" void func_0205ac40(void* dst, void* entry);

// USA: func_ov023_021dab5c
extern "C" ARM void func_ov023_021dab5c(void* obj, int a1, int a2, int a3, int a4) {
    char* o = (char*)obj;
    int a4s = a4 << 12;
    int fx = a1 << 12;
    int fy = a2 << 12;
    int minX, minY, maxX, maxY;

    if (*(signed char*)(o + 0xc58) == 1) {
        int sumX = fx + (a3 << 12);
        int sumY = fy + a4s;
        minX = fx - 0x7000;
        minY = fy - 0x7000;
        maxX = sumX - 0x1000;
        maxY = sumY - 0x1000;
        if (GetField0_0205bafc(o + 0xbec) == 8 && *(int*)(o + 0xbf8) == 1) {
            minX = fx - 0x4000;
            minY = fy - 0x4000;
            maxX = sumX - 0x4000;
            maxY = sumY - 0x4000;
        }
    } else {
        int sumX = fx + (a3 << 12);
        int sumY = fy + a4s;
        minX = fx - 0x4000;
        minY = fy - 0x4000;
        maxX = sumX - 0x4000;
        maxY = sumY - 0x4000;
    }

    char* dst = *(char**)(o + 0x7e8);
    *(int*)(dst + 0x35c) = minX;
    *(int*)(dst + 0x360) = minY;
    *(int*)(dst + 0x384) = maxX;
    *(int*)(dst + 0x388) = minY;
    *(int*)(dst + 0x3ac) = minX;
    *(int*)(dst + 0x3b0) = maxY;
    *(int*)(dst + 0x3d4) = maxX;
    *(int*)(dst + 0x3d8) = maxY;

    int j;
    for (j = 0; j < 4; j++) {
        func_0205ac40(*(void**)(o + 0x7e4), dst + (j + 0x15) * 0x28);
    }
}
#endif
