#include <globaldefs.h>

#if defined(jpn)
enum { kSaveFieldOffset = 0x444 };
#else
enum { kSaveFieldOffset = 0x424 };
#endif


#if defined(jpn)
#define func_ov017_021b2ad8 func_ov017_021b31e8
#endif

extern "C" ARM void* func_02012fe4(void);
extern "C" ARM int func_ov017_0218b5b0(void);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);

struct Obj021b2ad8 {
	unsigned char pad0[8];
	int f8;
	unsigned char pad1[0x38 - 0xc];
	int f38;
};

// USA: func_ov017_021b2ad8  (semantic: CheckField424OrClearBits_021b2ad8)
extern "C" ARM int func_ov017_021b2ad8(Obj021b2ad8* p) {
	if (*(int*)((char*)func_02012fe4() + kSaveFieldOffset) != 0) {
		return p->f8;
	}
	int h = func_ov017_0218b5b0();
	ClearBitsInField4((unsigned int*)h, 2);
	p->f38 &= ~1;
	return 3;
}
