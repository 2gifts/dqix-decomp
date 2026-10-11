#if defined(jpn)
#define R(j,u) (j)
#define func_ov006_02154e58 func_ov006_021565b0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Obj0215951c {
    char pad0[R(0x48, 0x50)];
    unsigned short* table;
    char pad54[0x362 - R(0x4c, 0x54)];
    short field362;
    char pad364[0x388 - 0x364];
    unsigned char field388;
    unsigned char field389;
};

// USA: func_ov006_0215951c
ARM void CalcField389_0215951c(struct Obj0215951c* obj) {
    int q;
    short idx;
    obj->field388 = 0;
    idx = obj->field362 - 0x5b;
    q = (obj->table[idx] + 7) / 8;
    obj->field389 = q;
    if ((q & 0xff) == 0) {
        obj->field389 = 1;
    }
}
