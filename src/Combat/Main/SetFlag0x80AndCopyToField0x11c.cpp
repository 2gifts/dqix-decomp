#include <globaldefs.h>

struct FourHalfwords02033f7c {
    unsigned short f0;
    unsigned short f2;
    unsigned short f4;
    unsigned short f6;
};

void CopyFourHalfwords(struct FourHalfwords02033f7c* dst, struct FourHalfwords02033f7c* src);

// USA: func_02033fa8
ARM void SetFlag0x80AndCopyToField0x11c_02033fa8(void* obj, struct FourHalfwords02033f7c* src) {
    *((unsigned char*)obj + 0xe0) |= 0x80;
    CopyFourHalfwords((struct FourHalfwords02033f7c*)((char*)obj + 0x11c), src);
}
