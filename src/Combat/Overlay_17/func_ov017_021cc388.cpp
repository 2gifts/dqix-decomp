// JPN: func_ov017_021cc830
#include <globaldefs.h>

#if defined(jpn)
enum { kRegionalFieldOffset = 0x4c0 };
#else
enum { kRegionalFieldOffset = 0x6d0 };
#endif
#include "GameState/GameState.h"

struct SearchStruct;

struct Group021cc388 {
	unsigned char pad0[4];
	signed char ownerId;
	unsigned char count;
	unsigned char ids[3];
	unsigned char kinds[3];
};

int GetField0x3acValue(GameState* battleStruct);
GameObject* GetCombatantWithFlag0x1000(GameState* battleStruct, int combatantId);
GameObject* GetCombatantWithFlag0x200(GameState* battleStruct, int combatantId);

extern "C" void func_ov017_02190264(unsigned char* ov, int combatantId);
extern "C" void func_ov017_021905b8(unsigned char* ov, int combatantId, int mode);
extern "C" void func_ov017_0218f064(unsigned char* ov, int combatantId, int flag, int c, int d);

extern "C" void _Z25EnqueueEventTag8_021cc4b8hhi(unsigned char combatantId, int tag, int value);
extern "C" ARM void _Z14SetBit020263b0Phj(unsigned char* bits, unsigned int index);

extern "C" void func_0202c288(struct SearchStruct* search);

// USA: func_ov017_021cc388  (semantic: EnqueueGroupEventsAndSetBits_021cc388)
extern "C" ARM void func_ov017_021cc388(int tag, Group021cc388* group, GameState* battleStruct,
                                        unsigned char* ov, struct SearchStruct* search) {
	if (group->ownerId >= 0) {
		if (group->ownerId != GetField0x3acValue(battleStruct)) return;
	}

	unsigned char* bits = *(unsigned char**)(ov + 0x3000 + kRegionalFieldOffset);
	unsigned char count = group->count;
	int lowValue = 0x3ff - 0x180;
	int flag, value;
	for (int i = 0; i < count; i++) {
		unsigned char idByte = group->ids[i];
		int id = idByte;
		int kind = group->kinds[i];
		if (GetCombatantWithFlag0x1000(battleStruct, id)) {
			func_ov017_02190264(ov, id);
		} else if (GetCombatantWithFlag0x200(battleStruct, id)) {
			func_ov017_021905b8(ov, id, 1);
		}
		if (kind == 0) {
			flag = 0x200;
			value = lowValue;
		} else if (kind == 1) {
			flag = 0x1000;
			value = 0x3ff;
		}
		func_ov017_0218f064(ov, id, flag, 0, 0);
		_Z25EnqueueEventTag8_021cc4b8hhi(idByte, tag, value);
		_Z14SetBit020263b0Phj(bits, id);
	}
	func_0202c288(search);
}
