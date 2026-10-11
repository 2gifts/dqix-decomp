#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x7100
#define REGION_OFFSET_1 0xb2
#define REGION_OFFSET_2 0xaa
#else
#define REGION_OFFSET_0 0x6f00
#define REGION_OFFSET_1 0xc2
#define REGION_OFFSET_2 0xba
#endif


// USA: func_ov000_021634c8
ARM void AppendUniqueShort021634c8(char* obj, int val) {
    int i;
    for (i = 0; i < *(short*)(obj + REGION_OFFSET_0 + REGION_OFFSET_1); i++) {
        if (val == *(short*)(obj + i * 2 + REGION_OFFSET_0 + REGION_OFFSET_2)) break;
    }
    if (i != *(short*)(obj + REGION_OFFSET_0 + REGION_OFFSET_1)) return;
    {
        short* countPtr = (short*)(obj + REGION_OFFSET_0 + REGION_OFFSET_1);
        int freshCount = *countPtr;
        short* elemPtr = (short*)(obj + *(short*)(obj + REGION_OFFSET_0 + REGION_OFFSET_1) * 2 + REGION_OFFSET_0 + REGION_OFFSET_2);
        *countPtr = freshCount + 1;
        *elemPtr = (short)val;
    }
}
