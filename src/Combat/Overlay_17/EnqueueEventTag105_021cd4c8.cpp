#include <globaldefs.h>

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021cd4c8
ARM void EnqueueEventTag105_021cd4c8(unsigned short a0, unsigned short a1, signed char a2) {
	void* p = GetData02100044();
	unsigned char buf[0x14];
	buf[0] = 0x69;
	unsigned char* b = buf + 4;
	*(unsigned short*)(b + 0) = a0;
	*(unsigned short*)(b + 2) = a1;
	b[4] = a2;
	b[5] = 0;
	func_0205e330(p, buf, 0);
}
