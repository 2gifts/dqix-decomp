#include <globaldefs.h>

extern "C" int func_ov031_0220cf6c();
extern "C" int func_ov031_0220cdf4(int, int);

// USA: func_ov031_0220cdd4
ARM int DispatchOnZeroPair_0220cdd4(int a, int b, int) {
	if (a == 0 || b == 0) return func_ov031_0220cf6c();
	return func_ov031_0220cdf4(a, b);
}
