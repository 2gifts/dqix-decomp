#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x371c
#else
#define REGION_OFFSET_0 0x3760
#endif


struct Result02162c14 {
    char pad0[0x18];
    signed char field18;
    char pad1[0x1c - 0x19];
    signed char field1c;
    signed char field1d;
    char pad2[0x26 - 0x1e];
    unsigned short field26;
    char pad3[0x2c - 0x28];
    short field2c;
    signed char field2e;
};

extern "C" struct Result02162c14* func_ov000_02161318(char* arr, int p1);
extern "C" int _Z25GetClampedArrayField0xd1cPci(char* arr, int idx);
extern "C" int _Z25GetClampedArrayField0xd3cPci(char* arr, int idx);

// USA: func_ov000_02162c14
extern "C" ARM void func_ov000_02162c14(char* obj, int p1, char* out) {
    struct Result02162c14* r = func_ov000_02161318(obj + REGION_OFFSET_0, p1);
    if (r == 0) {
        return;
    }
    signed char v18 = r->field18;
    out[0] = *(signed char*)((char*)r + v18 + 0x10);
    out[1] = r->field1c;
    out[2] = (signed char)_Z25GetClampedArrayField0xd1cPci(obj + REGION_OFFSET_0, r->field1d);
    out[3] = (signed char)_Z25GetClampedArrayField0xd3cPci(obj + REGION_OFFSET_0, r->field1d);
    *(short*)(out + 6) = r->field2c;
    out[4] = r->field2e;
    *(unsigned short*)(out + 8) = r->field26;
}
