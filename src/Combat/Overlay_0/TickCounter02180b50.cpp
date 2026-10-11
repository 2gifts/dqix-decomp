#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x84
#define REGION_OFFSET_1 0x85
#else
#define REGION_OFFSET_0 0x80
#define REGION_OFFSET_1 0x81
#endif


struct S02180b50 {
    char pad0[0x930];
    int f930;
    int f934;
    int f938;
    char pad1[0x94c - 0x93c];
    int f94c;
};

// USA: func_ov000_02180b50
ARM void TickCounter02180b50(struct S02180b50* obj) {
    if (obj->f934 == 0) {
        obj->f930 = 0x180;
        obj->f938 = 0;
        obj->f934 = 1;
        return;
    }
    if (obj->f934 != 1) return;
    int v = obj->f930 - obj->f94c * 3;
    obj->f930 = v;
    if (v <= REGION_OFFSET_0) {
        v = REGION_OFFSET_0;
        obj->f930 = v;
        obj->f934 = v - REGION_OFFSET_1;
    }
}
