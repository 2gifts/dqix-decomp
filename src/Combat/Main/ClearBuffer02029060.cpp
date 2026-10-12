#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
struct GfxBufferHolder {
    char pad[4];
    void* buffer;
};
extern GfxBufferHolder data_020fe6fc;
#define data_020fe9a4 data_020fe6fc.buffer
#else
extern void* data_020fe9a4;
#endif

#if defined(jpn)
#define ClearBuffer02029060 func_020288b0
extern "C" ARM void func_020288b0();
#endif

// USA: func_02029060
ARM void ClearBuffer02029060() {
    if (data_020fe9a4 == NULL) return;
    memset(data_020fe9a4, 0, 0x6000);
}
