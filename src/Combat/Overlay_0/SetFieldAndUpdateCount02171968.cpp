#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x1e4
#define REGION_OFFSET_1 0xc4
#else
#define REGION_OFFSET_0 0x1a4
#define REGION_OFFSET_1 0x84
#endif


struct S021719c0 { char pad[REGION_OFFSET_0]; int field[0x93]; };
short CountNonZero021719c0(struct S021719c0* s);

// USA: func_ov000_02171968
ARM void SetFieldAndUpdateCount02171968(struct S021719c0* obj, int idx, int val) {
    if (idx < 0) return;
    if (idx >= 0x93) return;
    if (val == 0) return;
    obj->field[idx] = val;
    *(short*)((char*)obj + REGION_OFFSET_1) = CountNonZero021719c0(obj);
}
