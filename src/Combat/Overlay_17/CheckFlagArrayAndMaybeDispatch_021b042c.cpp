#include <globaldefs.h>

#if defined(jpn)
#define CheckFlagArrayAndMaybeDispatch_021b042c func_ov017_021b0ac4
#endif

extern "C" void func_ov017_021d0b30(int a, int b, int c);

// USA: func_ov017_021b042c
#if defined(jpn)
extern "C"
#endif
ARM int CheckFlagArrayAndMaybeDispatch_021b042c(unsigned char* obj) {
	int ok = 1;
	int i;
	for (i = 1; i < 4; i++) {
		if ((obj + i)[0x1b] == 1) {
			if (!(obj[0x20] & (1 << i))) {
				ok = 0;
				break;
			}
		}
	}
	if (!ok) return obj[0xa];
	func_ov017_021d0b30(3, 0, 0);
	return 5;
}
