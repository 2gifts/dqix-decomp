#include <globaldefs.h>
#include "Util/Random.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct Packed_021f5680 {
    unsigned int lo : 7;
    unsigned int hi : 25;
};

struct Record_021f5680 {
    char pad0[4];
    short field4;
    struct Packed_021f5680 packed;
    char pad1[0x28 - 12];
};

struct Data021fff08_021f5680 {
    unsigned char count;
    char pad0[1];
    unsigned char flag;
    unsigned char index;
    char pad1[8];
    struct Record_021f5680* records;
};

extern struct Data021fff08_021f5680 data_ov023_021fff08;
extern unsigned char data_ov023_021fff1c[];

// USA: func_ov023_021f5680
extern "C" ARM int func_ov023_021f5680(struct Variant02030b0c* obj) {
    if (data_ov023_021fff08.flag == 0) {
        data_ov023_021fff08.index = data_ov023_021fff08.index + 1;
        return 1;
    }
    int v0 = ((Script::Parameter*)obj)->ToInt();
    int v1 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 8)))->ToInt();
    int v2 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 0x10)))->ToInt();
    int v3 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 0x18)))->ToInt();
    for (int i = 0; i < data_ov023_021fff08.count; i++) {
        if (data_ov023_021fff08.index == data_ov023_021fff1c[i]) {
            struct Random* rng = GetBTRandom();
            data_ov023_021fff08.records[i].field4 = (short)v0;
            ((struct Packed_021f5680*)((char*)data_ov023_021fff08.records + 8 + i * 0x28))->hi = v1;
            int n = NextRandomBetween(rng, v2, v3);
            ((struct Packed_021f5680*)((char*)data_ov023_021fff08.records + 8 + i * 0x28))->lo = n;
        }
    }
    data_ov023_021fff08.index = data_ov023_021fff08.index + 1;
    return 1;
}
