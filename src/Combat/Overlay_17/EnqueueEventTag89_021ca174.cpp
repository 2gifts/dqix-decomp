#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021ca174
ARM void EnqueueEventTag89_021ca174(unsigned short a0) {
	void* p = GetData02100044_0202ae24();
	unsigned char buf[0x14];
	buf[0] = 0x59;
	*(unsigned short*)(buf + 4) = a0;
	func_0205e330(p, buf, 0);
}
