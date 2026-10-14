#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);
int IsValidAndFlag0x1000Clear02088dd8(unsigned char* obj);
void SetByte0x7eSetFlag0x1000_02088e48(unsigned char* obj, unsigned char val);
void SetBool0x17fClear0x180_020488ac(unsigned char* obj, int value);
int GetField0x3acValue_020100a8(GameState* battleStruct);
int LoadBattleBlock020ac4c0(void* dst);
struct S_a056c;
void AddClamped16BitHighAt0x1c_020a056c(struct S_a056c* p, unsigned int amount);
int CopyInBattleField0x7540_020ac494(void* src);

struct Obj_021eb08c { char pad0[0x10]; struct Random* rng; };
struct Effect_021eb08c {
	char pad0[0x24];
	unsigned int kindA : 7;
	unsigned int chanceA : 7;
	unsigned int kindB : 7;
	unsigned int chanceB : 7;
	unsigned int : 4;
	unsigned char minTurns;
	unsigned char maxTurns;
};

static inline int IsValidSlot_021eb08c(int slot) {
	return slot >= 0 && slot <= 3;
}

// USA: func_ov024_021eb08c
extern "C" ARM int func_ov024_021eb08c(struct Obj_021eb08c* obj, int slot, int id, unsigned int kind) {
	struct Random* rng;
	GameObject* c = GetCombatantWithFlag0x400ByID_ov000_021536f8((int)obj->rng, id);
	if (!c) return 0;
	struct Effect_021eb08c* effect = *(struct Effect_021eb08c**)((char*)c + 0x148);
	if (!effect) return 0;
	if (!IsValidSlot_021eb08c(slot)) return 0;
	rng = obj->rng;
	unsigned int roll = NextRandomMax(rng, 100);
	if (!IsValidAndFlag0x1000Clear02088dd8((unsigned char*)c->currentStats_)) return 0;
	int turns = NextRandomBetween(rng, effect->minTurns, effect->maxTurns);
	int result = 0;
	if (kind == effect->kindA) {
		if (roll < effect->chanceA) {
			SetByte0x7eSetFlag0x1000_02088e48((unsigned char*)c->currentStats_, (unsigned char)turns);
			SetBool0x17fClear0x180_020488ac((unsigned char*)c, 1);
			result = 1;
			*(short*)((char*)c->currentStats_ + 0x2e) = slot;
		}
	} else if (kind == effect->kindB) {
		if (roll < effect->chanceB) {
			SetByte0x7eSetFlag0x1000_02088e48((unsigned char*)c->currentStats_, (unsigned char)turns);
			SetBool0x17fClear0x180_020488ac((unsigned char*)c, 1);
			result = 1;
			*(short*)((char*)c->currentStats_ + 0x2e) = slot;
		}
	}
	if (result && slot == GetField0x3acValue_020100a8(GameState::GetInstance())) {
		char block[0xb0];
		LoadBattleBlock020ac4c0(block);
		AddClamped16BitHighAt0x1c_020a056c((struct S_a056c*)block, 1);
		CopyInBattleField0x7540_020ac494(block);
	}
	return result;
}
