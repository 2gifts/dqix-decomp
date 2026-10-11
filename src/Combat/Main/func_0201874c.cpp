#include <globaldefs.h>
#if defined(jpn)
enum { kOwnerPad = 0x842 };
#else
enum { kOwnerPad = 0x822 };
#endif
#include <Graphics/Vector.h>

struct Entry02018b34 {
    unsigned short key;
    unsigned short flags;
    signed char state : 7;
    signed char field_4 : 1;
    char field_5;
    short angle;
    Vector3fix position;
    char pad_14[0x20];
    short targetAngle;
    short angularSpeed;
    short field_38;
    short duration;
    Vector3fix target;
    Vector3fix direction;
    char pad_54[0x1c];
};
struct LinkedEntry {
    unsigned short key;
    unsigned short flags;
    char pad_4[0x24];
    Entry02018b34* entry;
};
struct Owner02018b34 {
    unsigned short id;
    char pad_2[kOwnerPad];
    LinkedEntry** linkedEntries;
    int field_828;
    int linkedCount;
    unsigned char state;
};
struct Param02018b34 {
    char pad_0[0x2e];
    unsigned short field_2e : 4;
    unsigned short flags : 12;
    char pad_30[0x3c];
    int distance;
};
struct Entry_02028bd0 {
    unsigned short id;
    unsigned short field_2;
    unsigned short activeMask;
};
Entry02018b34* FindEntryByNodeIdAndKey(Owner02018b34*, Param02018b34*);
extern "C" int _Z32FindMatchingElementIndex02018bc4PhPv(unsigned char*, void*);
Entry_02028bd0* GetEntryTableBase();
Entry_02028bd0* FindInlineEntryById(Entry_02028bd0*, int);

// USA: func_0201874c
extern "C" ARM void func_0201874c(Owner02018b34* owner, Param02018b34* parameter) {
    Entry02018b34* entry = FindEntryByNodeIdAndKey(owner, parameter);
    if (!entry) return;
    entry->flags &= ~1;
    entry->flags &= ~4;
    for (int i = 0; i < owner->linkedCount; i++) {
        LinkedEntry* linked = owner->linkedEntries[i];
        if (linked->entry == entry) {
            linked->flags &= ~1;
            break;
        }
    }
    if (parameter->flags & 0x20) {
        Vector3fix target;
        Vector3fix offset;
        Vector3fixMultiplyScalar(&entry->direction, parameter->distance, &offset);
        Vector3fix_Add(&entry->position, &offset, &target);
        entry->direction.x = -entry->direction.x;
        entry->direction.y = -entry->direction.y;
        entry->direction.z = -entry->direction.z;
        entry->target = target;
        entry->duration = 0x266;
    } else {
        if (parameter->flags & 2) entry->targetAngle = 128.68f + entry->angle;
        else entry->targetAngle = entry->angle - 128.68f;
        entry->angularSpeed = 0x199;
        entry->state = 0x1f;
        entry->flags |= 0x80;
    }
    parameter->flags &= ~1;
    owner->state = 0xf;
    if (!(parameter->flags & 8)) {
        int index = _Z32FindMatchingElementIndex02018bc4PhPv((unsigned char*)owner, parameter);
        Entry_02028bd0* table = GetEntryTableBase();
        Entry_02028bd0* saved = FindInlineEntryById(table, owner->id);
        if (saved) saved->activeMask &= ~(1 << index);
    }
}
