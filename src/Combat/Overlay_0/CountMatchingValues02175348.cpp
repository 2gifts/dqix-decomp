#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0xf54
#else
#define REGION_OFFSET_0 0xd1c
#endif


struct DataLimit02175348 { int f0; int limit; };
extern struct DataLimit02175348 data_ov000_02184288;

// USA: func_ov000_02175348
ARM int CountMatchingValues02175348(void* objRaw, int val) {
    char* obj = (char*)objRaw;
    int limit = data_ov000_02184288.limit;
    int count = 0;
    for (int i = 0; i < limit; i++) {
        int v = *(int*)(obj + i * 4 + 0x1000 + REGION_OFFSET_0);
        if (val == v) {
            count++;
        }
    }
    return count;
}
