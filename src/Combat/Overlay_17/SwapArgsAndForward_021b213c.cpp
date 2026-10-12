#include <globaldefs.h>

#if defined(jpn)
#define func_ov017_021b213c func_ov017_021b2854
#define func_ov017_021b2090 func_ov017_021b27b0
#endif

extern "C" int func_ov017_021b2090(int a, int b);

// USA: func_ov017_021b213c  (semantic: SwapArgsAndForward_021b213c)
extern "C" ARM int func_ov017_021b213c(int a, int b) {
	return func_ov017_021b2090(*(int*)((int)&b + 0), *(int*)((int)&a + 0));
}
