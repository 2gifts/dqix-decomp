#include <globaldefs.h>
#if defined(jpn)
enum { kOwnerPad = 0x844 - 2 };
#else
enum { kOwnerPad = 0x824 - 2 };
#endif
#include "Graphics/Vector.h"

struct Entry02018b34 {
    unsigned short key;
    unsigned short flags;
    char pad4[4];
    Vector3fix position;
    char pad14[0x48 - 0x14];
    Vector3fix direction;
    char pad54[0x70 - 0x54];
};
struct LinkedEntry {
    unsigned short key;
    unsigned short flags;
    char pad4[0x28 - 4];
    Entry02018b34* target;
};
struct Owner02018b34 {
    unsigned short id;
    char pad2[kOwnerPad];
    LinkedEntry** linkedEntries;
    char pad828[4];
    int linkedCount;
    unsigned char updateTimer;
};
struct Param02018b34 {
    char pad0[0x20];
    short angle;
    char pad22[0x2e - 0x22];
    unsigned short kind : 4;
    unsigned short flags : 12;
    char pad30[0x6c - 0x30];
    int distance;
};
struct Entry_02028bd0 {
    unsigned short id;
    unsigned short field2;
    unsigned short activeMask;
    char pad6[0x318 - 6];
};
Entry02018b34* FindEntryByNodeIdAndKey(Owner02018b34*, Param02018b34*);
extern "C" int _Z32FindMatchingElementIndex02018bc4PhPv(unsigned char*, void*);
Entry_02028bd0* GetEntryTableBase();
Entry_02028bd0* FindInlineEntryById(Entry_02028bd0*, int);

// USA: func_02018918
extern "C" ARM void func_02018918(Owner02018b34* owner, Param02018b34* parameter) {
    Entry02018b34* entry = FindEntryByNodeIdAndKey(owner, parameter);
    if (entry) {
        entry->flags &= ~1;
        entry->flags &= ~4;
        for (int i = 0; i < owner->linkedCount; ++i) {
            LinkedEntry* linked = owner->linkedEntries[i];
            if (linked->target == entry) {
                linked->flags &= ~1;
                break;
            }
        }
        if (parameter->flags & 0x20) {
            short angle = fix32ReduceAngle0To2Pi((short)(parameter->angle + 0x1922));
            int cosine = fix32cos(angle);
            Vector3fix displacement;
            displacement.x = fix32sin(angle);
            displacement.y = 0;
            displacement.z = cosine;
            Vector3fix_Normalize(&displacement, &displacement);
            Vector3fixMultiplyScalar(&displacement, -parameter->distance, &displacement);
            Vector3fix direction;
            Vector3fix_Normalize(&displacement, &direction);
            entry->direction = direction;
            Vector3fix position;
            Vector3fix_Add(&entry->position, &displacement, &position);
            entry->position = position;
        }
        parameter->flags &= ~1;
        owner->updateTimer = 15;
        if (!(parameter->flags & 8)) {
            int index = _Z32FindMatchingElementIndex02018bc4PhPv((unsigned char*)owner, parameter);
            Entry_02028bd0* saved = FindInlineEntryById(GetEntryTableBase(), owner->id);
            if (saved) saved->activeMask &= ~(1 << index);
        }
    }
}
