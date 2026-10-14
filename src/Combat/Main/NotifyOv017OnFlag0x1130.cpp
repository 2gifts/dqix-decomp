#include <globaldefs.h>
#include "World/Zone3D.h"

extern "C" void* func_02012fe4(void);
extern "C" void func_ov017_021d1874(unsigned char a, unsigned char b, unsigned char c, int d, int e, int f, int g);

// USA: func_020a8740
ARM void NotifyOv017OnFlag0x1130_020a8740(void) {
    Zone3D* zone = (Zone3D*)func_02012fe4();
    int i = 0;
    for (;;) {
        ZoneFeatures::Opcode6aEntry* entry = GetElementStride0x74_0201e664(&zone->substruct_6c_, i);
        i++;
        if (!entry) return;
        if (entry->maybeType != 0xc) continue;
        unsigned char* sub = (unsigned char*)&entry->unk_2c.type12;
        unsigned short field = zone->unknown_4_;
        if (!sub) return;
        if (field == 0x1130 && sub[0] == 1) {
            func_ov017_021d1874(sub[0], sub[1], sub[2], 2, 0, 0, 0);
        }
    }
}
