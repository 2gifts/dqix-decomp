#include <globaldefs.h>

// USA: func_ov000_0217f5dc  (semantic: GetByteField_0217f5dc)
extern "C" ARM unsigned char func_ov000_0217f5dc(void* obj) {
#if defined(jpn)
    return *(unsigned char*)((char*)obj + 0x485);
#else
    return *(unsigned char*)((char*)obj + 0x445);
#endif
}
