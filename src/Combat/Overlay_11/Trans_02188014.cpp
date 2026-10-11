#if defined(jpn)
#define R(j,u) (j)
#define _Z27ScaleStatsIfType12_021f6f10Pv _Z27CheckAnyBuffBelow2_021f5c80P16Wrapper_021f5c80iiPiPs
#define _Z40InitTenAllocatorsAndClearFields_021e4e8cPv func_ov023_021e5080
#define data_ov023_021ff5b4 data_ov023_021fe83c
#define func_ov023_021fc518 func_ov023_021fb810
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" unsigned int _Z26GetGlobalField0x1c020421a0v();
extern "C" unsigned int _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30();

// USA: func_ov011_02188014  (semantic: Trans_02188014)
extern "C" ARM unsigned int func_ov011_02188014(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r0 = (unsigned int)_Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30();
    r4 = r0;
    r0 = (unsigned int)_Z26GetGlobalField0x1c020421a0v();
    *(unsigned int*)((char*)r0 + R(0x86c, 0x99c)) = (unsigned int)r4;
    r0 = 0x1;
    return r0;
}
