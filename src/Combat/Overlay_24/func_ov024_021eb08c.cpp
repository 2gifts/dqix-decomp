#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

GameObject* GetCombatantWithFlag0x400ByID(int unused, int id);
extern "C" int _Z33IsValidAndFlag0x1000Clear02088dd8Ph(unsigned char* obj);
void SetByte0x7eSetFlag0x1000(unsigned char* obj, unsigned char val);
void SetBool0x17fClear0x180(unsigned char* obj, int value);
int GetField0x3acValue(GameState* battleStruct);
extern "C" int _Z23LoadBattleBlock020ac4c0Pv(void* dst);
struct S_a056c;
void AddClamped16BitHighAt0x1c(struct S_a056c* p, unsigned int amount);
int CopyInBattleField0x7540(void* src);

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
	GameObject* c = GetCombatantWithFlag0x400ByID((int)obj->rng, id);
	if (!c) return 0;
	struct Effect_021eb08c* effect = *(struct Effect_021eb08c**)((char*)c + 0x148);
	if (!effect) return 0;
	if (!IsValidSlot_021eb08c(slot)) return 0;
	rng = obj->rng;
	unsigned int roll = NextRandomMax(rng, 100);
	if (!_Z33IsValidAndFlag0x1000Clear02088dd8Ph((unsigned char*)c->currentStats_)) return 0;
	int turns = NextRandomBetween(rng, effect->minTurns, effect->maxTurns);
	int result = 0;
	if (kind == effect->kindA) {
		if (roll < effect->chanceA) {
			SetByte0x7eSetFlag0x1000((unsigned char*)c->currentStats_, (unsigned char)turns);
			SetBool0x17fClear0x180((unsigned char*)c, 1);
			result = 1;
			*(short*)((char*)c->currentStats_ + 0x2e) = slot;
		}
	} else if (kind == effect->kindB) {
		if (roll < effect->chanceB) {
			SetByte0x7eSetFlag0x1000((unsigned char*)c->currentStats_, (unsigned char)turns);
			SetBool0x17fClear0x180((unsigned char*)c, 1);
			result = 1;
			*(short*)((char*)c->currentStats_ + 0x2e) = slot;
		}
	}
	if (result && slot == GetField0x3acValue(GameState::GetInstance())) {
		char block[0xb0];
		_Z23LoadBattleBlock020ac4c0Pv(block);
		AddClamped16BitHighAt0x1c((struct S_a056c*)block, 1);
		CopyInBattleField0x7540(block);
	}
	return result;
}
