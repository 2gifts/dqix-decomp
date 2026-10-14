#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021cdd70
ARM void EnqueueEventTag107_021cdd70(unsigned short a0, unsigned short a1, unsigned short a2, unsigned short a3, unsigned short a4, unsigned short a5, unsigned char a6) {
	void* p = GetData02100044_0202ae24();
	unsigned char buf[0x14];
	buf[0] = 0x6b;
	unsigned char* b = buf + 4;
	*(unsigned short*)(b + 0) = a0;
	*(unsigned short*)(b + 2) = a1;
	*(unsigned short*)(b + 4) = a2;
	*(unsigned short*)(b + 6) = a3;
	*(unsigned short*)(b + 0xa) = a4;
	*(unsigned short*)(b + 8) = a5;
	b[0xc] = a6;
	func_0205e330(p, buf, 0);
}
