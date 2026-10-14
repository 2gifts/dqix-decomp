#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021ea8e8  (semantic: SetFieldFromCheckField0NonZero_021ea8e8)
extern "C" ARM int func_ov023_021ea8e8(void* obj) {
    if (CheckField0NonZero_0202b7d8((int*)func_0202ae18()) != 0) {
        func_ov017_021d6134(obj, 1);
    } else {
        func_ov017_021d6134(obj, 0);
    }
    return 1;
}
