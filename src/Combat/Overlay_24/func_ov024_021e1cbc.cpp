#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Container02070e60;
struct Element_021e1cbc { char pad0[8]; void* field8; };
extern "C" Element_021e1cbc* _Z33SearchWithLow15Comparator02070fd0P17Container02070e60i(Container02070e60* container, int key);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct PackedPair_021e1cbc {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};
struct Range_021e1cbc { char pad[0x20]; PackedPair_021e1cbc f20; PackedPair_021e1cbc f24; };

struct Party_021e1cbc { unsigned short key; char pad[0x18 - 2]; };
struct BattleFlags_021e1cbc { unsigned char lo : 4; unsigned char count : 2; unsigned char hi : 2; };
struct Battle_021e1cbc {
    char pad0[0x81b1];
    BattleFlags_021e1cbc flags;
    char pad81b2[2];
    Party_021e1cbc parties[4];
    char pad[0x8e18 - 0x81b4 - 4 * 0x18];
    char* data;
};

struct Msg_021e1cbc { char pad[0x1a]; unsigned short field1a; unsigned short field1c; };
struct Flag_021e1cbc { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021e1cbc {
    char pad0[4];
    Msg_021e1cbc* msg;
    char pad8[4];
    void* field0xc;
    Battle_021e1cbc* battle;
    char pad2[0x6e - 0x14];
    unsigned char byte0x6e;
};

// JPN: func_ov024_021e2554
// USA: func_ov024_021e1cbc
extern "C" ARM void* func_ov024_021e1cbc(Obj_021e1cbc* obj, int unused, int id, Range_021e1cbc* range) {
	GameObject* c = GetCombatantByID((int)obj->battle, id);
	if (!c) return 0;
	int found = 0;
	char* data = obj->battle->data;
	for (int i = 0; i < obj->battle->flags.count; i++) {
		Element_021e1cbc* e = _Z33SearchWithLow15Comparator02070fd0P17Container02070e60i((Container02070e60*)(data + 0x684), obj->battle->parties[i].key);
		if (e && e->field8) found = 1;
	}
	if (!found) {
		obj->msg->field1c = 0x1f;
		obj->msg->field1a = 0x1f;
	} else {
		obj->msg->field1c = range->f24.a;
		obj->msg->field1a = range->f20.c;
	}
	obj->byte0x6e = 1;
	void* entry = func_ov000_0215e958(obj->battle);
	if (!entry) return 0;
	Flag_021e1cbc* fl = (Flag_021e1cbc*)((char*)obj->field0xc + 0x1c);
	func_ov000_0215cd44(obj->battle, entry, c, 0, 0, 0, fl->flag != 0);
	return entry;
}
