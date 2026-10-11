#include <globaldefs.h>

#if defined(jpn)
extern "C" void func_020e5abc(void* a);
#define func_020e3f1c func_020e5abc
#else
extern "C" void func_020e3f1c(void* a);
#endif

// USA: func_ov004_0216fa3c  (semantic: TailCallFunc020e3f1c_0216fa3c)
extern "C" ARM void func_ov004_0216fa3c(void* a) {
    func_020e3f1c(a);
}
