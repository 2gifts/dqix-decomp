#include <globaldefs.h>

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
#define SetBuffer02028ddc func_0202862c
extern "C" ARM void func_0202862c(void* ptr);
#endif

// USA: func_02028ddc
ARM void SetBuffer02028ddc(void* ptr) {
    data_020fe9a4 = ptr;
}
