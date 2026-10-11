#include <globaldefs.h>

extern void* data_ov017_021d83ac;
#if defined(jpn)
#define func_ov002_0216bfd4 func_ov002_0216c628
#endif
extern "C" void func_ov002_0216bfd4(void* obj, int mode);

// USA: func_ov017_021a5a28
extern "C" ARM void _Z27CallIfGlobalPtrSet_021a5a28v(void* unused, int mode) {
    if (data_ov017_021d83ac == NULL) {
        return;
    }
    func_ov002_0216bfd4(data_ov017_021d83ac, mode);
}
