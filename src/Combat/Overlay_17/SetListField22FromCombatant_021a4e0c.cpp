#include <globaldefs.h>

#if defined(jpn)
enum { LIST_FIELD_OFFSET = 0x50c };
#else
enum { LIST_FIELD_OFFSET = 0x71c };
#endif


#if defined(jpn)
#define SetListField22FromCombatant_021a4e0c func_ov017_021a5880
#endif
#include "GameState/GameState.h"

extern "C" void func_ov017_021c12fc(char* obj, unsigned char a, unsigned char b);

// USA: func_ov017_021a4e0c
#if defined(jpn)
extern "C"
#endif
ARM void SetListField22FromCombatant_021a4e0c(char* obj) {
	GameObject* c = GameState::GetInstance()->GetUnknownGameObject();
	if (c == NULL) {
		return;
	}
	short val = *(short*)((char*)c + 4);
	int* list = *(int**)(obj + 0x3000 + LIST_FIELD_OFFSET);
	*(short*)((char*)list + 0x22) = val;
	func_ov017_021c12fc(obj, 1, 1);
}
