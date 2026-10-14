#include <globaldefs.h>

extern "C" void func_020ca568(void* block, int arg);

// USA: func_020c54fc
ARM int SubmitBlock0x40IfNotBusy_020c54fc(int arg) {
    unsigned int* base = (unsigned int*)0x4000600;
    if (*base & 0x8000000) {
        return -1;
    }
    func_020ca568((unsigned char*)base + 0x40, arg);
    return 0;
}
