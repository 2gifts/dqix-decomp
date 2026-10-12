#include <globaldefs.h>

#if defined(jpn)
struct GfxBufferHolder {
    char pad[4];
    void* buffer;
};
extern GfxBufferHolder data_020fe6fc;
#else
extern int data_020fe9a4;
#endif

#if defined(jpn)
#define SetField402028d58 func_020285a8
extern "C" ARM void func_020285a8(int value);
#endif

// USA: func_02028d58
ARM void SetField402028d58(int value) {
#if defined(jpn)
    *(int*)&data_020fe6fc = value;
#else
    (&data_020fe9a4)[1] = value;
#endif
}
