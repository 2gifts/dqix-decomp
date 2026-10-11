#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov024_021fd088(void* obj, float pct, int a2);
struct IndexedObj_021fe6b4;
void SetFieldFromIndexed_021fe6b4(struct IndexedObj_021fe6b4* obj, int val);

struct Field14Bits_021fd2b4 { unsigned int lo : 7; unsigned int val : 7; };
struct State64c_021fd2b4 { char pad[0x14]; struct Field14Bits_021fd2b4 bits; char pad2[0x1a]; short field32; };

struct Obj_021fd2b4 {
	char pad0[0x64c];
	struct State64c_021fd2b4* state64c;
	char pad2[0x668 - 0x64c - 4];
	GameObject* ptr668;
};

// USA: func_ov024_021fd2b4  (semantic: ApplyBuffScaledPercent17_021fd2b4)
extern "C" ARM void func_ov024_021fd2b4(struct Obj_021fd2b4* obj) {
	struct ModifiableCombatStats* stats = obj->ptr668->currentStats_;
	if (stats->attackBuff <= -2) return;
	short field32;
	unsigned char pctBase = *(unsigned char*)((char*)stats + 0x4f);
	if (pctBase == 0) return;
	struct State64c_021fd2b4* state = obj->state64c;
	field32 = state->field32;
	float valF = (float)state->bits.val;
	float scaled = valF * ((float)pctBase / 100.0f);
	if (scaled > 100.0f) scaled = 100.0f;
	if (field32 >= 0) return;
	SetFieldFromIndexed_021fe6b4((struct IndexedObj_021fe6b4*)obj, 0xd);
	func_ov024_021fd088(obj, scaled, 0x11);
}
