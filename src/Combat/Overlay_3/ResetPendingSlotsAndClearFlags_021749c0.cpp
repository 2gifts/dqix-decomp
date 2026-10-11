#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021dca88 func_ov023_021dd398
#endif
extern "C" void func_ov023_021dca88(void* obj);

struct FlagWord020466f4;
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
void* GetDataPtr02114e04_020d6c00(void);

// USA: func_ov003_021749c0  (semantic: ResetPendingSlotsAndClearFlags_021749c0)
extern "C" ARM void func_ov003_021749c0(char* obj) {
	func_ov023_021dca88(obj + 0x3c);
#if defined(jpn)
    enum { pendingOffset = 0xfc2 };
#else
    enum { pendingOffset = 0x1046 };
#endif
	*(unsigned short*)(obj + pendingOffset) &= ~0x800;
	ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 1);
}
