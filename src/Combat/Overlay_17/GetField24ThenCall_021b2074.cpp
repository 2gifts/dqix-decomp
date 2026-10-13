#include <globaldefs.h>

extern "C" int func_ov031_02245710(void* p);

// USA: func_ov017_021b2074
ARM int GetField24ThenCall_021b2074(void* obj, void*) {
    void* p = *(void**)((char*)obj + 0x24);
    if (p == NULL) {
        return 0;
    }
    return func_ov031_02245710(p);
}
