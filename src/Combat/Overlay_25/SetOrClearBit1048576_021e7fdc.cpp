#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
void ClearBitsInField4_0203b4e8(unsigned int* obj, unsigned int mask);
void SetBitsInField4_0203b4d8(unsigned int* obj, unsigned int mask);

// USA: func_ov025_021e7fdc
ARM int SetOrClearBit1048576_021e7fdc(unsigned char* param) {
    unsigned char flag = param[8];
    void* obj = func_ov017_0218b5b0();
    if (flag) {
        ClearBitsInField4_0203b4e8((unsigned int*)obj, 0x100000);
    } else {
        SetBitsInField4_0203b4d8((unsigned int*)obj, 0x100000);
    }
    return 1;
}
