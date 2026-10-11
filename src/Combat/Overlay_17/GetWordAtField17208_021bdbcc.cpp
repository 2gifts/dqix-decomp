#include <globaldefs.h>
#if defined(jpn)
#define REGION_FIELD 0x4118
#else
#define REGION_FIELD 0x4338
#endif

// USA: func_ov017_021bdbcc  (semantic: GetWordAtField17208_021bdbcc)
extern "C" ARM int func_ov017_021bdbcc(void* obj) {
    return *(int*)((char*)obj + REGION_FIELD);
}
