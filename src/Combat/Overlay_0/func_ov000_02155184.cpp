#include <globaldefs.h>
#include "std_library_functions.h"

class GameState { public: static GameState* GetInstance(); };
struct Unit02155184;
Unit02155184* GetCombatantWithFlag0x400(GameState*, int);
struct Container02070e60;
struct BinarySearchByComparatorStruct;
void* SearchWithLow15Comparator02070fd0(Container02070e60*, int);
void* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct*, int);

struct Unit02155184 {
    char p0[2]; unsigned short key; char p1[0x138-4];
    unsigned char* details; char p2[8]; unsigned short* optional;
    char p3[0x17c-0x148]; unsigned char action, processed, flags;
    char p4[5]; unsigned char alternate; char p5;
    unsigned short alternateKey; char p6[4]; unsigned char alternateAction;
};
struct Entry02155184 {
    unsigned short action:3, count:11, flagA:1, flagB:1;
    unsigned short key, optional;
    unsigned char flags, detailFlags, credited, specialCount;
};
struct Action02155184 { char p[22]; unsigned char flagB, flagA; };
struct Root02155184 {
    char p0[0x81b4]; Action02155184 actions[3];
    char p1[0x8d66-0x81fc]; Entry02155184 entries[12];
    char p2[0x8e18-0x8dde]; char* info;
    char p3[12]; int total; int secondary; int entryCount; int specialTotal;
};
struct Record02155184 { char p[8]; int total; unsigned short secondary; };
struct Filter02155184 { char p[10]; unsigned short unused:12, special:1, rest:3; };

static inline int GetAction02155184(Unit02155184* unit) { return unit->action; }
static inline int IsPartySlot02155184(int id) { return id >= 0 && id <= 3; }

// USA: func_ov000_02155184
// JPN: func_ov000_02155184
extern "C" ARM void func_ov000_02155184(Root02155184* obj, int id, int flags) {
    if (IsPartySlot02155184(id)) return;
    Unit02155184* unit = GetCombatantWithFlag0x400(GameState::GetInstance(), id);
    if (!unit) return;
    char* search = obj->info + 0x284;
    unsigned short key = unit->key;
    Record02155184* record;
    char* filterSearch = obj->info + 0x678;
    int action = unit->action;
    if (unit->alternate) { key = unit->alternateKey; action = unit->alternateAction; }
    record = (Record02155184*)SearchWithLow15Comparator02070fd0((Container02070e60*)(search + 0x400), key);
    if (!record) return;
    Filter02155184* filter = (Filter02155184*)SearchWithComparator0206f4f0((BinarySearchByComparatorStruct*)filterSearch, (short)key);
    if (!filter || unit->processed) return;
    int credited = 0;
    if (!(flags & 0x10) && !(flags & 0x20)) {
        obj->total += record->total;
        obj->secondary += record->secondary;
        credited = 1;
        if (filter && filter->special) obj->specialTotal += record->total;
        unit->processed = 1;
    }
    Entry02155184* entry;
    int found = 0;
    for (int i = 0; i < obj->entryCount; i++) {
        entry = &obj->entries[i];
        if (entry->key == key && action == entry->action) {
            Action02155184* a = &obj->actions[entry->action];
            entry->count = (unsigned short)(entry->count + 1);
            entry->flagA = a->flagA;
            entry->flagB = a->flagB;
            entry->flags |= unit->flags;
            unsigned char detailFlags = unit->details[0x3d];
            detailFlags = entry->detailFlags | detailFlags;
            entry->detailFlags = detailFlags;
            entry->credited |= credited;
            if ((flags & 0x10) || (flags & 0x20)) entry->specialCount++;
            found = 1;
            break;
        }
    }
    if (found) return;
    if (obj->entryCount >= 12) return;
    if (GetAction02155184(unit) >= 3) return;
    {
        Action02155184* a = &obj->actions[unit->action];
        entry = &obj->entries[obj->entryCount];
        memset(entry, 0, sizeof(*entry));
        entry->key = key;
        entry->action = (unsigned short)action;
        entry->count = 1;
        entry->flagA = a->flagA;
        entry->flagB = a->flagB;
        entry->flags |= unit->flags;
        unsigned char detailFlags = unit->details[0x3d];
            detailFlags = entry->detailFlags | detailFlags;
            entry->detailFlags = detailFlags;
        entry->credited |= credited;
        if ((flags & 0x10) || (flags & 0x20)) entry->specialCount++;
        if (unit->optional) entry->optional = unit->optional[8];
        obj->entryCount++;
    }
}
