#include <globaldefs.h>
#include "System/Cache.h"
#include "System/LoadToVRAM.h"

struct LocalRes020b07c0 {
    int f0;
    int f4;
    unsigned int f8;
    const void* f0c;
};

struct Obj020b07c0 {
    int f0;
    int f4;
    char pad8[0x18];
};

extern "C" void _Z28SetIndexedFieldAt0x8020b035cPcii(char* base, int index, int value);

// USA: func_020b07c0
extern "C" ARM void func_020b07c0(LocalRes020b07c0* res, int val44, int tier, Obj020b07c0* out) {
    const void* data = res->f0c;
    unsigned int len = res->f8;

    CleanInvalidateCacheRange(data, len);

    switch (tier) {
    case 1:
        if (res->f4) {
            MemoryMapMainObjExtendedPalette();
            LoadToMainObjExtendedPalette(data, val44, len);
            MemoryUnmapMainObjExtendedPalette();
        } else {
            LoadToMainObjStandardPalette(data, val44, len);
        }
        break;
    case 2:
        if (res->f4) {
            MemoryMapSubObjExtendedPalette();
            LoadToSubObjExtendedPalette(data, val44, len);
            MemoryUnmapSubObjExtendedPalette();
        } else {
            LoadToSubObjStandardPalette(data, val44, len);
        }
        break;
    case 0:
        MemoryMapTexturePalette();
        LoadToTexturePalette(data, val44, len);
        MemoryUnmapTexturePalette();
        break;
    }

    out->f0 = res->f0;
    out->f4 = res->f4;
    _Z28SetIndexedFieldAt0x8020b035cPcii((char*)out, tier, val44);
}