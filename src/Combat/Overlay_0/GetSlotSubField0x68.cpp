#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x88
#else
#define REGION_OFFSET_0 0x68
#endif


extern "C" char* func_ov000_02161318(void* p, int id);

// USA: func_ov000_02174e1c
ARM char* GetSlotSubField0x68(void* obj, int id) {
    char* r = func_ov000_02161318(obj, id);
    return r ? r + REGION_OFFSET_0 : 0;
}
