#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021d09cc {
	unsigned short v0;
	unsigned char v2;
	unsigned char pad3;
	unsigned int v4;
	unsigned int v8;
};

struct LocalEvt021d09cc {
	unsigned char tag;
	unsigned char pad0[3];
	Sub021d09cc sub;
	unsigned char pad2[4];
};

// USA: func_ov017_021d09cc
ARM void EnqueueEventTag139_021d09cc(int a, int b, int c, int d) {
	LocalEvt021d09cc buf;
	void* p = GetData02100044_0202ae24();
	Sub021d09cc* s = &buf.sub;
	buf.tag = 0x8b;
	s->v0 = (unsigned short)a;
	s->v2 = (unsigned char)b;
	s->v4 = c;
	s->v8 = d;
	func_0205e330(p, &buf, 0);
}
