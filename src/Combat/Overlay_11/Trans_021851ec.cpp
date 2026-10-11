#if defined(jpn)
#define R(j,u) (j)
#define func_ov024_021f6bc0 func_ov023_021f6bc0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" unsigned int func_ov011_021849c8();
extern "C" unsigned int func_ov011_02184c68(unsigned int, unsigned int);
extern "C" unsigned int func_ov017_021b2164();
extern "C" unsigned int func_ov024_021f6bc0();

// USA: func_ov011_021851ec  (semantic: Trans_021851ec)
extern "C" ARM unsigned int func_ov011_021851ec(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r0 = (unsigned int)func_ov017_021b2164();
    r0 = (unsigned int)func_ov011_021849c8();
    r0 = (unsigned int)func_ov024_021f6bc0();
    r1 = r0;
    r0 = r4;
    r0 = (unsigned int)func_ov011_02184c68(r0, r1);
    r0 = 0x1;
    return r0;
}
