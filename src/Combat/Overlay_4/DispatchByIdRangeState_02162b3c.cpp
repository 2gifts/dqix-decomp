#include <globaldefs.h>

extern "C" void* func_02012fe4(void);
int IsIdInRange020981e4(int a, int id);
extern "C" void func_ov011_021848a0(void* p, int v);

// USA: func_ov004_02162b3c  (semantic: DispatchByIdRangeState_02162b3c)
#pragma opt_propagation off
extern "C" ARM int func_ov004_02162b3c(void* self) {
#if defined(jpn)
    enum { fieldOffset = 0x860 };
#else
    enum { fieldOffset = 0x840 };
#endif
    char* base = (char*)func_02012fe4();
    if (base + fieldOffset != 0) {
        unsigned short id = *(unsigned short*)base;
        if (IsIdInRange020981e4((int)(base + fieldOffset), id) != 0) {
            func_ov011_021848a0(self, 0x32);
        } else {
            func_ov011_021848a0(self, 0x33);
        }
    }
    return 0;
}
