#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct List021600f8;
struct ListNode021600f8;
extern "C" struct ListNode021600f8* _Z22GetNodeAtIndex021600f8P12List021600f8i(struct List021600f8* list, int index);
extern "C" void* _Z23FindNodeAtDepth0215fff4Pvii(void* obj, int limit, int idx);
extern "C" short _Z20ApplyHPDelta0215a16cPviiPs(void* unused, int id, int delta, short* outApplied);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(void* world, void* out, GameObject* combatant,
                            short valC, short valA, short valB, unsigned long long word, unsigned char byteE);
extern "C" void _Z32AppendToChainAndIncCount0215fe84PvS_i(void* obj, void* node, int idx);

struct Chain_021e5988 { char pad0[0x18]; unsigned char count; };
struct Depth_021e5988 { char pad0[0xc]; short value; };
struct Result_021e5988 { char pad0[0x22]; short hp; };
struct Id12_021e5988 { unsigned int id : 12; unsigned int rest : 20; };
struct Action_021e5988 { char pad0[4]; struct Id12_021e5988 f4; };
struct Stats_021e5988 { char pad0[2]; short field2; };
struct Obj_021e5988 {
	char pad0[4];
	struct List021600f8* field0x4;
	struct Result_021e5988* field0x8;
	struct Chain_021e5988* field0xc;
	void* field0x10;
};

static inline short GetStatField2_021e5988(GameObject* c) { short v = ((struct Stats_021e5988*)c->currentStats_)->field2; return v; }

// USA: func_ov024_021e5988
extern "C" ARM void func_ov024_021e5988(struct Obj_021e5988* obj, int id, struct Action_021e5988* action) {
	struct Chain_021e5988* chain;
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return;
	chain = obj->field0xc;
	if (action->f4.id == 0x91) {
		struct Chain_021e5988* first = (struct Chain_021e5988*)_Z22GetNodeAtIndex021600f8P12List021600f8i(obj->field0x4, 0);
		if (first) chain = first;
	}
	int sum = 0;
	int depth = 0;
	for (int i = 0; i < chain->count; i++) {
		struct Depth_021e5988* d = (struct Depth_021e5988*)_Z23FindNodeAtDepth0215fff4Pvii(chain, i, depth);
		if (d) sum += d->value;
	}
	sum >>= 2;
	if (sum <= 0) return;
	short applied = 0;
	short hp = _Z20ApplyHPDelta0215a16cPviiPs(obj->field0x10, id, sum, &applied);
	obj->field0x8->hp = hp;
	void* entry = func_ov000_0215e958(obj->field0x10);
	if (!entry) return;
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	func_ov000_02159eac(obj->field0x10, &local, 0x25);
	_Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, 0x215);
	_Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(obj->field0x10, entry, c, -sum, hp,
	                       GetStatField2_021e5988(c), local.v, 0);
	_Z32AppendToChainAndIncCount0215fe84PvS_i(obj->field0x8, entry, 2);
	((unsigned char*)obj->field0x10)[0x8e02]++;
}
