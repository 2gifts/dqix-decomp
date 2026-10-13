#include <globaldefs.h>

struct CopyPayload {
#if defined(jpn)
    char data[0xb];
#else
    char data[0x30];
#endif
};

struct CopyableRecord {
    struct CopyPayload payload;
#if defined(jpn)
    unsigned char byte11;
#endif
    short f30;
    signed char f32;
    unsigned char f33;
};

// USA: func_02093b54
ARM void CopyRecord(struct CopyableRecord* dst, struct CopyableRecord* src) {
    dst->payload = src->payload;
#if defined(jpn)
    dst->byte11 = src->byte11;
#endif
    dst->f30 = src->f30;
    dst->f32 = src->f32;
    dst->f33 = src->f33;
}
