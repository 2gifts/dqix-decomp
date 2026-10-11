#include <globaldefs.h>

extern void* data_ov017_021d83ac;
#if defined(jpn)
#define func_ov002_02155dbc func_ov002_021574fc
#endif
extern "C" void func_ov002_02155dbc(void*);

// JPN: func_ov017_021a636c
// USA: func_ov017_021a5934
ARM void CallIfGlobalPtrSet_021a5934(void) {
    if (data_ov017_021d83ac == NULL) {
        return;
    }
    func_ov002_02155dbc(data_ov017_021d83ac);
}
