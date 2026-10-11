#include <globaldefs.h>
#if defined(jpn)
enum { kRegion730 = 0x62c };
enum { kRegionb48 = 0x928 };
#else
enum { kRegion730 = 0x730 };
enum { kRegionb48 = 0xb48 };
#endif

extern "C" void* func_ov017_0218b5b0(void);
void* ResetOverlayAndAllocator_0219bf74(void);
extern "C" void func_ov017_021b1d44(void* p, int a, int b);

// JPN: func_ov003_02170f68
// USA: func_ov003_02171cac
ARM void SetupFlag_02171cac_02171cac(unsigned char* obj) {
	unsigned char result;
	if (!(obj[kRegion730] & 2)) {
		result = 0;
	} else {
		unsigned char* p = (unsigned char*)func_ov017_0218b5b0() + 0x3000;
		void* five = *(void**)(p + kRegionb48);
		void* four = ResetOverlayAndAllocator_0219bf74();
		func_ov017_021b1d44(five, 0x20, 1);
		*(void**)((unsigned char*)five + 8) = four;
		result = 9;
	}
	obj[0] = result;
}
