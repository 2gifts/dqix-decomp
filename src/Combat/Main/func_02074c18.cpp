#include <globaldefs.h>
#include "System/Graphics.h"

struct BgCnt {
    unsigned short priority : 2;
    unsigned short charBase : 4;
    unsigned short mosaic : 1;
    unsigned short colorMode : 1;
    unsigned short screenBase : 5;
    unsigned short extPalette : 1;
    unsigned short screenSize : 2;
};

struct BgSlot {
    struct BgCnt cnt;
    unsigned short pad;
};

struct Struct02074c18 {
    struct BgSlot bg[4];
    unsigned char flag10;
};

inline short GetCharBase(struct BgCnt* cnt) {
    short value = cnt->charBase;
    return value;
}

inline short GetExtPalette(struct BgCnt* cnt) {
    short value = cnt->extPalette;
    return value;
}

// USA: func_02074c18
extern "C" ARM void func_02074c18(struct Struct02074c18* obj) {
    if (obj->flag10) {
        struct BgCnt* cnt0 = &obj->bg[0].cnt;
        struct BgCnt* cnt1 = &obj->bg[1].cnt;
        struct BgCnt* cnt2 = &obj->bg[2].cnt;
        struct BgCnt* cnt3 = &obj->bg[3].cnt;
        BG0CNT = (cnt0->screenSize << 14) | (BG0CNT & 0x43) | (cnt0->colorMode << 7) |
                 (cnt0->screenBase << 8) | (GetCharBase(cnt0) << 2) | (GetExtPalette(cnt0) << 13);
        BG1CNT = (cnt1->screenSize << 14) | (BG1CNT & 0x43) | (cnt1->colorMode << 7) |
                 (cnt1->screenBase << 8) | (GetCharBase(cnt1) << 2) | (GetExtPalette(cnt1) << 13);
        BG2CNT = (cnt2->screenSize << 14) | (BG2CNT & 0x43) | (cnt2->colorMode << 7) |
                 (cnt2->screenBase << 8) | (GetCharBase(cnt2) << 2);
        BG3CNT = (cnt3->screenSize << 14) | (BG3CNT & 0x43) | (cnt3->colorMode << 7) |
                 (cnt3->screenBase << 8) | (GetCharBase(cnt3) << 2);

        BG0CNT = (BG0CNT & ~3) | cnt0->priority;
        BG1CNT = (BG1CNT & ~3) | cnt1->priority;
        BG2CNT = (BG2CNT & ~3) | cnt2->priority;
        BG3CNT = (BG3CNT & ~3) | cnt3->priority;

        if (cnt0->mosaic) {
            BG0CNT |= 0x40;
        } else {
            BG0CNT &= ~0x40;
        }
        if (cnt1->mosaic) {
            BG1CNT |= 0x40;
        } else {
            BG1CNT &= ~0x40;
        }
        if (cnt2->mosaic) {
            BG2CNT |= 0x40;
        } else {
            BG2CNT &= ~0x40;
        }
        if (cnt3->mosaic) {
            BG3CNT |= 0x40;
        } else {
            BG3CNT &= ~0x40;
        }
    }
}
