#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021cea34
ARM void EnqueueEventTag49_021cea34(int a0) {
	void* p = GetData02100044_0202ae24();
	unsigned char buf[0x14];
	buf[0] = 0x31;
	*(int*)(buf + 4) = a0;
	func_0205e330(p, buf, 0);
}
