#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
void ClearBitsInField4_0203b4e8(unsigned int* obj, unsigned int mask);
void SetBitsInField4_0203b4d8(unsigned int* obj, unsigned int mask);

// USA: func_ov025_021e8314
ARM int SetOrClearBit1024_021e8314(unsigned char* param) {
    void* obj = func_ov017_0218b5b0();
    if (param[8]) {
        ClearBitsInField4_0203b4e8((unsigned int*)obj, 0x400);
    } else {
        SetBitsInField4_0203b4d8((unsigned int*)obj, 0x400);
    }
    return 1;
}
