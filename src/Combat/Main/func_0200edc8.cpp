#include <globaldefs.h>

extern "C" void (*ARM9_CTOR_START[])(void);

// USA: func_0200edc8
extern "C" ARM void func_0200edc8(void) {
    void (**p)(void) = ARM9_CTOR_START;
    while (p != 0 && *p != 0) {
        (*p)();
        p++;
    }
}
