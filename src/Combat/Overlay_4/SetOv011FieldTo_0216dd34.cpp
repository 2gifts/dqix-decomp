#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_0216dd34  (semantic: SetOv011FieldTo_0216dd34)
extern "C" ARM int func_ov004_0216dd34(void* obj) {
    func_ov011_021848a0(obj, 0x193);
    return 0;
}
