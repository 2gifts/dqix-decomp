#if defined(jpn)
#define R(j,u) (j)
#define func_ov006_02154e58 func_ov006_021565b0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct LookupByOffset0x362_021591ecStruct {
    unsigned char pad0[R(0x48, 0x50)];
    unsigned short* arr;
    unsigned char pad1[0x362 - R(0x4c, 0x54)];
    short f362;
};

// USA: func_ov006_021591ec
ARM unsigned short LookupByOffset_021591ec_021591ec(struct LookupByOffset0x362_021591ecStruct* s) {
    unsigned short result = 0;
    short idx = s->f362 - 0x5b;
    if (idx >= 0) {
        result = s->arr[idx];
    }
    return result;
}
