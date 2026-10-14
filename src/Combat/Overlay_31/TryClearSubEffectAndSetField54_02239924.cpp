#include <globaldefs.h>

int ForwardClearBattleSubEffectAt0x800020d68d0(void* p);
void SetField54IfTagNot9Or10_ov031_022393e4(int v);

struct Struct02239924 { unsigned char pad[4]; char* inner; };
extern struct Struct02239924 data_ov031_02290d18;

// USA: func_ov031_02239924
ARM int TryClearSubEffectAndSetField54_02239924(void) {
	void* p = data_ov031_02290d18.inner + 0x1e00;
	int r = ForwardClearBattleSubEffectAt0x800020d68d0(p);
	if (r == 2) {
		return 1;
	}
	SetField54IfTagNot9Or10_ov031_022393e4(r);
	return 0;
}
