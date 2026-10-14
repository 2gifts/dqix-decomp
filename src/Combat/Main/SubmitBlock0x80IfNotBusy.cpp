#include <globaldefs.h>

extern "C" void func_020ca528(void* block, int arg);

// USA: func_020c552c
ARM int SubmitBlock0x80IfNotBusy_020c552c(int arg) {
    unsigned int* base = (unsigned int*)0x4000600;
    if (*base & 0x8000000) {
        return -1;
    }
    func_020ca528((unsigned char*)base + 0x80, arg);
    return 0;
}
