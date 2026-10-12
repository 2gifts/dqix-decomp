#include <globaldefs.h>

#if defined(jpn)
#define SetFlagFromField0NonZero_021ea920 func_ov023_021ea884
#endif

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void*);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021ea920
#if defined(jpn)
extern "C"
#endif
ARM int SetFlagFromField0NonZero_021ea920(void* obj) {
    void* p = func_0202ae18();
    if (func_0202c540(p) != 0) {
        func_ov017_021d6134(obj, 1);
    } else {
        func_ov017_021d6134(obj, 0);
    }
    return 1;
}
