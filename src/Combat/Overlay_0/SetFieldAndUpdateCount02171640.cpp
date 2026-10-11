#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0xdc
#define REGION_OFFSET_1 0xc2
#else
#define REGION_OFFSET_0 0x9c
#define REGION_OFFSET_1 0x82
#endif


struct S02171698 { char pad[REGION_OFFSET_0]; int field[0x42]; };
signed char CountNonZero02171698(struct S02171698* s);

// USA: func_ov000_02171640
ARM void SetFieldAndUpdateCount02171640(struct S02171698* obj, int idx, int val) {
    if (idx < 0) return;
    if (idx >= 0x42) return;
    if (val == 0) return;
    obj->field[idx] = val;
    *(short*)((char*)obj + REGION_OFFSET_1) = CountNonZero02171698(obj);
}
