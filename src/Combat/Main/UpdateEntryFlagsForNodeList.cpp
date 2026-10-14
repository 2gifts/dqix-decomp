#include <globaldefs.h>
#include "World/ZoneChest.h"

void* GetPointerFromArray0x3c_0201e838(unsigned char*, unsigned int);

// USA: func_02018ab8
ARM void UpdateEntryFlagsForNodeList_02018ab8(Zone3D* zone) {
    ZoneFeatures::Opcode6aEntry* node;
    BmdjSceneElement* entry;
    int hasFlag;

    node = (ZoneFeatures::Opcode6aEntry*)GetPointerFromArray0x3c_0201e838((unsigned char*)&zone->substruct_6c_, 2);
    while (node != NULL) {
        entry = FindEntryByNodeIdAndKey_02018b34(zone, node);
        hasFlag = (node->unk_2c.type2.unk_2_high & 0x80) != 0;
        if (entry != NULL) {
            entry->flags |= 0x8;
            if (hasFlag) entry->flags |= 0x10;
        }
        node = node->pNext;
    }
}
