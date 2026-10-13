#include <globaldefs.h>
#include "World/ZoneChest.h"
#include <Graphics/Vector.h>

struct Entry_02028bd0 {
    unsigned short id;
    unsigned short field_2;
    unsigned short activeMask;
};
Entry_02028bd0* GetEntryTableBase();
Entry_02028bd0* FindInlineEntryById(Entry_02028bd0*, int);

// USA: func_0201874c
extern "C" ARM void func_0201874c(Zone3D* owner, ZoneFeatures::Opcode6aEntry* parameter) {
    BmdjSceneElement* entry = FindEntryByNodeIdAndKey(owner, parameter);
    if (!entry) return;
    entry->flags &= ~1;
    entry->flags &= ~4;
    for (int i = 0; i < owner->unknown_82c_; i++) {
        BmdjSceneElement* linked = owner->terrainElements_[i];
        if (linked->parent == entry) {
            linked->flags &= ~1;
            break;
        }
    }
    if (parameter->unk_2c.type2.unk_2_high & 0x20) {
        Vector3fix target;
        Vector3fix offset;
        Vector3fixMultiplyScalar(&entry->direction, parameter->unk_2c.type2.unk_40, &offset);
        Vector3fix_Add(&entry->position, &offset, &target);
        entry->direction.x = -entry->direction.x;
        entry->direction.y = -entry->direction.y;
        entry->direction.z = -entry->direction.z;
        entry->destination = target;
        entry->movementSpeed = 0x266;
    } else {
        if (parameter->unk_2c.type2.unk_2_high & 2) entry->destinationAngle = 128.68f + entry->angle;
        else entry->destinationAngle = entry->angle - 128.68f;
        entry->rotationSpeed = 0x199;
        entry->state = 0x1f;
        entry->flags |= 0x80;
    }
    parameter->unk_2c.type2.unk_2_high &= ~1;
    owner->unk_830[0] = 0xf;
    if (!(parameter->unk_2c.type2.unk_2_high & 8)) {
        int index = FindMatchingElementIndex02018bc4(owner, parameter);
        Entry_02028bd0* table = GetEntryTableBase();
        Entry_02028bd0* saved = FindInlineEntryById(table, owner->currentZoneID_);
        if (saved) saved->activeMask &= ~(1 << index);
    }
}
