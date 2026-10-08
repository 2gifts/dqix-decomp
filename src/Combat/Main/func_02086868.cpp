#include <globaldefs.h>

union CopyBytes13_02086868 { unsigned char bytes[13]; };
union CopyWords13_02086868 { int words[13]; };
union CopyWords39_02086868 { int words[39]; };
union CopyBytes27_02086868 { unsigned char bytes[27]; };
union CopyBytes9_02086868 { unsigned char bytes[9]; };
union CopyBytes36_02086868 { unsigned char bytes[36]; };
union CopyBytes12_02086868 { unsigned char bytes[12]; };
union CopyWords5_02086868 { int words[5]; };
union CopyHalfwords14_02086868 { unsigned short halfwords[14]; };
union CopyHalfwords96_02086868 { unsigned short halfwords[96]; };

struct CopyEntry02086868 {
    signed char field00;
    unsigned char field01;
    CopyBytes13_02086868 field02;
    CopyBytes13_02086868 field0f;
    CopyWords13_02086868 field1c;
    int field50;
    unsigned short field54;
    unsigned char padding56[2];
    CopyWords39_02086868 field58;
    unsigned short fieldf4;
    CopyBytes27_02086868 fieldf6;
    CopyBytes9_02086868 field111;
    CopyBytes36_02086868 field11a;
    unsigned char field13e;
    unsigned char field13f;
    CopyBytes12_02086868 field140;
    CopyWords5_02086868 field14c;
    CopyHalfwords14_02086868 field160;
    CopyHalfwords96_02086868 field17c;
};

// USA: func_02086868
extern "C" ARM void* func_02086868(void* destination, void* source) {
    CopyEntry02086868* dst = (CopyEntry02086868*)destination;
    CopyEntry02086868* src = (CopyEntry02086868*)source;
    dst->field00 = src->field00;
    dst->field01 = src->field01;
    dst->field02 = src->field02;
    dst->field0f = src->field0f;
    dst->field1c = src->field1c;
    dst->field50 = src->field50;
    dst->field54 = src->field54;
    dst->field58 = src->field58;
    dst->fieldf4 = src->fieldf4;
    dst->fieldf6 = src->fieldf6;
    dst->field111 = src->field111;
    dst->field11a = src->field11a;
    dst->field13e = src->field13e;
    dst->field13f = src->field13f;
    dst->field140 = src->field140;
    dst->field14c = src->field14c;
    dst->field160 = src->field160;
    dst->field17c = src->field17c;
    return destination;
}
