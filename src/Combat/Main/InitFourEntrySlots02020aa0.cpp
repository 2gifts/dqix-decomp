#include <globaldefs.h>

extern "C" void func_020dc7e8(int a, int b);
extern "C" void func_020200c0(int index, void* obj);

// USA: func_02020aa0
ARM void InitFourEntrySlots02020aa0(void* obj) {
    char i;
    func_020dc7e8(6, -1);
    func_020dc7e8(7, -1);
    for (i = 0; i < 4; i++) {
        func_020200c0(i, (char*)obj + 0xe8);
    }
}
