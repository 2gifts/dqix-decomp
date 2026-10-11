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

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(TaggedNumber02184c30*);
int GetGlobalField0x1c020421a0();

// USA: func_ov011_02188158  (semantic: SetGlobalFlagByte9caFromTagged_02188158)
extern "C" ARM int func_ov011_02188158(TaggedNumber02184c30* a) {
    int v = GetTaggedValueAsInt_02184c30(a);
    unsigned char* g = (unsigned char*)GetGlobalField0x1c020421a0();
    *(unsigned char*)(g + 0x1000 + R(0x7fb, 0x9ca)) = (v != 0) ? 1 : 0;
    return 1;
}
