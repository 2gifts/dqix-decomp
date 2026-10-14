#include <globaldefs.h>

extern "C" void func_ov023_021f6ed8(void*, int, int, int);

// USA: func_ov023_021fba80
ARM int SetFieldsAndInit_021fba80(void* a, int b, int c, int d) {
    func_ov023_021f6ed8(a, b, c, d);
    *(short*)((char*)a + 0x4) = 0xe;
    *(short*)((char*)a + 0x6) = c;
    *(short*)((char*)a + 0x8) = d;
    return 1;
}
