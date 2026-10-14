#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021cfde0 {
	unsigned short valA;
	unsigned short valB;
	unsigned short valC;
};

struct LocalEvt021cfde0 {
	unsigned char tag;
	unsigned char pad0[3];
	Sub021cfde0 sub;
	unsigned char pad2[10];
};

// USA: func_ov017_021cfde0
ARM void EnqueueEventTag165_021cfde0(unsigned short a, unsigned short b, unsigned short c) {
	LocalEvt021cfde0 buf;
	void* p = GetData02100044_0202ae24();
	Sub021cfde0* s = &buf.sub;
	buf.tag = 0xa5;
	s->valA = a;
	s->valB = b;
	s->valC = c;
	func_0205e330(p, &buf, 0);
}
