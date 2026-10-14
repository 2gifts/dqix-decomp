#include <globaldefs.h>
#include "World/Zone3D.h"

extern "C" void *func_02012fe4(void);
int IsInRange0201b588(int zoneId);
int StringLength_020d2ff0(const char *text);
void SetElementFields0202756c(void *receiver, int x, int y, int elementIndex, unsigned char image, unsigned char palette,
                              unsigned short tile, unsigned char flags, int scaleX, int scaleY);

static inline int PixelsToFixed(int pixels) {
    return pixels << 12;
}

// USA: func_0202427c
extern "C" ARM void func_0202427c(void *receiver) {
    unsigned char *frame = static_cast<unsigned char *>(receiver);
    Zone3D *zone = static_cast<Zone3D *>(func_02012fe4());
    unsigned short zoneId = zone->currentZoneID_;
    if (!frame[0x5a8] || IsInRange0201b588(zoneId) || zoneId == 10000 || zoneId == 10100) {
        return;
    }

    int x = 256;
#if defined(jpn)
    int textWidth = 10 * (StringLength_020d2ff0(zone->substruct_c_.jpbuffer) / 2);
    int objectCount = textWidth / 8 + 1;
    *reinterpret_cast<unsigned short *>(frame + 0x4d0) = objectCount;
    int width = objectCount * 8;
#else
    int width = (*reinterpret_cast<int *>(frame + 0xbe4) + 7) & ~7;
    if (width > 144) {
        width = 144;
    }
    *reinterpret_cast<unsigned short *>(frame + 0x4d0) = static_cast<unsigned short>(width) >> 3;
#endif

    x -= 8;
    SetElementFields0202756c(receiver, PixelsToFixed(x), 0, 26, 0x53, 0, 8, 0xff, 4096, 4096);
    x -= width;
    SetElementFields0202756c(receiver, PixelsToFixed(x), 0, 25, 0x41, 0, 8, 0xff, 4096, 4096);
    SetElementFields0202756c(receiver, PixelsToFixed(x - 8), 0, 24, 0x40, 0, 8, 0xff, 4096, 4096);
}
