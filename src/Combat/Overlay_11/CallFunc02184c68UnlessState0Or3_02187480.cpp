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

void* GetGlobalField0x1c020421a0();
extern "C" unsigned int func_ov011_02184c68(unsigned int, unsigned int);

// USA: func_ov011_02187480  (semantic: CallFunc02184c68UnlessState0Or3_02187480)
extern "C" ARM int func_ov011_02187480(unsigned int obj) {
    int state = *(int*)((char*)GetGlobalField0x1c020421a0() + R(0x870, 0x9a0));
    int flag = 1;
    if (state == 0 || state == 3) flag = 0;
    func_ov011_02184c68(obj, flag);
    return 1;
}
