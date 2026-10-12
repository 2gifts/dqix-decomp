#include <globaldefs.h>

extern char data_02107800;

#if defined(jpn)
#define GetField0x10IfArg8 func_02042e30
extern "C" ARM int func_02042e30(int);
#endif

// USA: func_020429bc
ARM int GetField0x10IfArg8(int x) {
    int r = 0;
#if defined(jpn)
    switch (x) {
    case 6: r = *(int*)(&data_02107800 + 0x14); break;
    case 8: r = *(int*)(&data_02107800 + 0x20); break;
    case 10: r = *(int*)(&data_02107800 + 0x24); break;
    case 12: r = *(int*)(&data_02107800 + 0x28); break;
    }
#else
    if (x == 8) r = *(int*)(&data_02107800 + 0x10);
#endif
    return r;
}
