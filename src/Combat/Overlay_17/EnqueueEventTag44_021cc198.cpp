#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021cc198 {
	unsigned char field4;
	unsigned char pad1[3];
	int field8;
};

struct LocalEvt021cc198 {
	unsigned char tag;
	unsigned char pad0[3];
	Sub021cc198 sub;
	unsigned char pad2[8];
};

// USA: func_ov017_021cc198
ARM void EnqueueEventTag44_021cc198(unsigned char a, int b) {
	LocalEvt021cc198 buf;
	GameState::GetInstance();
	void* p = GetData02100044_0202ae24();
	Sub021cc198* s = &buf.sub;
	buf.tag = 0x2c;
	s->field4 = a;
	s->field8 = b;
	func_0205e330(p, &buf, 0);
}
