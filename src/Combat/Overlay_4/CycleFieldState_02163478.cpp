#include <globaldefs.h>

#if defined(jpn)
#define func_ov004_02163478 func_ov004_02163a6c
enum { kCurrentState = 0x9fa, kPreviousState = 0x9fb };
#else
enum { kCurrentState = 0x8fa, kPreviousState = 0x8fb };
#endif



// USA: func_ov004_02163478  (semantic: CycleFieldState_02163478)
extern "C" ARM void func_ov004_02163478(unsigned char* obj) {
    obj += 0x1000;
    obj[kPreviousState] = obj[kCurrentState];
    unsigned char v = obj[kCurrentState];
    if (v == 0) { obj[kCurrentState] = 1; return; }
    if (v == 1) { obj[kCurrentState] = 2; return; }
    if (v == 2) { obj[kCurrentState] = 0; return; }
}
