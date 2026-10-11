#include <globaldefs.h>

class Battle0215b9a4 {
public:
    char unk_0[0x1bb8];
};

typedef void (Battle0215b9a4::*PageFn0215b9a4)(void *buf, int flag);

struct ModePage0215b9a4 {
    int a;
    int b;
};

extern PageFn0215b9a4 data_ov002_0216cfac[44];
extern unsigned int data_ov002_0216d3b0[2];
extern PageFn0215b9a4 data_020e6d5c;
extern ModePage0215b9a4 data_ov002_0216cae8[];
extern ModePage0215b9a4 data_ov002_0216caec[];

extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" unsigned char *_Z23FindElementByC40205d81cP15Struct_0205d81ci(char *s, int key);
extern "C" void _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(char *obj, int a, void *b, int c, unsigned char d);

// USA: func_ov002_0215b9a4
extern "C" ARM void func_ov002_0215b9a4(Battle0215b9a4 *self, unsigned char key, int flag) {
    char *base          = (char *) self;
    unsigned char *elem = _Z23FindElementByC40205d81cP15Struct_0205d81ci(base + 0x2c8 + 0xc00, key);
    if (elem == 0) {
        return;
    }
    if (flag) {
        elem[0xc5] |= 0x40;
    } else {
        elem[0xc5] &= ~0x40;
    }
    int hl = 0;
    if (elem[0xc5] & 2) {
        hl = 1;
    }
    memset(*(void **) (base + 0x1000 + 0xbd0), 0, 0x960);
    if (!(data_ov002_0216d3b0[1] & 1)) {
        PageFn0215b9a4 nul      = data_020e6d5c;
        data_ov002_0216cfac[0]  = nul;
        data_ov002_0216cfac[23] = nul;
        data_ov002_0216cfac[30] = nul;
        data_ov002_0216cfac[36] = nul;
        data_ov002_0216cfac[40] = nul;
        data_ov002_0216cfac[41] = nul;
        data_ov002_0216cfac[42] = nul;
        data_ov002_0216cfac[43] = nul;
        data_ov002_0216d3b0[1] |= 1;
    }
    if (data_ov002_0216cfac[key] == 0) {
        return;
    }
    (self->*data_ov002_0216cfac[key])(*(void **) (base + 0x1000 + 0xbd0), hl);
    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(base + 0x2c8 + 0xc00, key, *(void **) (base + 0x1000 + 0xbd0), 0, 0);
    if (*(int *) (base + 0x1000 + 0xbcc) == 0) {
        return;
    }
    for (int i = 0; data_ov002_0216cae8[i].a >= 0; i++) {
        if (*(int *) (base + 0x1000 + 0xbb8) == data_ov002_0216cae8[i].a) {
            int page = data_ov002_0216caec[i].a;
            memset(*(void **) (base + 0x1000 + 0xbd0), 0, 0x960);
            if (data_ov002_0216cfac[page] == 0) {
                break;
            }
            (self->*data_ov002_0216cfac[page])(*(void **) (base + 0x1000 + 0xbd0), hl);
            _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(base + 0x2c8 + 0xc00, (unsigned char) page,
                                                                 *(void **) (base + 0x1000 + 0xbd0), 0, 0);
        }
    }
    *(int *) (base + 0x1000 + 0xbcc) = 0;
}
