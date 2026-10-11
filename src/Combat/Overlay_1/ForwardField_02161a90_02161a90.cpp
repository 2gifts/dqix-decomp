#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov001_02161a90
ARM int ForwardField_02161a90_02161a90(void* obj) {
#if defined(jpn)
    enum { queueOffset = 0x524, fieldOffset = 0x158 };
#else
    enum { queueOffset = 0x734, fieldOffset = 0x15c };
#endif
    int* p = *(int**)(func_ov017_0218b5b0() + 0x3000 + queueOffset);
    func_ov017_021d6134(obj, p[fieldOffset / 4]);
    return 1;
}
