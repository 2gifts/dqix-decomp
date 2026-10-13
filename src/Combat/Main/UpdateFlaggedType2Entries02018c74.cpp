#include <globaldefs.h>
#include "World/ZoneChest.h"

extern "C" void* func_0205ec34();

// USA: func_02018c74
ARM void UpdateFlaggedType2Entries02018c74(Zone3D* zone, unsigned int flags) {
    func_0205ec34();
    int i;
    for (i = 0; i < 16; i++) {
        if (flags & (1 << i)) {
            ZoneFeatures::Opcode6aEntry* record = FindNthType2Entry02018c20(zone, i);
            if (record) {
                if (!(record->unk_2c.type2.unk_2_high & 8)) {
                    record->unk_2c.type2.unk_2_high = record->unk_2c.type2.unk_2_high | 0x101;
                }
                func_02018300(zone, record, 0, 0, 0);
            }
        }
    }
    zone->unknown_281e_ = 0;
}
