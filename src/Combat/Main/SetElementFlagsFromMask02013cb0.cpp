#include <globaldefs.h>
#include "World/ZoneChest.h"

struct Entry_02028bd0;
Entry_02028bd0* GetEntryTableBase_02027ca4();
Entry_02028bd0* FindInlineEntryById(Entry_02028bd0* base, int key);

// USA: func_02013cb0
ARM void SetElementFlagsFromMask02013cb0(Zone3D* zone, unsigned int mask) {
    int i;
    for (i = 0; i < zone->unknown_476_; i++) {
        if (mask & (1 << i)) {
            zone->unknown_478_[i].field2 = -1;
        }
    }
    Entry_02028bd0* base = GetEntryTableBase_02027ca4();
    Entry_02028bd0* result = FindInlineEntryById(base, zone->currentZoneID_);
    if (result == NULL) {
        return;
    }
    unsigned short* fieldPtr = (unsigned short*)((unsigned char*)result + 2);
    unsigned int cur = *fieldPtr;
    *fieldPtr = (cur & 0xffff000f) | ((mask << 20) >> 16);
}
