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

int GetGlobalField0x1c020421a0();
extern "C" void func_ov011_02184c68(void* obj, int val);

// USA: func_ov011_021874b0
ARM int SetFieldFromGlobal998_021874b0(void* obj) {
    int val = *(int*)((char*)(int)GetGlobalField0x1c020421a0() + R(0x868, 0x998));
    func_ov011_02184c68(obj, val);
    return 1;
}
