#include <globaldefs.h>

struct S_b20c { int field0; int field4; unsigned char field8; };
struct Entry0204df9c { int a; short b; short c; short d; short e; };

struct Obj0204df9c {
    char pad0[8];
    int field8;
    char pad1[0xa8 - 0xc];
    short fieldA8;
    short fieldAA;
};

void ClearTwoWordsAndByte_0205b20c(struct S_b20c* obj);
void SetField0_0205b220(void* obj, int value);
void SetFieldsAt0x4And0x8_0205b228(void* obj, int value, unsigned char flag);
extern "C" void func_0205b36c(void* obj, short v1, int v2, int v3, unsigned char v4, unsigned char v5);

// USA: func_0204df9c
extern "C" ARM void func_0204df9c(Obj0204df9c* obj, short v1, int v2, int v3, unsigned char stackArg1, unsigned char stackArg2) {
    if (v1 == 0) return;
    Entry0204df9c buf;
    buf.a = 0;
    buf.b = 0;
    buf.c = 0;
    buf.d = 0;
    buf.e = 0;
    buf.d = obj->fieldA8 << 3;
    buf.e = obj->fieldAA << 3;
    S_b20c localObj;
    ClearTwoWordsAndByte_0205b20c(&localObj);
    SetField0_0205b220(&localObj, obj->field8);
    SetFieldsAt0x4And0x8_0205b228(&localObj, (int)&buf, 1);
    func_0205b36c(&localObj, v1, v2, v3, stackArg1, stackArg2);
}
