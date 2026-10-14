#include <globaldefs.h>
#include "GameState/GameState.h"

int GetFieldIfFlag4_020100f8(char* obj);
void SetFlagsAt0x244_020a28a0(unsigned char* obj, unsigned char mask);
void BlankFunction020a289c(void);
typedef void (*BlankFn020a289c)(void*, int);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);

struct Field12Bits0219e234 {
	unsigned char nibble : 4;
	unsigned char mid : 3;
	unsigned char high : 1;
};

// USA: func_ov017_0219e234
ARM void UpdateFlagsFromField12_0219e234(int a0, int a1, int a2, void* obj) {
	GameState* battle = GameState::GetInstance();
	int f = GetFieldIfFlag4_020100f8((char*)battle);
	if (!f) return;
	struct Field12Bits0219e234* b = (struct Field12Bits0219e234*)((char*)obj + 0xc);
	if (b->nibble == 0 || b->high == 0) {
		SetFlagsAt0x244_020a28a0((unsigned char*)f, 0x10);
		((BlankFn020a289c)&BlankFunction020a289c)((void*)f, 2);
		return;
	}
	ClearFlagBits_020a28b0((unsigned char*)f, 0x10);
}
