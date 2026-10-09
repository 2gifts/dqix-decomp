#include <globaldefs.h>
#include "Combat/Overlay_1/EventArgs.h"

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

union Payload021c927c {
    struct { unsigned char lowNibble : 4; unsigned char padLo : 4; } lo;
    struct { char padHi : 4; char highNibble : 4; } hi;
};

struct Evt021c927c {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned short field4;
    unsigned char mode : 6;
    unsigned char pad6 : 2;
    union Payload021c927c payload;
    unsigned short field8;
    unsigned short fieldA;
    int fieldC;
    int field10;
};

// USA: func_ov017_021c927c
extern "C" ARM void func_ov017_021c927c(int id, int slot, int heading, EventVec3 pos, int height, unsigned short mode, int dir) {
    void* d = GetData02100044();

    struct Evt021c927c evt;
    evt.tag = 0x88;
    evt.field4 = (unsigned short)id;
    evt.payload.lo.lowNibble = (unsigned char)slot;
    evt.payload.hi.highNibble = (char)dir;
    evt.mode = mode;
    evt.fieldC = pos.a;
    evt.fieldA = pos.b >> 4;
    evt.field10 = pos.c;
    evt.field8 = (unsigned short)height;

    func_0205e330(d, &evt, 0);
}
