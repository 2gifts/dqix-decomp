#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);
int GetSignedByte0x2d0(void* obj);
int GetSignedByte0x2d1(void* obj);
int GetSignedByte0x1c8(void* obj);
int GetSignedByte0x1c9(void* obj);
GameObject* GetCombatantWithFlag0x1000(GameState* battleStruct, int combatantId);

struct LocalEvt021ce32c {
	unsigned char tag;
	unsigned char pad0[3];
	unsigned short field4;
	unsigned char field6;
	unsigned char field7;
	unsigned char field8;
	unsigned char field9;
	unsigned char fielda;
	unsigned char pad1[9];
};

// JPN: func_ov017_021ce7d4
// USA: func_ov017_021ce32c
ARM void EnqueueEventTag38_021ce32c(int id) {
#if defined(jpn)
 enum {regionalOffset0=0x2c6};
#else
 enum {regionalOffset0=0x2d2};
#endif
	void* p = GetData02100044();
	GameObject* c = GetCombatantWithFlag0x1000(GameState::GetInstance(), id);
	if (c == NULL) {
		return;
	}
	LocalEvt021ce32c buf;
	buf.tag = 0x26;
	buf.field4 = id;
	buf.field6 = GetSignedByte0x2d0(c);
	buf.field7 = GetSignedByte0x2d1(c);
	buf.field8 = GetSignedByte0x1c8(c);
	buf.field9 = GetSignedByte0x1c9(c);
	buf.fielda = *(unsigned char*)((char*)c + regionalOffset0);
	func_0205e330(p, &buf, 0);
}
