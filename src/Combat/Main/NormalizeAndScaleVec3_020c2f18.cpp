#include <globaldefs.h>

struct Vec3s32_020c2f18 { int x, y, z; };

struct HwMathRegs020c2f18 {
    volatile unsigned short divCnt;
    unsigned char pad0[0xe];
    unsigned int numerLo;
    unsigned int numerHi;
    unsigned int denomLo;
    unsigned int denomHi;
    unsigned char pad1[0x30 - 0x20];
    volatile unsigned short sqrtCnt;
    unsigned char pad2[0x38 - 0x32];
    unsigned int sqrtParamLo;
    unsigned int sqrtParamHi;
};

// USA: func_020c2f18  (semantic: NormalizeAndScaleVec3_020c2f18)
extern "C" ARM void Vector3fix_Normalize(struct Vec3s32_020c2f18* v, struct Vec3s32_020c2f18* out) {
    long long sq = (long long)v->x * v->x;
    int vy = v->y;
    sq += (long long)vy * vy;
    sq += (long long)v->z * v->z;

    struct HwMathRegs020c2f18* hw = (struct HwMathRegs020c2f18*)0x4000280;
    hw->divCnt = 2;
    hw->numerLo = 0;
    hw->numerHi = 0x1000000;
    hw->denomLo = (unsigned int)sq;
    hw->denomHi = (unsigned int)(sq >> 32);
    hw->sqrtCnt = 1;
    hw->sqrtParamLo = (unsigned int)sq << 2;
    hw->sqrtParamHi = (unsigned int)(((unsigned long long)sq << 2) >> 32);

    while (hw->sqrtCnt & 0x8000) {}
    int sqrtResult = *(volatile int*)0x40002b4;

    while (*(volatile unsigned short*)0x4000280 & 0x8000) {}
    long long divResult = *(volatile long long*)0x40002a0;

    long long scale = divResult * (long long)sqrtResult;
    out->x = (int)((scale * (long long)v->x + (1LL << 44)) >> 45);
    out->y = (int)((scale * (long long)v->y + (1LL << 44)) >> 45);
    out->z = (int)((scale * (long long)v->z + (1LL << 44)) >> 45);
}
