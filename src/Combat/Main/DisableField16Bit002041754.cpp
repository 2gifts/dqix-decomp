#include <globaldefs.h>

struct Obj02041754 {
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    short field_14;
#if defined(jpn)
    unsigned char pad_16[5];
#endif
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4_7 : 4;
    unsigned char field_17;
    int field_18;
};

extern "C" int _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(int, int, int, int, unsigned char, unsigned char);

#if defined(jpn)
#define DisableField16Bit002041754 func_02041c7c
extern "C" ARM void func_02041c7c(struct Obj02041754* obj);
#endif

// USA: func_02041754
ARM void DisableField16Bit002041754(struct Obj02041754* obj) {
    if (obj->field_8 < 0) return;
    if (obj->b0 && obj->field_0 != 0) {
        _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(1, obj->field_0, obj->field_4, 0x80, 1, 1);
        obj->b0 = 0;
    }
}
