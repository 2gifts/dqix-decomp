#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021d257c { unsigned char valA; unsigned char pad[3]; int valB; };
struct LocalEvt021d257c { unsigned char tag; unsigned char pad0[3]; Sub021d257c sub; unsigned char pad2[8]; };

// USA: func_ov017_021d257c
ARM void EnqueueEventTag31_021d257c(unsigned char a, int b) {
	LocalEvt021d257c buf;
	void* p = GetData02100044_0202ae24();
	buf.tag = 0x1f;
	Sub021d257c* s = &buf.sub;
	s->valA = a;
	s->valB = b;
	func_0205e330(p, &buf, 0);
}
