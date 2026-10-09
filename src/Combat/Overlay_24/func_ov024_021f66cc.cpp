#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400(GameState* gameState, int combatantId);
void* GetData02108e10(void);
int GetCombatantField0x148Bits3To4(int unused, int id);

struct MoveData_021f66cc {
	char pad0[0xc];
	unsigned short handlerA;
	unsigned short handlerB;
};

extern "C" struct MoveData_021f66cc* _Z24SearchBothTables02079e2cPci(char* table, int key);

class AIHandler_021f66cc {
public:
	int battle;
};

typedef int (AIHandler_021f66cc::*Handler_021f66cc)(unsigned char id, struct MoveData_021f66cc* move, int a3, int a4);

extern Handler_021f66cc data_ov024_021ff790[];

// USA: func_ov024_021f66cc
extern "C" ARM int func_ov024_021f66cc(AIHandler_021f66cc* obj, int battle, int moveId, int id, int a4, int a5) {
	obj->battle = battle;
	GetCombatantWithFlag0x400(GameState::GetInstance(), id);
	struct MoveData_021f66cc* move = _Z24SearchBothTables02079e2cPci((char*)GetData02108e10(), (short)moveId);
	int handler = 0;
	int kind = GetCombatantField0x148Bits3To4(obj->battle, (short)id);
	switch (kind) {
	case 1:
		handler = move->handlerA;
		break;
	case 2:
		handler = move->handlerB;
		break;
	}
	if (handler >= 0xa1) {
		return (obj->*data_ov024_021ff790[0])(id, move, a4, a5);
	}
	if (data_ov024_021ff790[handler] == 0) {
		return (obj->*data_ov024_021ff790[0])(id, move, a4, a5);
	}
	return (obj->*data_ov024_021ff790[handler])(id, move, a4, a5);
}
