#include <globaldefs.h>

extern "C" char* func_ov017_0218b5b0(void);
extern "C" void func_ov028_021d8c20(int);
void PopStack1AndTrigger(int flag);

// USA: func_ov001_02161a60
ARM int ClearFieldAndPopStack_02161a60(void) {
#if defined(jpn)
    enum { queueOffset = 0x524, fieldOffset = 0x15c };
#else
    enum { queueOffset = 0x734, fieldOffset = 0x160 };
#endif
    char* p = *(char**)(func_ov017_0218b5b0() + 0x3000 + queueOffset);
    int v = *(int*)(p + fieldOffset);
    func_ov028_021d8c20(v);
    *(int*)(p + fieldOffset) = 0;
    PopStack1AndTrigger(1);
    return 1;
}
