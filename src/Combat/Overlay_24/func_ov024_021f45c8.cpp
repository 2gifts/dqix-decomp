#include <globaldefs.h>
#include "GameState/GameState.h"

struct Out0215fb54 { int ids[2]; };

GameObject* GetCombatantWithFlag0x400ByID(int unused, int id);
void* GetActiveCombatWork(void);
extern "C" int _Z23FindRecordByKey0215fb54isP11Out0215fb54(int unused, short key, struct Out0215fb54* out);
extern "C" void* _Z26FindNodeByShortKey02162d88Pvs(void* obj, int key);

struct Group_021f45c8 {
	unsigned char pad0;
	unsigned char flags : 4;
	unsigned char groupCount : 2;
	unsigned char pad1 : 2;
	char pad2[2];
	unsigned short key;
	char pad6[8];
	unsigned char memberCount : 4;
	unsigned char weight : 4;
	char padf[0x18 - 0xf];
};
struct Obj_021f45c8 { int field0; };
struct Header_021f45c8 { unsigned char pad0; unsigned char flags : 4; unsigned char groupCount : 2; unsigned char pad1 : 2; };
struct Action_021f45c8 {
	char pad0[4];
	unsigned int key : 12;
	unsigned int rest4 : 20;
	char pad8[0x18 - 8];
	unsigned int lo18 : 5;
	unsigned int kind : 7;
	unsigned int hi18 : 20;
};
extern struct Out0215fb54 data_ov024_021fea1c[];

// USA: func_ov024_021f45c8
extern "C" ARM int func_ov024_021f45c8(struct Obj_021f45c8* obj, int id, struct Action_021f45c8* action, int* outCount, short* outId) {
	GameObject* c;
	void* work;
	int count;
	int i;
	c = GetCombatantWithFlag0x400ByID(obj->field0, id);
	if (!c) return 0;
	work = GetActiveCombatWork();
	if (!work) return 0;
	struct Group_021f45c8* groups = (struct Group_021f45c8*)((char*)obj->field0 + 0x81b0);
	if (!groups) return 0;
	if (action->kind == 0xc) {
		struct Out0215fb54 rec;
		rec.ids[1] = data_ov024_021fea1c[63].ids[1];
		rec.ids[0] = data_ov024_021fea1c[63].ids[0];
		count = _Z23FindRecordByKey0215fb54isP11Out0215fb54(obj->field0, action->key, &rec);
		for (i = 0; i < count; i++) {
			if (!_Z26FindNodeByShortKey02162d88Pvs(work, rec.ids[i])) return 0;
			if (((struct Header_021f45c8*)groups)->groupCount >= 3) {
				int found = 0;
				int j;
				for (j = 0; j < groups->groupCount; j++) {
					if (groups[j].key == rec.ids[i]) {
						found = 1;
						break;
					}
				}
				if (!found) {
					for (j = 0; j < groups->groupCount; j++) {
						if (groups[j].weight == 0) {
							found = 1;
							break;
						}
					}
					if (!found) return 0;
				}
			}
		}
	}
	int limit = 5;
	if (c->obj3D_.unknown_2_ == 0x10a) limit = 8;
	if (limit <= groups->flags) return 0;
	*outCount = 1;
	*outId = id;
	return 1;
}
