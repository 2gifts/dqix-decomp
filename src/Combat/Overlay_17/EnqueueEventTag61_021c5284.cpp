#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);
extern "C" void func_0202ae18(void);
extern "C" int func_0202c508(void);
void EnqueueEventTag147_021cdaa0(void);

struct Src021c5284 {
    unsigned short field0;
    unsigned short field2;
    unsigned char field4;
    unsigned char field5;
    unsigned short field6;
    unsigned char field8;
    unsigned char field9;
    unsigned short fielda;
    unsigned char fieldc;
};

struct LocalEvt021c5284 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned short field4;
    unsigned short field6;
    unsigned char field8;
    unsigned char field9;
    unsigned short fielda;
    unsigned char fieldc;
    unsigned char fieldd;
    unsigned short fielde;
    unsigned char field10;
};

// USA: func_ov017_021c5284
ARM void EnqueueEventTag61_021c5284(Src021c5284* src) {
    void* p = GetData02100044_0202ae24();

    LocalEvt021c5284 buf;
    buf.tag = 0x3d;
    buf.field4 = src->field0;
    buf.field6 = src->field2;
    buf.field8 = src->field4;
    buf.field9 = src->field5;
    buf.fielda = src->field6;
    buf.fieldc = src->field8;
    buf.fieldd = src->field9;
    buf.fielde = src->fielda;
    buf.field10 = src->fieldc;
    func_0205e330(p, &buf, 0);

    func_0202ae18();
    if (func_0202c508()) {
        EnqueueEventTag147_021cdaa0();
    }
}
