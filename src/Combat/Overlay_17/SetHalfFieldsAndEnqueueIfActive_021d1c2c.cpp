#include <globaldefs.h>

extern "C" void func_0202ae18(void);
extern "C" int func_0202c508(void);
extern "C" void* func_02012fe4(void);
void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021d1c2c
ARM void SetHalfFieldsAndEnqueueIfActive_021d1c2c(unsigned short a0, unsigned short a1) {
	func_0202ae18();
	if (!func_0202c508()) return;
	unsigned char* base = (unsigned char*)func_02012fe4();
	#if defined(jpn)
	base += 0x2740;
#else
	base += 0x2700;
#endif
	*(unsigned short*)(base + 0xb4) = a0;
	*(unsigned short*)(base + 0xb6) = a1;
	void* d = GetData02100044();
	unsigned char buf[0x14];
	buf[0] = 0xb3;
	buf[4] = (unsigned char)a0;
	buf[5] = (unsigned char)a1;
	func_0205e330(d, buf, 0);
}
