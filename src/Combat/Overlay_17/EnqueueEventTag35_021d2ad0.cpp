#include <globaldefs.h>

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021d2ad0
ARM void EnqueueEventTag35_021d2ad0(short a0, int a1, int a2, int a3, unsigned char a4) {
	void* d = GetData02100044();
	unsigned char buf[0x14];
	buf[0] = 0x23;
	unsigned char* b = buf + 4;
	b[0] = a0;
	*(int*)(b + 4) = a1;
	*(int*)(b + 8) = a2;
	*(int*)(b + 0xc) = a3;
	b[1] = a4;
	func_0205e330(d, buf, 0);
}
