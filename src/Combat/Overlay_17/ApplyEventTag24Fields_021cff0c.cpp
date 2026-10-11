#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
extern "C" void func_ov017_02191234(int a);
void ClearBit02026394(unsigned char* obj, unsigned int index);
GameObject* GetCombatantWithFlag0x1000(GameState* battleStruct, int combatantId);
int GetSignedByte0x2d0(void* obj);
void CallHelperWithBuf_021907dc(int a, int b, int c, int d, int e);

struct LocalEvt021cff0c {
	unsigned char pad0[4];
	unsigned char field4;
	unsigned char field5;
};

// JPN: func_ov017_021d03bc
// USA: func_ov017_021cff0c
ARM void ApplyEventTag24Fields_021cff0c(int unused0, LocalEvt021cff0c* evt, GameState* battleStruct, int table, struct SearchStruct0202c1a4* extra) {
#if defined(jpn)
 enum {regionalOffset0=0x4c0};
#else
 enum {regionalOffset0=0x6d0};
#endif
	signed char val = GetSearchStructCurrentArrEntry(extra);
	if (evt->field4 != val) {
		return;
	}
	func_ov017_02191234(table);
	unsigned char* obj = *(unsigned char**)((unsigned char*)table + 0x3000 + regionalOffset0);
	ClearBit02026394(obj, evt->field5);
	int v = evt->field5;
	GameObject* c = GetCombatantWithFlag0x1000(battleStruct, v);
	if (c != NULL) {
		v = GetSignedByte0x2d0(c);
	}
	CallHelperWithBuf_021907dc(table, v, 1, 1, 1);
}
