#include <globaldefs.h>
#include "World/ZoneChest.h"
#include "Graphics/Vector.h"

struct Entry_02028bd0 {
    unsigned short id;
    unsigned short field2;
    unsigned short activeMask;
    char pad6[0x318 - 6];
};
Entry_02028bd0* GetEntryTableBase_02027ca4();
Entry_02028bd0* FindInlineEntryById(Entry_02028bd0*, int);

// USA: func_02018918
extern "C" ARM void func_02018918(Zone3D* owner, ZoneFeatures::Opcode6aEntry* parameter) {
    BmdjSceneElement* entry = FindEntryByNodeIdAndKey_02018b34(owner, parameter);
    if (entry) {
        entry->flags &= ~1;
        entry->flags &= ~4;
        for (int i = 0; i < owner->unknown_82c_; ++i) {
            BmdjSceneElement* linked = owner->terrainElements_[i];
            if (linked->parent == entry) {
                linked->flags &= ~1;
                break;
            }
        }
        if (parameter->unk_2c.type2.unk_2_high & 0x20) {
            short angle = fix32ReduceAngle0To2Pi((short)(parameter->unk_20 + 0x1922));
            int cosine = fix32cos(angle);
            Vector3fix displacement;
            displacement.x = fix32sin(angle);
            displacement.y = 0;
            displacement.z = cosine;
            Vector3fix_Normalize(&displacement, &displacement);
            Vector3fixMultiplyScalar(&displacement, -parameter->unk_2c.type2.unk_40, &displacement);
            Vector3fix direction;
            Vector3fix_Normalize(&displacement, &direction);
            entry->direction = direction;
            Vector3fix position;
            Vector3fix_Add(&entry->position, &displacement, &position);
            entry->position = position;
        }
        parameter->unk_2c.type2.unk_2_high &= ~1;
        owner->unk_830[0] = 15;
        if (!(parameter->unk_2c.type2.unk_2_high & 8)) {
            int index = FindMatchingElementIndex02018bc4(owner, parameter);
            Entry_02028bd0* saved = FindInlineEntryById(GetEntryTableBase_02027ca4(), owner->currentZoneID_);
            if (saved) saved->activeMask &= ~(1 << index);
        }
    }
}
