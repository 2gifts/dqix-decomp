#include "GameState/GameState.h"
#include <globaldefs.h>

struct Slots_0216c9fb {
    signed char v[4];
};

extern "C" void *memset(void *dst, int value, unsigned int length);
void *GetPtrField0x2a04(GameState *gameState);
void FilterSlotsWithFlag0x800020dc4d0(signed char *out, signed char *outCount);
extern "C" void func_ov002_0215be00(void *obj, int val, int a2, int a3);
extern "C" void func_ov002_0215e644(unsigned char *obj, void *buf, int a);
extern "C" void func_0205d304(void *, void *, int, int, bool, bool, void *, bool);
extern "C" void _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(unsigned char *obj, unsigned char a, void *b, int c,
                                                                     unsigned char d);
extern "C" unsigned char *_Z23FindElementByC40205d81cP15Struct_0205d81ci(unsigned char *s, int key);
void SetField0xa0AndByte0xc4IfFlag0x1Clear(unsigned char *obj, int value, unsigned char b);
extern "C" void func_0204ecb4(unsigned char *wnd, int a, int b, int w, int h, signed char *margins);
extern "C" void _Z36InvokeHandlerAfterCacheFlush0204fbf8P11Obj0204fbf8(unsigned char *obj);
extern "C" void _Z17SetElementFieldC2P15Struct_0205d81cii(unsigned char *obj, int a, int b);

extern Slots_0216c9fb data_ov002_0216c9fb;

// USA: func_ov002_0215e44c
extern "C" ARM void func_ov002_0215e44c(unsigned char *self) {
    GetPtrField0x2a04(GameState::GetInstance());
    signed char count    = 0;
    Slots_0216c9fb slots = data_ov002_0216c9fb;
    FilterSlotsWithFlag0x800020dc4d0(slots.v, &count);
    int x = 0x10;
    x -= count * 4;
    for (signed char i = 0; i < count; i++) {
        *(signed char *) (self + 0x1c20) = slots.v[i];
        func_ov002_0215be00(self, (unsigned char) (*(signed char *) (self + 0x1c20) + 0x2c), (short) x, 3);
        memset(*(void **) (self + 0x1bd0), 0, 0x960);
        func_ov002_0215e644(self, *(void **) (self + 0x1bd0), 0);
        func_0205d304(self + 0x2c8 + 0xc00, *(void **) (self + 0x1bd0), 0, 0, false, false, 0, false);
        unsigned char key = (unsigned char) (*(signed char *) (self + 0x1c20) + 0x2c);
        if ((unsigned char) (key + 0xd4) <= 3) {
            _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(self + 0x2c8 + 0xc00, key, *(void **) (self + 0x1bd0), 1, 0);
            unsigned char *elem = _Z23FindElementByC40205d81cP15Struct_0205d81ci(self + 0x2c8 + 0xc00, key);
            if (elem != 0) {
                short ex = *(short *) (elem + 0xac);
                short ey = *(short *) (elem + 0xae);
                short ew = *(short *) (elem + 0xa8);
                short eh = *(short *) (elem + 0xaa);
                SetField0xa0AndByte0xc4IfFlag0x1Clear(elem, *(int *) (elem + 0xa0), key);
                func_0204ecb4(elem, ex, ey, ew, eh, 0);
                _Z36InvokeHandlerAfterCacheFlush0204fbf8P11Obj0204fbf8(elem);
            }
        }
        x += 8;
    }
    for (int j = 0; j < count; j++) {
        *(signed char *) (self + 0x1c20) = slots.v[j];
        _Z17SetElementFieldC2P15Struct_0205d81cii(self + 0x2c8 + 0xc00,
                                                  (unsigned char) (*(signed char *) (self + 0x1c20) + 0x2c),
                                                  (unsigned short) (*(signed char *) (self + 0x1c20) + 6));
    }
    *(signed char *) (self + 0x1c20) = -1;
}
