#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x7034
#define REGION_OFFSET_1 0x7036
#define REGION_OFFSET_2 0x7038
#else
#define REGION_OFFSET_0 0x6e44
#define REGION_OFFSET_1 0x6e46
#define REGION_OFFSET_2 0x6e48
#endif


// USA: func_ov000_02163454
ARM void ZeroShortTriple0x6e44(void* obj) {
    *(unsigned short*)((char*)obj + REGION_OFFSET_0) = 0;
    *(unsigned short*)((char*)obj + REGION_OFFSET_1) = 0;
    *(unsigned short*)((char*)obj + REGION_OFFSET_2) = 0;
}
