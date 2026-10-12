#include <globaldefs.h>

#if defined(jpn)
enum { ACTIVE_FIELD_OFFSET = 0x34ac };
#else
enum { ACTIVE_FIELD_OFFSET = 0x36bc };
#endif


#if defined(jpn)
#define CallIfField36bc_02199480 func_ov017_0219a030
#endif

void BlankFunction020a87cc(void);

// USA: func_ov017_02199480
#if defined(jpn)
extern "C"
#endif
ARM void CallIfField36bc_02199480(void* obj) {
    if (*(int*)((char*)obj + ACTIVE_FIELD_OFFSET)) BlankFunction020a87cc();
}
