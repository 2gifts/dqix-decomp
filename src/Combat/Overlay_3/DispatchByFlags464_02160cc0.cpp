#include <globaldefs.h>
#if defined(jpn)
enum { kRegion464 = 0x28c };
#else
enum { kRegion464 = 0x464 };
#endif

extern "C" int func_ov003_02160cf8(void* obj);
extern "C" int func_ov003_02160e34(void* obj);

// JPN: func_ov003_02160e1c
// USA: func_ov003_02160cc0
ARM int DispatchByFlags464_02160cc0(char* obj) {
    int flags = *(int*)(obj + kRegion464);
    int result = 1;
    if (flags & 0x400) {
        result = func_ov003_02160cf8(obj);
    } else if (flags & 0x800) {
        result = func_ov003_02160e34(obj);
    }
    return result;
}
