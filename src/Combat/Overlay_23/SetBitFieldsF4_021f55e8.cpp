#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

struct BitFieldsF4_021f55e8 {
    unsigned int low : 12;
    unsigned int mid : 4;
    unsigned int hi : 5;
    unsigned int rest : 11;
};

struct StructWithF4_021f55e8 {
    char pad[0xf4];
    struct BitFieldsF4_021f55e8 f4;
};

struct Data021fff08_021f55e8 {
    char pad2[2];
    unsigned char flag2;
    char pad3[9];
    struct StructWithF4_021f55e8* ptr;
};

extern struct Data021fff08_021f55e8 data_ov023_021fff08;

// USA: func_ov023_021f55e8  (semantic: SetBitFieldsF4_021f55e8)
extern "C" ARM int func_ov023_021f55e8(void* objRaw) {
    struct Variant02030b0c* obj = (struct Variant02030b0c*)objRaw;
    if (data_ov023_021fff08.flag2 == 0) return 1;
    data_ov023_021fff08.ptr->f4.low = ((Script::Parameter*)obj)->ToInt();
    data_ov023_021fff08.ptr->f4.mid = ((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 8)))->ToInt();
    data_ov023_021fff08.ptr->f4.hi = ((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 0x10)))->ToInt();
    return 1;
}
