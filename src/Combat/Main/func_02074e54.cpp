#include <globaldefs.h>
#include <System/Graphics.h>

struct BgControl {
    unsigned short priority : 2;
    unsigned short charBase : 4;
    unsigned short mosaic : 1;
    unsigned short colorMode : 1;
    unsigned short screenBase : 5;
    unsigned short wrap : 1;
    unsigned short screenSize : 2;
};

struct BgSlot {
    unsigned short unused;
    struct BgControl cnt;
};

struct Struct02074bf4 {
    struct BgSlot bg[4];
    unsigned char pad10;
    unsigned char flag11;
};

inline short GetCharBase(struct BgControl* cnt) {
    short value = cnt->charBase;
    return value;
}

inline short GetWrap(struct BgControl* cnt) {
    short value = cnt->wrap;
    return value;
}

// USA: func_02074e54
extern "C" ARM void func_02074e54(struct Struct02074bf4* obj) {
    if (obj->flag11) {
        struct BgControl* cnt0 = &obj->bg[0].cnt;
        struct BgControl* cnt1 = &obj->bg[1].cnt;
        struct BgControl* cnt2 = &obj->bg[2].cnt;
        struct BgControl* cnt3 = &obj->bg[3].cnt;
        BG0CNTSUB = (cnt0->screenSize << 14) | (BG0CNTSUB & 0x43) | (cnt0->colorMode << 7) |
                    (cnt0->screenBase << 8) | (GetCharBase(cnt0) << 2) | (GetWrap(cnt0) << 13);
        BG1CNTSUB = (cnt1->screenSize << 14) | (BG1CNTSUB & 0x43) | (cnt1->colorMode << 7) |
                    (cnt1->screenBase << 8) | (GetCharBase(cnt1) << 2) | (GetWrap(cnt1) << 13);
        BG2CNTSUB = (cnt2->screenSize << 14) | (BG2CNTSUB & 0x43) | (cnt2->colorMode << 7) |
                    (cnt2->screenBase << 8) | (GetCharBase(cnt2) << 2);
        BG3CNTSUB = (cnt3->screenSize << 14) | (BG3CNTSUB & 0x43) | (cnt3->colorMode << 7) |
                    (cnt3->screenBase << 8) | (GetCharBase(cnt3) << 2);

        BG0CNTSUB = (BG0CNTSUB & ~3) | cnt0->priority;
        BG1CNTSUB = (BG1CNTSUB & ~3) | cnt1->priority;
        BG2CNTSUB = (BG2CNTSUB & ~3) | cnt2->priority;
        BG3CNTSUB = (BG3CNTSUB & ~3) | cnt3->priority;

        if (cnt0->mosaic) {
            BG0CNTSUB |= 0x40;
        } else {
            BG0CNTSUB &= ~0x40;
        }
        if (cnt1->mosaic) {
            BG1CNTSUB |= 0x40;
        } else {
            BG1CNTSUB &= ~0x40;
        }
        if (cnt2->mosaic) {
            BG2CNTSUB |= 0x40;
        } else {
            BG2CNTSUB &= ~0x40;
        }
        if (cnt3->mosaic) {
            BG3CNTSUB |= 0x40;
        } else {
            BG3CNTSUB &= ~0x40;
        }
    }
}
