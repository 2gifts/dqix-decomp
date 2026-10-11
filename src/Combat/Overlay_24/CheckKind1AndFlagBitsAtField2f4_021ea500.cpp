#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj4Bits_021ea500 { char pad[0x4]; unsigned int kind : 12; };
struct Bits2f4_021ea500 { unsigned int bit0 : 1; unsigned int bit1 : 1; };

// JPN: func_ov024_021eaccc
// USA: func_ov024_021ea500  (semantic: CheckKind1AndFlagBitsAtField2f4_021ea500)
extern "C" ARM int func_ov024_021ea500(void* unused, struct Obj4Bits_021ea500* obj, int id) {
#if defined(jpn)
 enum {regionalOffset0=0x144};
#else
 enum {regionalOffset0=0x150};
#endif
	GameState* bs = GameState::GetInstance();
	if (obj->kind == 1) {
		int inRange = (id >= 0 && id <= 3);
		if (inRange) {
			GameObject* combatant = GetCombatantWithFlag0x100(bs, id);
			char* p = (char*)(*(int**)((char*)combatant + regionalOffset0)) + 0x2f4;
			if (p) {
				struct Bits2f4_021ea500* flags = (struct Bits2f4_021ea500*)p;
				if (flags->bit1 || flags->bit0) {
					return 1;
				}
			}
		}
	}
	return 0;
}
