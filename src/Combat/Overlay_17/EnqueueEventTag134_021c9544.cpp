#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021c9544
ARM void EnqueueEventTag134_021c9544(int a0, int a1, int a2, int a3) {
	void* p = GetData02100044_0202ae24();
	unsigned char buf[0x14];
	unsigned char* b = buf + 4;
	unsigned char byte3 = b[3];
	unsigned char a1b = (unsigned char)a1;
	signed char sb = (signed char)a3;
	byte3 = (byte3 & ~0xf) | (a1b & 0xf);
	b[3] = byte3;
	signed char byte3s = *(signed char*)&b[3];
	buf[0] = 0x86;
	byte3s = (byte3s & ~0xf0) | ((sb & 0xf) << 4);
	*(short*)b = (short)a0;
	b[3] = byte3s;
	func_0205e330(p, buf, 0);
}
