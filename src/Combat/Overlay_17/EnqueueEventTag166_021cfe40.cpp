#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021cfe40 {
	unsigned short valA;
	unsigned short valC;
	unsigned short valB;
};

struct LocalEvt021cfe40 {
	unsigned char tag;
	unsigned char pad0[3];
	Sub021cfe40 sub;
	unsigned char pad2[10];
};

// USA: func_ov017_021cfe40
ARM void EnqueueEventTag166_021cfe40(unsigned short a, unsigned short b, unsigned short c) {
	LocalEvt021cfe40 buf;
	void* p = GetData02100044_0202ae24();
	Sub021cfe40* s = &buf.sub;
	buf.tag = 0xa6;
	s->valA = a;
	s->valB = b;
	s->valC = c;
	func_0205e330(p, &buf, 0);
}
