#include <globaldefs.h>

struct InitStruct;
struct ResetObject0209af34Struct;
struct ZeroWordAndByte0206ee60Struct;

ARM void InitializeStruct(struct InitStruct* s);
ARM void ClearHalfword0x18(void* obj);
extern "C" ARM void _Z19ClearBuffer0209bc84Pv(void* obj);
extern "C" ARM void _Z19ResetObject0209af34P25ResetObject0209af34Struct(struct ResetObject0209af34Struct* obj);
extern "C" void* _Z20Clear12Bytes0206efc4Pv(void* obj);
extern "C" ARM void _Z23ZeroWordAndByte0206ee60P29ZeroWordAndByte0206ee60Struct(struct ZeroWordAndByte0206ee60Struct* s);
extern "C" ARM void _Z20Clear12Bytes020a8e88Pv(void* p);

struct Flags020287b4 {
    unsigned short f00 : 2;
    unsigned short f02 : 1;
    unsigned short f03 : 1;
    unsigned short f04 : 12;
};

struct Elem020287b4 {
    unsigned short w00;
    struct Flags020287b4 flags;
    unsigned short w04;
    unsigned short w06;
    int w08;
    unsigned char b0c;
    signed char b0d;
    unsigned short pad0e;
    int w10;
#if !defined(jpn)
    int w14;
#endif
    unsigned char sub18[0x2c];
    unsigned short w44;
    unsigned char pad46[0x1a];
    unsigned char sub60[0xc0];
    unsigned char pad120[4];
    unsigned char sub124[0x1d4];
    unsigned char sub2f8[0xc];
    unsigned char sub304[5];
    unsigned char pad309[3];
    unsigned char sub30c[0xc];
};

// USA: func_020287b4
// JPN: func_020287b4
extern "C" ARM void func_020287b4(struct Elem020287b4* obj) {
    int i;
    struct Elem020287b4* e;

    for (i = 0; i < 4; i++) {
        e = &obj[i];
        e->flags.f02 = 0;
        e->flags.f03 = 0;
        e->flags.f00 = 0;
        obj[i].w00 = 0;
        e->w10 = 0;
#if !defined(jpn)
        e->w14 = 0;
#endif
        e->w08 = 0;
        e->w06 = 0;
        e->b0c = 0;
        e->flags.f04 = 0;
        e->w04 = 0;
        e->b0d = -1;
        InitializeStruct((struct InitStruct*)e->sub18);
        ClearHalfword0x18((void*)&e->w44);
        _Z19ClearBuffer0209bc84Pv(e->sub60);
        _Z19ResetObject0209af34P25ResetObject0209af34Struct((struct ResetObject0209af34Struct*)e->sub124);
        _Z20Clear12Bytes0206efc4Pv(e->sub2f8);
        _Z23ZeroWordAndByte0206ee60P29ZeroWordAndByte0206ee60Struct((struct ZeroWordAndByte0206ee60Struct*)e->sub304);
        _Z20Clear12Bytes020a8e88Pv(e->sub30c);
        e->flags.f00 = i;
    }
}
