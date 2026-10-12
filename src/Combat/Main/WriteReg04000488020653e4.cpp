#include <globaldefs.h>

#if defined(jpn)
#define func_020653e4 func_020666c0
extern "C" ARM void func_020666c0(int a, int b);
#endif

// USA: func_020653e4  (semantic: WriteReg04000488020653e4)
extern "C" ARM void func_020653e4(int a, int b) {
    *(volatile unsigned int*)0x4000488 =
        (unsigned short)(short)(a >> 8) | ((unsigned short)(short)(b >> 8) << 16);
}
