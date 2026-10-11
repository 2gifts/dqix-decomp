#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x6e8
#else
#define REGION_OFFSET_0 0x4f4
#endif


struct SubObj02162c90 { char pad[REGION_OFFSET_0]; int val; };

// USA: func_ov000_02162c90
ARM void SetBoundedArrayField0x4f4(char* base, int index, int value) {
    int valid = (index >= 0 && index <= 3);
    if (valid) {
        ((struct SubObj02162c90*)(base + index * 4 + 0x5000))->val = value;
    }
}
