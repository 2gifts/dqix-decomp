#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct ItemData0217c32c {
    unsigned int pad0 : 7;
    unsigned int category : 4;
    unsigned int pad11 : 21;
};

struct EquipSlot0217c32c {
    struct ItemData0217c32c* item;
};

struct CombatData0217c32c {
    char pad0[0x2b4];
    struct EquipSlot0217c32c shield;
    char pad2b8[0x950 - 0x2b8];
    int field950;
};

struct Outer_02054000 {
    char pad0[0x150];
    struct CombatData0217c32c* data;
};
extern "C" struct EquipSlot0217c32c* _Z21GetActiveSub_02054000P14Outer_02054000(struct Outer_02054000* p);

struct Field150Holder02052e14;
short* GetField150Ptr0x488(struct Field150Holder02052e14* obj);
void* GetFieldAt0x150(unsigned char* obj);

struct Pair0209a338;
extern "C" void _Z26ClearFirstTwoWords0209a338P12Pair0209a338(struct Pair0209a338* p);
struct Ctx0209a348;
extern "C" void _Z33SetupAndRunBufferedScript0209a348P11Ctx0209a348Pv(struct Ctx0209a348* ctx, void* value);

struct FindEntry0209a614 {
    unsigned short kind : 11;
    unsigned short pad0 : 5;
    unsigned short id;
    unsigned int category : 5;
    unsigned int pad4 : 27;
    int field8;
};
struct FindList0209a614 {
    struct FindEntry0209a614* entries;
    int count;
};
extern "C" struct FindEntry0209a614* _Z21FindEntryById0209a614P16FindList0209a614i(struct FindList0209a614* list, int id);

struct Entry0217c32c {
    int name;
    unsigned int id : 12;
    unsigned int rest : 20;
};

struct Menu0217c32c {
    char pad0[0x4c];
    int combatantId;
    char pad50[0x88 - 0x50];
    unsigned char usable[0x13];
    char pad9b[0x1a4 - 0x9b];
    struct Entry0217c32c* items[0x93];
};

// USA: func_ov000_0217c32c
extern "C" ARM void func_ov000_0217c32c(struct Menu0217c32c* menu) {
    struct Outer_02054000* c = (struct Outer_02054000*)GetCombatantWithFlag0x100(GameState::GetInstance(), menu->combatantId);
    if (c == NULL) {
        return;
    }
    struct EquipSlot0217c32c* weapon = _Z21GetActiveSub_02054000P14Outer_02054000(c);
    struct EquipSlot0217c32c* shield = &c->data->shield;
    short* equipIds = GetField150Ptr0x488((struct Field150Holder02052e14*)c);
    if (equipIds != NULL) {
        if (equipIds[7] < 0) {
            weapon = NULL;
        }
        if (equipIds[8] < 0) {
            shield = NULL;
        }
    }
    if (GetFieldAt0x150((unsigned char*)c) == NULL) {
        return;
    }
    memset(menu->usable, 0, sizeof(menu->usable));
    struct FindList0209a614 list;
    struct FindEntry0209a614 entries[287];
    _Z26ClearFirstTwoWords0209a338P12Pair0209a338((struct Pair0209a338*)&list);
    _Z33SetupAndRunBufferedScript0209a348P11Ctx0209a348Pv((struct Ctx0209a348*)&list, entries);
    for (unsigned short i = 0; i < 0x93; i++) {
        struct Entry0217c32c* item = menu->items[i];
        if (item == NULL) {
            return;
        }
        struct FindEntry0209a614* found = _Z21FindEntryById0209a614P16FindList0209a614i(&list, item->id);
        if (found == NULL) {
            continue;
        }
        int usable;
        if (c->data->field950 == 0) {
            usable = 1;
        } else if (weapon != NULL) {
            usable = weapon->item->category == found->category;
        } else {
            usable = found->category == 0xe;
        }
        if (shield != NULL && shield->item->category == found->category) {
            usable = 1;
        }
        if (found->category > 0xe) {
            usable = 1;
        }
        if (found->kind == 0x11e) {
            usable = 1;
        }
        if (usable) {
            menu->usable[(unsigned char)(i >> 3)] |= 1 << (i & 7);
        }
    }
}
