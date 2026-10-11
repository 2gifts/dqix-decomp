#include <globaldefs.h>

struct Values021bd2f0 {
    unsigned short v[4];
};

struct Params021bd2f0 {
    unsigned char kind;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned short h4;
    unsigned short h6;
    unsigned char flag;
    unsigned char pad9;
    Values021bd2f0 values;
};

struct Obj021bd2f0 {
#if defined(jpn)
    unsigned char pad0[0xf8];
#else
    unsigned char pad0[0xfc];
#endif
    unsigned char dirty;
    unsigned char padfd[0x13c - 0xfd];
    unsigned char kind;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned short h4;
    unsigned short h6;
    unsigned char flag;
    unsigned char pad145;
    Values021bd2f0 values;
};

// JPN: func_ov017_021bd8e8
// USA: func_ov017_021bd2f0
extern "C" ARM void func_ov017_021bd2f0(Obj021bd2f0* obj, Params021bd2f0* params) {
    obj->kind = params->kind;
    obj->b1 = params->b1;
    obj->b2 = params->b2;
    obj->b3 = params->b3;
    obj->h4 = params->h4;
    obj->h6 = params->h6;
    obj->flag = params->flag;
    obj->values = params->values;
    obj->dirty = 1;
}
