#include <globaldefs.h>
#include "System/Cache.h"
#include "System/LoadToVRAM.h"

struct Res020b08b8 {
    int f0;
    int f4;
    unsigned int f8;
    const unsigned char* f0c;
};

struct Pcmp020b08b8 {
    unsigned short count;
    unsigned short pad2;
    const unsigned short* table;
};

struct Out020b08b8 {
    int f0;
    int f4;
    int arr[3];
};

extern "C" void _Z28SetIndexedFieldAt0x8020b035cPcii(char* base, int index, int value);

// USA: func_020b08b8
extern "C" ARM void func_020b08b8(Res020b08b8* res, Pcmp020b08b8* pcmp, int base, int tier,
                                  Out020b08b8* out) {
    unsigned int size = (res->f0 == 3) ? 0x20 : 0x200;
    unsigned short count = pcmp->count;
    unsigned int dst;
    const unsigned char* data;
    unsigned int src;
    unsigned short i = 0;

    if (count != 0) {
        do {
            data = res->f0c;
            unsigned int idx = pcmp->table[i];
            dst = size * i;
            src = size * idx;
            CleanInvalidateCacheRange(data, res->f8);
            switch (tier) {
            case 1:
                if (res->f4) {
                    MemoryMapMainObjExtendedPalette();
                    LoadToMainObjExtendedPalette(data + dst, base + src, size);
                    MemoryUnmapMainObjExtendedPalette();
                } else {
                    LoadToMainObjStandardPalette(data + dst, base + src, size);
                }
                break;
            case 2:
                if (res->f4) {
                    MemoryMapSubObjExtendedPalette();
                    LoadToSubObjExtendedPalette(data + dst, base + src, size);
                    MemoryUnmapSubObjExtendedPalette();
                } else {
                    LoadToSubObjStandardPalette(data + dst, base + src, size);
                }
                break;
            case 0:
                MemoryMapTexturePalette();
                LoadToTexturePalette(data + dst, base + src, size);
                MemoryUnmapTexturePalette();
                break;
            }
            i++;
        } while (i < count);
    }

    out->f0 = res->f0;
    out->f4 = res->f4;
    _Z28SetIndexedFieldAt0x8020b035cPcii((char*)out, tier, base);
}
