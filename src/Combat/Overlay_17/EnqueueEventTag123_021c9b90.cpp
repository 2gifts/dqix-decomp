#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021c9b90  (semantic: EnqueueEventTag123_021c9b90)
extern "C" ARM void func_ov017_021c9b90(unsigned short a0, unsigned short a1) {
	void* p = GetData02100044_0202ae24();
	unsigned char buf[0x14];
	buf[0] = 0x7b;
	*(unsigned short*)(buf + 4) = a0;
	*(unsigned short*)(buf + 6) = a1;
	func_0205e330(p, buf, 0);
}
