#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Src021c5f00 { unsigned short w0; unsigned short w2; unsigned char b4; unsigned char b5; unsigned char b6; };

struct LocalEvt021c5f00 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned short field4;
    unsigned short field6;
    unsigned char field8;
    unsigned char field9;
    unsigned char fielda;
    unsigned char pad2[9];
};

// USA: func_ov017_021c5f00
ARM void EnqueueEventTag63_021c5f00(Src021c5f00* src) {
    LocalEvt021c5f00 buf;
    void* p = GetData02100044_0202ae24();
    buf.tag = 0x3f;
    buf.field4 = src->w0;
    buf.field6 = src->w2;
    buf.field8 = src->b4;
    buf.field9 = src->b5;
    buf.fielda = src->b6;
    func_0205e330(p, &buf, 0);
}
