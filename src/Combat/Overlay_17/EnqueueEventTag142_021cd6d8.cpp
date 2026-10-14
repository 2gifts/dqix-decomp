#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Src021cd6d8 {
	unsigned short f0;
	unsigned short f2;
	unsigned short f4;
	short f6;
	unsigned char f8;
	unsigned short fa;
	signed char fc;
	unsigned char pad;
	int f10;
};

// USA: func_ov017_021cd6d8
ARM void EnqueueEventTag142_021cd6d8(Src021cd6d8* src) {
	void* p = GetData02100044_0202ae24();
	unsigned char buf[0x14];
	buf[0] = 0x8e;
	unsigned char* b = buf + 4;
	*(unsigned short*)(b + 0) = src->f0;
	*(unsigned short*)(b + 2) = src->f2;
	*(unsigned short*)(b + 4) = src->f4;
	b[0xa] = src->f8;
	*(unsigned short*)(b + 6) = src->fa;
	*(short*)(b + 8) = src->f6;
	*(int*)(b + 0xc) = src->f10;
	*(signed char*)(b + 0xb) = src->fc;
	func_0205e330(p, buf, 0);
}
