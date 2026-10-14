#include <globaldefs.h>

extern "C" void func_ov000_0216d370(void*, int, int, int);
void SetFlag0x1At0x168_0202ecec(unsigned char* obj);

// USA: func_ov000_0216d530
ARM void SetFlagOrState0216d530(void* obj, int val) {
    if (val < 0) {
        func_ov000_0216d370(obj, 1, 1, 1);
    } else {
        SetFlag0x1At0x168_0202ecec((unsigned char*)obj);
    }
    *(int*)((char*)obj + 0x224) = val;
}
