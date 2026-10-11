#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define EnqueueEventType9_021590c4 _Z26EnqueueEventType9_021590c4Pv
extern "C" void* EnqueueEventType9_021590c4(void* ctx);
#else
void* EnqueueEventType9_021590c4(void* ctx);
#endif

struct Data24_0215d8b4 { char pad[0x24]; void* field24; };
extern Data24_0215d8b4 data_ov001_02165880;

// USA: func_ov001_0215d8b4  (semantic: EnqueueEventType9Wrapper_0215d8b4)
extern "C" ARM int func_ov001_0215d8b4(void) {
    EnqueueEventType9_021590c4(data_ov001_02165880.field24);
    return 1;
}
