#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

// USA: func_ov009_021855dc
#if defined(jpn)
extern "C" ARM void func_ov009_021867bc(
#else
ARM void SetStatValue021855dc(
#endif
unsigned char *self, int val) {
	signed char v = (signed char)val;
	*(signed char*)(self + LOW_REGION(0xc1c, 0xc58)) = v;
	*(signed char*)(self + LOW_REGION(0xc1d, 0xc59)) = 0;
	int idx = self[LOW_REGION(0xd67, 0xda3)];
	signed char *arr = (signed char*)(self + LOW_REGION(0xd64, 0xda0));
	if (arr[idx] < val) {
		arr[idx] = v;
	}
	*(unsigned int*)(self + LOW_REGION(0xd60, 0xd9c)) |= 0x1100;
	if (val != 9 && val != 0xb && val != 0xc) {
		unsigned char *sub = self + LOW_REGION(0x160, 0x19c);
		*(unsigned int*)(sub + 0xc00) |= 0x80;
	}
}
