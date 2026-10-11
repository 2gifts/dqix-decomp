#include <globaldefs.h>
#include "std_library_functions.h"

struct S_10088;
int GetFieldAt0x150(unsigned char* obj);
void* GetData02108e10(void);
int TestBitAt0x34(unsigned char* obj, unsigned int index);
int IsFlag10088Set(struct S_10088* obj);
struct AddEntryList_021f6a1c;
extern "C" void _Z31AddEntryIfUnderLimit16_021f6a1cP21AddEntryList_021f6a1cPv(struct AddEntryList_021f6a1c* obj, void* src);
extern "C" void func_ov024_021f9874(void* obj, void* buf, int slot, int value);

struct Stats_021fc068 {
	unsigned short hp;
	char pad2[0x14 - 0x2];
	unsigned int flags14;
};

struct Combatant_021fc068 {
	char pad0[4];
	short id;
	char pad6[0x138 - 0x6];
	struct Stats_021fc068* stats;
};

struct Combatant_021fc068* GetCombatantByID(int unused, int id);

struct Action_021fc068 {
	char pad0[4];
	unsigned int code : 12;
	unsigned int rest4 : 20;
	unsigned int low8 : 8;
	unsigned int mode : 2;
	unsigned int high8 : 22;
	char padc[0x10 - 0xc];
	unsigned int flags10;
	unsigned int low14 : 28;
	unsigned int targetType : 4;
};

struct Battle_021fc068 {
	char pad[0x8e18];
	unsigned char* partyWork;
};

struct Obj_021fc068 {
	struct Battle_021fc068* battle;
	short id;
	char pad6[2];
	struct Combatant_021fc068* self;
	char padc[0x128 - 0xc];
	int targetId;
	char pad12c[0x64c - 0x12c];
	struct Action_021fc068* action;
};

struct Entry_021fc068 {
	float value;
	unsigned char field4;
	unsigned char field5;
	unsigned char slot;
	unsigned char rate;
	unsigned char kind;
	char pad9[3];
};

struct WorkBuffer_021fc068 {
	char entries[0xc4];
	float threshold;
};

// JPN: func_ov024_021fc834
// USA: func_ov024_021fc068
extern "C" ARM void func_ov024_021fc068(struct Obj_021fc068* obj) {
	struct Combatant_021fc068* self = obj->self;
	GetFieldAt0x150((unsigned char*)self);
	GetData02108e10();
	struct Action_021fc068* action = obj->action;
	if (action->mode == 1) return;
	GetCombatantByID((int)obj->battle, (short)obj->targetId);
	float rate = 50.0f;
	if (action->code == 0x27) {
		rate = 100.0f;
	} else if (action->code == 0x26 || action->code == 0x54) {
		rate = 50.0f;
	}
	struct WorkBuffer_021fc068 buf;
	memset(&buf, 0, sizeof(buf));
	memset(&buf, 0, sizeof(buf));
	for (int i = 0; i < 4; i++) {
		if (!TestBitAt0x34(obj->battle->partyWork, (unsigned char)i)) continue;
		if (action->targetType == 1 && i != obj->id) continue;
		struct Combatant_021fc068* c = GetCombatantByID((int)obj->battle, (short)i);
		if (!c) continue;
		if (!IsFlag10088Set((struct S_10088*)c)) continue;
		if ((action->flags10 & 0x400) && (c->stats->flags14 & 0x200)) continue;
		struct Entry_021fc068 entry;
		entry.value = (float)(c->stats->hp / 2);
		entry.field5 = 0;
		entry.slot = i;
		entry.rate = (int)rate;
		entry.kind = 5;
		_Z31AddEntryIfUnderLimit16_021f6a1cP21AddEntryList_021f6a1cPv((struct AddEntryList_021f6a1c*)&buf, &entry);
		if (action->targetType == 2 || action->targetType == 1) {
			func_ov024_021f9874(obj, &buf, 0, (unsigned char)c->id);
			memset(&buf, 0, sizeof(buf));
		}
	}
	if (action->targetType == 4 || action->targetType == 3) {
		GetCombatantByID((int)obj->battle, 0);
		int value = (unsigned char)self->id;
		if (action->targetType == 3) value = 0xff;
		func_ov024_021f9874(obj, &buf, 0, value);
	}
}
