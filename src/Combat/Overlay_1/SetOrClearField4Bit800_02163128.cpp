#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
extern "C" int func_ov017_021d60f4(void* obj);
void ClearBitsInField4_0203b4e8(unsigned int* obj, unsigned int mask);
void SetBitsInField4_0203b4d8(unsigned int* obj, unsigned int mask);

// USA: func_ov001_02163128
ARM int SetOrClearField4Bit800_02163128(void* obj) {
    unsigned int* p = (unsigned int*)func_ov017_0218b5b0();
    int cond = func_ov017_021d60f4(obj);
    if (cond != 0) {
        ClearBitsInField4_0203b4e8(p, 0x800);
    } else {
        SetBitsInField4_0203b4d8(p, 0x800);
    }
    return 1;
}
