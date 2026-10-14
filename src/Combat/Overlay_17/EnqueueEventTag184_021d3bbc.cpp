#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021d3bbc {
	unsigned char v0;
	unsigned char v1;
	unsigned char v2;
	unsigned char v3;
};

struct LocalEvt021d3bbc {
	unsigned char tag;
	unsigned char pad0[3];
	Sub021d3bbc sub;
	unsigned char pad2[12];
};

// USA: func_ov017_021d3bbc
ARM void EnqueueEventTag184_021d3bbc(int a, int b, int c, int d) {
	LocalEvt021d3bbc buf;
	void* p = GetData02100044_0202ae24();
	Sub021d3bbc* s = &buf.sub;
	buf.tag = 0xb8;
	s->v0 = (unsigned char)c;
	s->v1 = (unsigned char)d;
	s->v3 = (unsigned char)a;
	s->v2 = (unsigned char)b;
	func_0205e330(p, &buf, 0);
}
