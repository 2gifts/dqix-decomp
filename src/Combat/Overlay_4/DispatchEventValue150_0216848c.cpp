#if defined(jpn)
#define func_ov004_02167b78 func_ov004_02168074
#endif
#include <globaldefs.h>

extern "C" void func_ov004_02167b78(void* obj, int val);
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_0216848c  (semantic: DispatchEventValue150_0216848c)
extern "C" ARM int func_ov004_0216848c(void* a1) {
    func_ov004_02167b78(a1, 0);
    func_ov011_021848a0(a1, 0x96);
    return 0;
}
