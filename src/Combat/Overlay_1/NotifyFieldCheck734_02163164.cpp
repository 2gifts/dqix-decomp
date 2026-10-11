#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
extern "C" int func_ov017_021bbc04(int val);
extern "C" void func_ov017_021d6134(void* param, int val);

// USA: func_ov001_02163164
ARM int NotifyFieldCheck734_02163164(void* param) {
#if defined(jpn)
    enum { queueOffset = 0x524 };
#else
    enum { queueOffset = 0x734 };
#endif
    void* base = func_ov017_0218b5b0();
    int field = *(int*)((char*)base + 0x3000 + queueOffset);
    int cond = func_ov017_021bbc04(field);
    if (cond != 0) {
        func_ov017_021d6134(param, 1);
    } else {
        func_ov017_021d6134(param, 0);
    }
    return 1;
}
