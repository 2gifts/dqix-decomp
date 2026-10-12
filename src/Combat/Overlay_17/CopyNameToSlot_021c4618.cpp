#include <globaldefs.h>

#if defined(jpn)
#define CopyNameToSlot_021c4618 func_ov017_021c4adc
#endif
#include "GameState/GameState.h"
#include "std_library_functions.h"

GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int combatantId);
void FormatAndCopyName02052958(char* obj, char* name, int shouldFormatSecond);

#if defined(jpn)
extern char data_020ef078;
#endif

// USA: func_ov017_021c4618
#if defined(jpn)
extern "C"
#endif
ARM void CopyNameToSlot_021c4618(int unused0, char* obj, GameState* bs, char* base) {
	unsigned char idx = obj[4];
	GameObject* combatant = GetCombatantWithFlag0x100(bs, idx);
	if (combatant == NULL) {
		return;
	}
#if defined(jpn)
	sprintf(*(char**)((char*)combatant + 0x134), &data_020ef078, obj + 5);
	char* dst = base + 0x413c + idx * 0xc;
	strcpy(dst, obj + 5);
#else
	FormatAndCopyName02052958((char*)combatant, obj + 5, 1);
	char* dst = base + 0x435c + idx * 0x30;
	strcpy(dst, *(char**)((char*)combatant + 0x134));
#endif
}
