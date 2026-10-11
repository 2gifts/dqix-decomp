#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x47c
#else
#define REGION_OFFSET_0 0x43c
#endif


struct Obj021754e0 { char pad[REGION_OFFSET_0]; unsigned char flags; };

extern "C" struct Obj021754e0* func_ov000_02161318(int, int);

// USA: func_ov000_021754e0
ARM void SetFlag0x2_021754e0(int a, int b) {
    struct Obj021754e0* p = func_ov000_02161318(a, b);
    if (p) {
        p->flags |= 0x2;
    }
}
