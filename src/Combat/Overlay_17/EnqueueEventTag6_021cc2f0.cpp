#include <globaldefs.h>

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021cc2f0
ARM void EnqueueEventTag6_021cc2f0(int a0) {
	void* p = GetData02100044();
	unsigned char buf[0x14];
	buf[0] = 0x6;
	buf[4] = a0;
	func_0205e330(p, buf, 0);
}
