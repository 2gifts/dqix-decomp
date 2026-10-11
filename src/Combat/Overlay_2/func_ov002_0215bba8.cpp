#include <globaldefs.h>

class Battle0215bba8 {
public:
    char unk_0[0x1bb8];
};

typedef void (Battle0215bba8::*PageFn0215bba8)(void *buf, int flag);

struct ModePage0215bba8 {
    int a;
    int b;
};

struct Global02114e54 {
    char unk_0[0x24];
    unsigned short f24;
    char unk_26[0x5f - 0x26];
    unsigned char f5f;
};

extern PageFn0215bba8 data_ov002_0216d10c[44];
extern unsigned int data_ov002_0216d3b0[2];
extern PageFn0215bba8 data_020e6d5c;
extern ModePage0215bba8 data_ov002_0216cb18[];
extern ModePage0215bba8 data_ov002_0216cb1c[];
extern Global02114e54 data_02114e54;

extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" unsigned char *_Z23FindElementByC40205d81cP15Struct_0205d81ci(char *s, unsigned char key);
extern "C" void _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(char *obj, int a, void *b, int c, unsigned char d);

struct W0215bba8 {
    char pad[0x34];
    int f34;
};
// USA: func_ov002_0215bba8
extern "C" ARM void func_ov002_0215bba8(Battle0215bba8 *self) {
    char *base = (char *) self;
    int mode   = *(int *) (base + 0x1000 + 0xbc8);
    if (mode == 0) {
        return;
    }
    int hl = 0;
    if (mode == 2) {
        if (data_02114e54.f5f != 0 && data_02114e54.f24 != 0) {
            W0215bba8 *w = (W0215bba8 *) (base + 0x2c8 + 0xc00) + 1;
            w--;
            if (w->f34 < 0) {
                return;
            }
        }
        hl = 1;
    }
    memset(*(void **) (base + 0x1000 + 0xbd0), 0, 0x960);
    if (!(data_ov002_0216d3b0[0] & 1)) {
        PageFn0215bba8 nul      = data_020e6d5c;
        data_ov002_0216d10c[0]  = nul;
        data_ov002_0216d10c[23] = nul;
        data_ov002_0216d10c[30] = nul;
        data_ov002_0216d10c[36] = nul;
        data_ov002_0216d10c[40] = nul;
        data_ov002_0216d10c[41] = nul;
        data_ov002_0216d10c[42] = nul;
        data_ov002_0216d10c[43] = nul;
        data_ov002_0216d3b0[0] |= 1;
    }
    int key = *(int *) (base + 0x1000 + 0xbb8);
    if (data_ov002_0216d10c[key] == 0) {
        return;
    }
    if (_Z23FindElementByC40205d81cP15Struct_0205d81ci(base + 0x2c8 + 0xc00, (unsigned char) key) != 0) {
        (self->*data_ov002_0216d10c[*(int *) (base + 0x1000 + 0xbb8)])(*(void **) (base + 0x1000 + 0xbd0), hl);
        _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(
            base + 0x2c8 + 0xc00, (unsigned char) *(int *) (base + 0x1000 + 0xbb8), *(void **) (base + 0x1000 + 0xbd0), 0, 0);
    }
    if (*(int *) (base + 0x1000 + 0xbcc) == 0) {
        return;
    }
    for (int i = 0; data_ov002_0216cb18[i].a >= 0; i++) {
        if (*(int *) (base + 0x1000 + 0xbb8) == data_ov002_0216cb18[i].a) {
            int page = data_ov002_0216cb1c[i].a;
            memset(*(void **) (base + 0x1000 + 0xbd0), 0, 0x960);
            if (data_ov002_0216d10c[page] == 0) {
                break;
            }
            if (_Z23FindElementByC40205d81cP15Struct_0205d81ci(base + 0x2c8 + 0xc00, page) == 0) {
                continue;
            }
            (self->*data_ov002_0216d10c[page])(*(void **) (base + 0x1000 + 0xbd0), hl);
            _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(base + 0x2c8 + 0xc00, (unsigned char) page,
                                                                 *(void **) (base + 0x1000 + 0xbd0), 0, 0);
        }
    }
    *(int *) (base + 0x1000 + 0xbcc) = 0;
}
