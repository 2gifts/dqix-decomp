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
#if defined(jpn)
    char pad2b8[0x8b8 - 0x2b8];
#else
    char pad2b8[0x950 - 0x2b8];
#endif
    int field950;
};

struct Outer_02054000 {
#if defined(jpn)
    char pad0[0x144];
#else
    char pad0[0x150];
#endif
    struct CombatData0217c32c* data;
};
struct EquipSlot0217c32c* GetActiveSub_02054000(struct Outer_02054000* p);

struct Field150Holder02052e14;
short* GetField150Ptr0x488(struct Field150Holder02052e14* obj);
void* GetFieldAt0x150(unsigned char* obj);

struct Pair0209a338;
void ClearFirstTwoWords0209a338(struct Pair0209a338* p);
struct Ctx0209a348;
void SetupAndRunBufferedScript0209a348(struct Ctx0209a348* ctx, void* value);

struct FindEntry0209a614 {
#if defined(jpn)
    unsigned short kind : 12;
    unsigned short pad0 : 4;
#else
    unsigned short kind : 11;
    unsigned short pad0 : 5;
#endif
    unsigned short id;
    unsigned int category : 5;
    unsigned int pad4 : 27;
    int field8;
};
struct FindList0209a614 {
    struct FindEntry0209a614* entries;
    int count;
};
struct FindEntry0209a614* FindEntryById0209a614(struct FindList0209a614* list, int id);

struct Entry0217c32c {
    int name;
    unsigned int id : 12;
    unsigned int rest : 20;
};

struct Menu0217c32c {
    char pad0[0x4c];
    int combatantId;
#if defined(jpn)
    char pad50[0xc8 - 0x50];
#else
    char pad50[0x88 - 0x50];
#endif
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
    struct EquipSlot0217c32c* weapon = GetActiveSub_02054000(c);
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
    ClearFirstTwoWords0209a338((struct Pair0209a338*)&list);
    SetupAndRunBufferedScript0209a348((struct Ctx0209a348*)&list, entries);
    for (unsigned short i = 0; i < 0x93; i++) {
        struct Entry0217c32c* item = menu->items[i];
        if (item == NULL) {
            return;
        }
        struct FindEntry0209a614* found = FindEntryById0209a614(&list, item->id);
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
