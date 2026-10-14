#include <globaldefs.h>
#include "Util/Random.h"

struct Struct02082d38;
void CopyStruct02082d38(struct Struct02082d38* dst, struct Struct02082d38* src);

extern "C" void func_020891cc(void* dst, void* src, int useExactValue);

struct Packed3c_89630 {
    unsigned int fieldA : 10;
    unsigned int fieldB : 10;
    unsigned int fieldC : 10;
    unsigned int fieldD : 2;
};

// USA: func_02089630
extern "C" ARM void func_02089630(char* dst, char* src, int useExactValue) {
    func_020891cc(dst, src, useExactValue);
    struct Random* rng = GetBTRandom();

    if (useExactValue != 0) {
        unsigned short exact = *(unsigned short*)(src + 0x30);
        *(unsigned short*)(dst + 0x4) = exact;
        *(unsigned short*)(dst + 0x0) = exact;
    } else {
        unsigned int base = *(unsigned short*)(src + 0x30);
        *(unsigned short*)(dst + 0x4) = (unsigned short)(unsigned int)(0.5f +
            (float)base * NextRandomFloatBetween(rng, 0.8f, 1.0f));
        *(unsigned short*)(dst + 0x0) = *(unsigned short*)(dst + 0x4);
    }
    unsigned short second = *(unsigned short*)(src + 0x32);
    *(unsigned short*)(dst + 0x6) = second;
    *(unsigned short*)(dst + 0x2) = second;
    *(unsigned short*)(dst + 0xc) = *(unsigned short*)(src + 0x38);
    *(unsigned short*)(dst + 0x8) = *(unsigned short*)(src + 0x34);
    *(unsigned short*)(dst + 0xa) = *(unsigned short*)(src + 0x36);
    ((Packed3c_89630*)(dst + 0x10))->fieldA = (unsigned short)((Packed3c_89630*)(src + 0x3c))->fieldA;
    ((Packed3c_89630*)(dst + 0x10))->fieldB = (unsigned short)((Packed3c_89630*)(src + 0x3c))->fieldB;
    ((Packed3c_89630*)(dst + 0x10))->fieldC = (unsigned short)((Packed3c_89630*)(src + 0x3c))->fieldC;
    CopyStruct02082d38((struct Struct02082d38*)(dst + 0x3e), (struct Struct02082d38*)(src + 0x40));
}
