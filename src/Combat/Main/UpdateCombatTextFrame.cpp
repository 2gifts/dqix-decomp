#include <globaldefs.h>

extern "C" void *func_02012fe4(void);
int IsInRange0201b588(int zoneId);
void SetElementFields0202756c(void *receiver, int x, int y, int elementIndex, unsigned char image, unsigned char palette,
                              unsigned short tile, unsigned char flags, int scaleX, int scaleY);

struct CombatTextFrameView {
    unsigned char unknown0[0x4d0];
    unsigned short widthTiles;
    unsigned char unknown4d2[0x5a8 - 0x4d2];
    unsigned char enabled;
    unsigned char unknown5a9[0xbe4 - 0x5a9];
    int textWidth;
};

static inline int PixelsToFixed(int pixels) {
    return pixels << 12;
}

// USA: func_0202427c
extern "C" ARM void func_0202427c(void *receiver) {
    CombatTextFrameView *frame = static_cast<CombatTextFrameView *>(receiver);
    unsigned short zoneId      = *static_cast<unsigned short *>(func_02012fe4());
    if (!frame->enabled || IsInRange0201b588(zoneId) || zoneId == 10000 || zoneId == 10100) {
        return;
    }

    int x     = 256;
    int width = (frame->textWidth + 7) & ~7;
    if (width > 144) {
        width = 144;
    }
    frame->widthTiles = static_cast<unsigned short>(width) >> 3;

    x -= 8;
    SetElementFields0202756c(receiver, PixelsToFixed(x), 0, 26, 0x53, 0, 8, 0xff, 4096, 4096);
    x -= width;
    SetElementFields0202756c(receiver, PixelsToFixed(x), 0, 25, 0x41, 0, 8, 0xff, 4096, 4096);
    SetElementFields0202756c(receiver, PixelsToFixed(x - 8), 0, 24, 0x40, 0, 8, 0xff, 4096, 4096);
}
