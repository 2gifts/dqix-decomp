#include <globaldefs.h>

extern "C" int func_ov000_02169a58(void* obj);

// USA: func_02048ab4
ARM int GetField0Result02169a58_02048ab4(void* obj, int) {
    void* p = *(void**)((char*)obj + 0x13c);
    if (p == NULL) return 0;
    void* q = *(void**)p;
    if (q == NULL) return 0;
    return func_ov000_02169a58(q);
}
