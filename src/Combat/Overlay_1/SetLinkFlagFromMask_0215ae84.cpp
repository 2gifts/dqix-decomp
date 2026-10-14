#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* obj);
extern "C" void func_ov017_021d6134(void* obj, unsigned int val);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);

extern unsigned short data_02114e30;

// USA: func_ov001_0215ae84
ARM int SetLinkFlagFromMask_0215ae84(void* obj) {
    int v = func_ov017_021d60f4(obj);
    unsigned short masked = (unsigned short)v;
    int result = TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, masked);
    func_ov017_021d6134((char*)obj + 8, result);
    return 1;
}
