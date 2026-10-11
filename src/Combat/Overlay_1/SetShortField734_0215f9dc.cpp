#include <globaldefs.h>

extern "C" char* func_ov017_0218b5b0(void);
extern "C" int func_ov017_021d60f4(int a);
extern "C" void func_ov017_021bbbec(void* p, unsigned short v);

// USA: func_ov001_0215f9dc
ARM int SetShortField734_0215f9dc(int id) {
#if defined(jpn)
    enum { fieldOffset = 0x524 };
#else
    enum { fieldOffset = 0x734 };
#endif
	void* p = *(void**)(func_ov017_0218b5b0() + 0x3000 + fieldOffset);
	func_ov017_021bbbec(p, (unsigned short)func_ov017_021d60f4(id));
	return 1;
}
