#include <globaldefs.h>

#if defined(jpn)
#define func_ov017_021b213c func_ov017_021b2854
#define func_ov017_021b2090 func_ov017_021b27b0
#endif

struct PackedField017 {
    unsigned int low : 12;
    unsigned int f12 : 4;
    unsigned int f16 : 5;
    unsigned int f21 : 5;
    unsigned int top : 6;
};

extern "C" int func_ov017_021b2090(PackedField017 a, PackedField017 b);

// USA: func_ov017_021b213c  (semantic: SwapArgsAndForward_021b213c)
extern "C" ARM int func_ov017_021b213c(PackedField017 a, PackedField017 b) {
	return func_ov017_021b2090(b, a);
}
