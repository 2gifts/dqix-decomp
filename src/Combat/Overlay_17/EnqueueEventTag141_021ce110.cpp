#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021ce110
ARM void EnqueueEventTag141_021ce110(int a0, unsigned short a1, unsigned short a2, unsigned char a3) {
	void* p = GetData02100044_0202ae24();
	unsigned char buf[0x14];
	unsigned char combined = (buf[4] & ~0x7f) | (a0 & 0x7f);
	combined = (combined & ~0x80) | ((a3 & 1) << 7);
	buf[0] = 0x8d;
	*(unsigned short*)(buf + 6) = a1;
	*(unsigned short*)(buf + 8) = a2;
	buf[4] = combined;
	func_0205e330(p, buf, 0);
}
