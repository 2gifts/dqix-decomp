#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif

extern int data_ov025_021ef988;
extern "C" void func_ov025_021e3084(void* p);

// USA: func_ov025_021e6208
ARM int SetField_021e6208_021e6208(void* unused, int value) {
    char* p = *(char**)((char*)&data_ov025_021ef988 + kGlobalHolderInnerOffset);
    func_ov025_021e3084(p + 0x540);
    *(int*)(p + 0x540) = value;
    return 1;
}
