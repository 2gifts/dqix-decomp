#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

union Payload021c9168 {
    struct { unsigned char lowNibble : 4; unsigned char padLo : 4; } lo;
    struct { char padHi : 4; char highNibble : 4; } hi;
};

struct Evt021c9168 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned short field4;
    unsigned char pad2[1];
    union Payload021c9168 payload;
    unsigned short field8;
    unsigned short fieldA;
    unsigned int fieldC;
    unsigned int field10;
};

// USA: func_ov017_021c9168
extern "C" ARM void func_ov017_021c9168(int p0, int p1, int p2, int p3,
        int p4, int p5, int p6, int p7, int p8, int p9, int p10) {
    void* d = GetData02100044_0202ae24();

    struct Evt021c9168 evt;
    evt.tag = 0x84;
    evt.field4 = (unsigned short)p0;
    evt.payload.lo.lowNibble = (unsigned char)p1;
    evt.payload.hi.highNibble = (char)p10;
    evt.fieldC = p4;
    evt.field10 = p6;
    evt.fieldA = (unsigned short)p8;
    evt.field8 = (unsigned short)p3;

    func_0205e330(d, &evt, 0);
}
