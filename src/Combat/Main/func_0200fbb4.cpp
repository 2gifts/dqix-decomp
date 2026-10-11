#include <globaldefs.h>

union CopyVector0200fbb4 { int words[3]; };
union CopyBlock0200fbb4 { int words[12]; };

struct CopyRecord0200fbb4 {
    unsigned short field00;
    unsigned char field02, field03, field04, field05, field06, field07;
    unsigned char field08, field09, field0a;
    signed char field0b;
    unsigned char field0c, field0d, field0e;
    unsigned char padding0f;
    CopyVector0200fbb4 field10;
    short field1c, field1e;
    int field20, field24, field28, field2c;
    CopyBlock0200fbb4 field30;
    unsigned char field60, field61, field62, field63, field64;
    unsigned char field65, field66, field67, field68, field69;
    short field6a, field6c;
    unsigned char field6e;
};

// USA: func_0200fbb4
// JPN: func_0200fbb4
extern "C" ARM CopyRecord0200fbb4* func_0200fbb4(CopyRecord0200fbb4* dst, const CopyRecord0200fbb4* src) {
    dst->field00 = src->field00;
    dst->field02 = src->field02;
    dst->field03 = src->field03;
    dst->field04 = src->field04;
    dst->field05 = src->field05;
    dst->field06 = src->field06;
    dst->field07 = src->field07;
    dst->field08 = src->field08;
    dst->field09 = src->field09;
    dst->field0a = src->field0a;
    dst->field0b = src->field0b;
    dst->field0c = src->field0c;
    dst->field0d = src->field0d;
    dst->field0e = src->field0e;
    dst->field10 = src->field10;
    dst->field1c = src->field1c;
    dst->field1e = src->field1e;
    dst->field20 = src->field20;
    dst->field24 = src->field24;
    dst->field28 = src->field28;
    dst->field2c = src->field2c;
    dst->field30 = src->field30;
    dst->field60 = src->field60;
    dst->field61 = src->field61;
    dst->field62 = src->field62;
    dst->field63 = src->field63;
    dst->field64 = src->field64;
    dst->field65 = src->field65;
    dst->field66 = src->field66;
    dst->field67 = src->field67;
    dst->field68 = src->field68;
    dst->field69 = src->field69;
    dst->field6a = src->field6a;
    dst->field6c = src->field6c;
    dst->field6e = src->field6e;
    return dst;
}
