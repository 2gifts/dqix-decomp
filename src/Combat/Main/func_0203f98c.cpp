#include <globaldefs.h>

extern "C" void func_0203fc28(int s, int t);

extern unsigned short data_020e79d8[];

struct Quad0203f98c {
    unsigned short x;
    unsigned short y;
    unsigned short sizeS;
    unsigned short sizeT;

    unsigned short GetSizeS() const {
        unsigned short v = sizeS;
        return v;
    }
    unsigned short GetSizeT() const {
        unsigned short v = sizeT;
        return v;
    }
};

struct Obj0203f98c {
    char pad0[0x2a];
    unsigned short color;
    short field2c;
    short field2e;
    char pad1[0x50 - 0x30];
    unsigned int flags;
};

static inline void TexPlttBase(unsigned int addr, int texFmt) {
    *(volatile unsigned int*)0x040004ac = addr >> (4 - (texFmt == 2));
}

static inline void PolygonAttr(int light, int polyMode, int cullMode, int polygonID, int alpha, int misc) {
    *(volatile unsigned int*)0x040004a4 = light | (polyMode << 4) | cullMode | misc | (polygonID << 24) | (alpha << 16);
}

// USA: func_0203f98c
extern "C" ARM void func_0203f98c(struct Obj0203f98c* self, struct Quad0203f98c* quad, unsigned int texAddr, unsigned int palAddr, unsigned short fmt, unsigned short arg6, unsigned short arg7) {
    *(volatile unsigned int*)0x04000444 = 0;
    *(volatile unsigned int*)0x040004a8 = (texAddr >> 3) | (fmt << 26) | 0x40000000 | (quad->GetSizeS() << 20) | (quad->GetSizeT() << 23) | 0x20000000;
    TexPlttBase(palAddr, fmt);
    PolygonAttr(0, 0, 0xc0, self->field2e, self->field2c, 0x8000);

    unsigned int w = data_020e79d8[quad->GetSizeS()] << 12;
    unsigned int h = data_020e79d8[quad->GetSizeT()] << 12;
    unsigned int x = quad->x << 12;
    unsigned int y = quad->y << 12;

    if (self->flags & 2) {
        x = (arg6 << 12) - (w + x);
    }
    if (self->flags & 4) {
        y = (arg7 << 12) - (h + y);
    }

    *(volatile unsigned int*)0x04000470 = x;
    *(volatile unsigned int*)0x04000470 = y;
    *(volatile unsigned int*)0x04000470 = 0;
    *(volatile unsigned int*)0x0400046c = w;
    *(volatile unsigned int*)0x0400046c = h;
    *(volatile unsigned int*)0x0400046c = 0x1000;
    *(volatile unsigned int*)0x04000500 = 1;
    *(volatile unsigned int*)0x04000480 = self->color;

    if (self->flags & 2) {
        if (self->flags & 4) {
            func_0203fc28(w, 0);
            *(volatile unsigned int*)0x04000494 = 0x10000000;
            *(volatile unsigned int*)0x04000488 = 0;
            *(volatile unsigned int*)0x04000494 = 0x10001000;
            func_0203fc28(0, h);
            *(volatile unsigned int*)0x04000494 = 0x1000;
            func_0203fc28(w, h);
            *(volatile unsigned int*)0x04000494 = 0;
        } else {
            func_0203fc28(w, h);
            *(volatile unsigned int*)0x04000494 = 0x10000000;
            func_0203fc28(0, h);
            *(volatile unsigned int*)0x04000494 = 0x10001000;
            *(volatile unsigned int*)0x04000488 = 0;
            *(volatile unsigned int*)0x04000494 = 0x1000;
            func_0203fc28(w, 0);
            *(volatile unsigned int*)0x04000494 = 0;
        }
    } else {
        if (self->flags & 4) {
            *(volatile unsigned int*)0x04000488 = 0;
            *(volatile unsigned int*)0x04000494 = 0x10000000;
            func_0203fc28(w, 0);
            *(volatile unsigned int*)0x04000494 = 0x10001000;
            func_0203fc28(w, h);
            *(volatile unsigned int*)0x04000494 = 0x1000;
            func_0203fc28(0, h);
            *(volatile unsigned int*)0x04000494 = 0;
        } else {
            func_0203fc28(0, h);
            *(volatile unsigned int*)0x04000494 = 0x10000000;
            func_0203fc28(w, h);
            *(volatile unsigned int*)0x04000494 = 0x10001000;
            func_0203fc28(w, 0);
            *(volatile unsigned int*)0x04000494 = 0x1000;
            *(volatile unsigned int*)0x04000488 = 0;
            *(volatile unsigned int*)0x04000494 = 0;
        }
    }

    *(volatile unsigned int*)0x04000504 = 0;
    *(volatile unsigned int*)0x04000448 = 1;
}
