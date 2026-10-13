#include <globaldefs.h>

struct Src_0218fea0 {
    unsigned char kind;
    short value;
};

struct Dst_0218fea0 {
    int value;
    int kind;
};

// USA: func_ov016_0218fea0  (semantic: Trans_0218fea0)
extern "C" ARM Dst_0218fea0* func_ov016_0218fea0(Dst_0218fea0* dst, const Src_0218fea0* src) {
    dst->kind = src->kind;
    dst->value = src->value;
    return dst;
}
