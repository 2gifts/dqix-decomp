#include <globaldefs.h>

#if defined(jpn)
enum { FLAG_A_OFFSET = 0xfe, FLAG_PTR_OFFSET = 0x16c, FLAG_B_OFFSET = 0xd0 };
#else
enum { FLAG_A_OFFSET = 0x31e, FLAG_PTR_OFFSET = 0x41c, FLAG_B_OFFSET = 0x2f0 };
#endif


#if defined(jpn)
#define CheckThreeFlags_02195550 func_ov017_02196118
#endif

// USA: func_ov017_02195550
#if defined(jpn)
extern "C"
#endif
ARM int CheckThreeFlags_02195550(unsigned char* obj) {
	obj += 0x4000;
	if (obj[FLAG_A_OFFSET]) {
		return 1;
	}
	unsigned char* p = *(unsigned char**)(obj + FLAG_PTR_OFFSET);
	if (*p) {
		return 1;
	}
	return obj[FLAG_B_OFFSET] != 0;
}
