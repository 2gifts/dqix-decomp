#include <globaldefs.h>
#if defined(jpn)
#define REGION_FIELD 0x20
#else
#define REGION_FIELD 0x24
#endif

// USA: func_ov023_021fad18  (semantic: GetFieldPtr24_021fad18)
extern "C" ARM void* func_ov023_021fad18(void* obj) {
    return (char*)obj + REGION_FIELD;
}
