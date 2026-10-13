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
extern "C" ARM unsigned int func_ov011_021851ec(unsigned int arg0) {
    func_ov017_021b2164();
    func_ov011_021849c8();
    func_ov011_02184c68(arg0, func_ov024_021f6bc0());
    return 1;
}
