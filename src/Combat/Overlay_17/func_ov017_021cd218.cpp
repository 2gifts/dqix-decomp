#include <globaldefs.h>

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Evt021cd218 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned short field4 : 16;
    unsigned short field6 : 16;
    unsigned short field8 : 16;
    unsigned short fieldA_lo : 4;
    unsigned short fieldA_hi : 12;
    unsigned short fieldC_lo : 4;
    unsigned short fieldC_hi : 12;
    unsigned char pad2[6];
};

// USA: func_ov017_021cd218
extern "C" ARM void func_ov017_021cd218(unsigned short a, unsigned short b, unsigned short c, unsigned short d, unsigned short e, unsigned short f) {
    void* data = GetData02100044();

    struct Evt021cd218 evt;
    evt.tag = 0x66;
    evt.field4 = a;
    evt.field6 = b;
    evt.field8 = c;
    evt.fieldA_lo = d;
    evt.fieldC_lo = e;
    evt.fieldA_hi = f;

    func_0205e330(data, &evt, 0);
}
