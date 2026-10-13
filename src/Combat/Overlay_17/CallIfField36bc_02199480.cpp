#include <globaldefs.h>

#if defined(jpn)
enum { ACTIVE_FIELD_OFFSET = 0x34ac };
#else
enum { ACTIVE_FIELD_OFFSET = 0x36bc };
#endif

void BlankFunction020a87cc(void);

// USA: func_ov017_02199480
ARM void CallIfField36bc_02199480(void* obj) {
    if (*(int*)((char*)obj + ACTIVE_FIELD_OFFSET)) BlankFunction020a87cc();
}
