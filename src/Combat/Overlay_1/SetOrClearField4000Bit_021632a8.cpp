#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
extern "C" int func_ov017_021d60f4(void* obj);
void SetBitsInWord_0203b4a0(unsigned int* obj, unsigned int mask);
void ClearBitsInWord_0203b4b0(unsigned int* obj, unsigned int mask);

// USA: func_ov001_021632a8
ARM int SetOrClearField4000Bit_021632a8(void* obj) {
    unsigned int* p = (unsigned int*)func_ov017_0218b5b0();
    int cond = func_ov017_021d60f4(obj);
    if (cond != 0) {
        SetBitsInWord_0203b4a0(p, 0x4000);
    } else {
        ClearBitsInWord_0203b4b0(p, 0x4000);
    }
    return 1;
}
