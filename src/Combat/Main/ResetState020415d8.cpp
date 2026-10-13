#include <globaldefs.h>

extern "C" void func_02037d10(void*);

struct State020415d8 {
    unsigned short flags_00;
#if defined(jpn)
    char pad_02[0x2c2];
#else
    char pad_02[0x2ce];
#endif
    unsigned short field_2d0;
    char pad_2d2[2];
    int field_2d4;
    char pad_2d8[0xc];
    int field_2e4;
    unsigned char field_2e8;
    char pad_2e9[3];
    int field_2ec;
    unsigned char field_2f0;
    char pad_2f1[3];
    int field_2f4;
};

// USA: func_020415d8
ARM void ResetState020415d8(struct State020415d8* obj) {
    func_02037d10(obj);
    obj->field_2d0 = 0;
    obj->field_2d4 = 0;
    obj->field_2e4 = 0;
    obj->field_2e8 = 0;
    obj->field_2f4 = 0;
    obj->field_2ec = 0x7a;
    obj->field_2f0 = 0;
    obj->flags_00 |= 0x4000;
    obj->flags_00 &= ~0x80;
}
