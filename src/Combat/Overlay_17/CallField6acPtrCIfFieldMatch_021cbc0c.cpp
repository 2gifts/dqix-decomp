#include <globaldefs.h>

#if defined(jpn)
enum { kResourceWorkOffset = 0x508 };
#else
enum { kResourceWorkOffset = 0x718 };
#endif


#if defined(jpn)
#define CallField6acPtrC_021b86e0 func_ov017_021b8bf0
#endif


#if defined(jpn)
#define CallField6acPtrCIfFieldMatch_021cbc0c func_ov017_021cc0bc
#endif

extern "C" void* func_ov017_021b8478(void* obj);
#if defined(jpn)
extern "C"
#endif
void CallField6acPtrC_021b86e0(void* obj);

struct Src021cbc0c { unsigned char pad[4]; unsigned short field4; };
struct Ret021cbc0c { unsigned char pad[8]; unsigned short field8; };

// USA: func_ov017_021cbc0c
#if defined(jpn)
extern "C"
#endif
ARM void CallField6acPtrCIfFieldMatch_021cbc0c(int unused0, Src021cbc0c* src, int unused2, unsigned char* obj) {
    obj += 0x3000;
    void* work = *(void**)(obj + kResourceWorkOffset);
    Ret021cbc0c* r = (Ret021cbc0c*)func_ov017_021b8478(work);
    if (!r) return;
    if (r->field8 != src->field4) return;
    CallField6acPtrC_021b86e0(work);
}
