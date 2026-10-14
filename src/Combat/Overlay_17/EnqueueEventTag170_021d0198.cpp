#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021d0198 {
	unsigned char v0;
	unsigned char v1;
	unsigned char v2;
	unsigned char pad3;
	unsigned short v4;
};

struct LocalEvt021d0198 {
	unsigned char tag;
	unsigned char pad0[3];
	Sub021d0198 sub;
	unsigned char pad2[10];
};

// USA: func_ov017_021d0198
ARM void EnqueueEventTag170_021d0198(int a, int b, int c, int d) {
	LocalEvt021d0198 buf;
	void* p = GetData02100044_0202ae24();
	buf.tag = 0xaa;
	Sub021d0198* s = &buf.sub;
	s->v0 = (unsigned char)a;
	s->v1 = (unsigned char)b;
	s->v2 = (unsigned char)c;
	s->v4 = (unsigned short)d;
	func_0205e330(p, &buf, 0);
}
