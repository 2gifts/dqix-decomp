#include <globaldefs.h>

struct Obj02081ce8 {
    float field0;
    char pad1[0x6 - 0x4];
    short short6;
    short short8;
    char fieldA;
    char padB;
    char fieldC;
    char pad3[0x13 - 0xd];
    unsigned char lowNibble : 4;
    unsigned char highNibble : 4;
    char pad4[0x28 - 0x14];
    short short28;
    unsigned char byte2a;
};

extern "C" void __clear(void* buf, int n);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" int func_020420e8(void* builder, void* obj);
extern "C" void func_0204f41c(int a, short b, short c, void* buf, int d, int e, void* f, void* g, int h);
extern char data_020f0ff2;

// USA: func_02081ce8
ARM void FormatValueAndDispatch02081ce8(void* unused0, int param1, struct Obj02081ce8* obj, int unused3) {
    int r4val = obj->highNibble;
    if (obj->byte2a & 4) {
        r4val = 5;
    }
    char buf[0x40];
    __clear(buf, 0x40);
    sprintf(buf, &data_020f0ff2, (double)obj->field0);
    int r1val = func_020420e8(buf, 0);
    int nibble = obj->lowNibble;
    short sum = (short)((obj->short6 + obj->short28) - r1val);
    func_0204f41c(param1, sum, obj->short8, buf, nibble, r4val, &obj->fieldA, &obj->fieldC, 0);
}
