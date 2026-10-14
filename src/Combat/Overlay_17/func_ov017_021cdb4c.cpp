#include <globaldefs.h>

struct SearchStruct0202c1a4;
int GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4*);
extern "C" void* func_0205ec34(void);
extern "C" void* func_02012fe4(void);
void SetOrClearBitInArray_0206df6c(void* unused, unsigned char* array, int bit, int value);
void SetOrClearBit2_0201bf84(unsigned char* obj, int set);

struct Obj021cdb4c {
    char pad0[4];
    signed char field4;
    unsigned char caseSel;
    unsigned short field6;
    int field8;
};

// USA: func_ov017_021cdb4c
extern "C" ARM void func_ov017_021cdb4c(void* unused0, struct Obj021cdb4c* obj, int unused2, int unused3, struct SearchStruct0202c1a4* search) {
    if (obj->field4 >= 0 && obj->field4 != GetSearchStructCurrentArrEntry(search)) {
        return;
    }

    unsigned char* base = (unsigned char*)func_0205ec34();
    unsigned char* other = (unsigned char*)func_02012fe4();

    switch (obj->caseSel) {
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        break;
    case 1:
        SetOrClearBitInArray_0206df6c(base, base + 0x8c, obj->field6 + 0x212, obj->field8);
        break;
    case 8:
        SetOrClearBitInArray_0206df6c(base, base + 0x8c, obj->field6 + 0x79e, obj->field8);
        break;
    case 7:
        SetOrClearBitInArray_0206df6c(base, base + 0x8c, obj->field6 + 0x33e, obj->field8);
        SetOrClearBit2_0201bf84(other, 1);
        break;
    default:
        break;
    }
}
