#include <globaldefs.h>

int FreeVRAMStagingMemory(void const*);

// USA: func_020e2478
ARM int InvokeSubHandlerIfPresent(int* obj) {
    int p = obj[0];
    if (p == 0) return p;
    return FreeVRAMStagingMemory((void const*)p);
}
