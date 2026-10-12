#include <globaldefs.h>

#if defined(jpn)
enum { kStateInBlock = 0xe2 };
#else
enum { kStateInBlock = 0xe6 };
#endif


#if defined(jpn)
#define func_ov023_021e4e3c func_ov023_021e5030
#define func_ov023_021e33b4 func_ov023_021e370c
#endif


#if defined(jpn)
#define func_ov023_021e3030 func_ov023_021e3388
#endif

extern "C" unsigned int func_ov023_021e4e3c(unsigned int obj);
extern "C" void func_ov023_021e33b4(void* obj);
extern "C" void func_ov023_021e3db0(void* obj);
extern "C" void func_ov023_021e3f34(void* obj);

// USA: func_ov023_021e3030  (semantic: DispatchByStateField_021e3030)
extern "C" ARM void func_ov023_021e3030(void* obj) {
    func_ov023_021e4e3c((unsigned int)obj);
    signed char state = *(signed char*)((char*)obj + 0x400 + kStateInBlock);
    if (state == 0) goto case0;
    if (state == 1) goto case1;
    if (state == 3) goto case3;
    return;
case0:
    func_ov023_021e33b4(obj);
    return;
case3:
    func_ov023_021e3db0(obj);
    return;
case1:
    func_ov023_021e3f34(obj);
    return;
}
