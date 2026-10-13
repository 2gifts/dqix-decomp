#include <globaldefs.h>

extern int data_ov025_021ef988;
extern "C" unsigned int func_ov025_021e2f54(unsigned int, unsigned int, unsigned int);
extern "C" unsigned int func_ov025_021e3084(unsigned int);

// USA: func_ov025_021e3048  (semantic: Trans_021e3048)
extern "C" ARM unsigned int func_ov025_021e3048(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3) {
    unsigned int work = *(unsigned int*)((char*)&data_ov025_021ef988 + 0xc);
    func_ov025_021e3084(work + 0x540);
    *(unsigned int*)(work + 0x540) = arg1;
    func_ov025_021e2f54(work + 0x540, arg1, arg3);
    return 1;
}
