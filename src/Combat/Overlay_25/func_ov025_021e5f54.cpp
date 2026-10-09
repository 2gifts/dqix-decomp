#include <globaldefs.h>

struct Inner021e5f54 {
    char pad0[0x21c];
    unsigned short field_21c;
    char pad21e[2];
    short field_220;
    short field_222;
};

struct Holder021e5f54 {
    char pad0[0xc];
    Inner021e5f54* inner;
};

extern Holder021e5f54 data_ov025_021ef988;

struct Param021e5f54 {
    char pad0[8];
    unsigned int hasValue : 1;
    unsigned int value : 15;
    unsigned int flag16 : 1;
    unsigned int hasLimit : 1;
    unsigned int : 14;
    unsigned int limit : 15;
};

// USA: func_ov025_021e5f54
extern "C" ARM int func_ov025_021e5f54(Param021e5f54* p) {
    if (p->hasValue) {
        data_ov025_021ef988.inner->field_21c = p->value;
    } else {
        data_ov025_021ef988.inner->field_21c = 0;
    }
    if (p->flag16) {
        data_ov025_021ef988.inner->field_220 = 0x1e;
    } else {
        data_ov025_021ef988.inner->field_220 = -1;
    }
    if (p->hasLimit) {
        data_ov025_021ef988.inner->field_222 = p->limit;
    } else {
        data_ov025_021ef988.inner->field_222 = -1;
    }
    return 1;
}
