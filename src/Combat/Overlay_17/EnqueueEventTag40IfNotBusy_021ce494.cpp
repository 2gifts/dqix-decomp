#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void* p);

struct LocalEvt021ce494 {
	unsigned char tag;
	unsigned char pad[0x13];
};

// USA: func_ov017_021ce494
ARM void EnqueueEventTag40IfNotBusy_021ce494(void) {
	void* x = func_0202ae18();
	if (func_0202c508(x) != 0) {
		return;
	}
	if (GameState::GetInstance()->GetPartyMemberByIndex(0xce) != NULL) {
		return;
	}
	LocalEvt021ce494 buf;
	void* p = GetData02100044_0202ae24();
	buf.tag = 0x28;
	func_0205e330(p, &buf, 0);
}
