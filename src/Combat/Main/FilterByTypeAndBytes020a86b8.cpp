#include <globaldefs.h>
#include "World/Zone3D.h"


extern "C" void* func_02012fe4(void);
extern "C" void* func_020a8a34(void*, int, int, int);

// USA: func_020a86b8
ARM void* FilterByTypeAndBytes020a86b8(int unused, int flag, unsigned char b0, unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4, unsigned char b5) {
    Zone3D* zone = (Zone3D*)func_02012fe4();
    int i = 0;
    for (;;) {
        ZoneFeatures::Opcode6aEntry* entry = GetElementStride0x74(&zone->substruct_6c_, i);
        i++;
        if (!entry) return entry;
        if (entry->maybeType != 0xc) continue;
        unsigned char* sub = (unsigned char*)&entry->unk_2c.type12;
        if (!sub) return sub;
        if (flag != 0) {
            if (sub[0] == b0 && sub[1] == b1 && sub[2] == b2 && b0 == 1) {
                return func_020a8a34(sub, b3, b4, b5);
            }
        }
    }
}
