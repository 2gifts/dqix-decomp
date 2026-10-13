#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(int a);
void DispatchWithGlobalContext020daf9c(int a, int b, int c, int d);

// KEEP-NAME
// USA: func_ov001_02162488
// JPN: func_ov001_02163a14
ARM int DispatchOv17ResultWrapper_02162488(int a) {
    DispatchWithGlobalContext020daf9c(func_ov017_021d60f4(a), 0, 1, 0);
    return 1;
}
