#include <globaldefs.h>

struct State02155f4c;
extern void* data_ov017_021d83ac;
#if defined(jpn)
#define func_ov002_02155f4c func_ov002_02157634
#define CallIfGlobalPtrSet_021a5954 func_ov017_021a638c
extern "C" void CallIfGlobalPtrSet_021a5954(void);
#endif
extern "C" void func_ov002_02155f4c(State02155f4c*);

// USA: func_ov017_021a5954
ARM void CallIfGlobalPtrSet_021a5954(void) {
    if (data_ov017_021d83ac == NULL) {
        return;
    }
    func_ov002_02155f4c((State02155f4c*)data_ov017_021d83ac);
}
