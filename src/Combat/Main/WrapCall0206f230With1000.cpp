#include <globaldefs.h>

#if defined(jpn)
extern "C" void func_0206f230(int, int, int, int, void*, int);
#else
extern "C" void func_0206f230(int, int, int, int, void*, int, int, int);
#endif

// USA: func_0206f200
ARM void WrapCall0206f230With1000_0206f200(int a, int b, int c, int d, int e) {
#if defined(jpn)
    func_0206f230(a, b, c, d, &e, 1);
#else
    func_0206f230(a, b, c, d, &e, 1, 0, 0);
#endif
}
