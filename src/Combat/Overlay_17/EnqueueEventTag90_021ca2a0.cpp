#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021ca2a0 {
    unsigned char tag;
    unsigned char pad[3];
    unsigned short field4;
    unsigned short field6;
    unsigned char pad2[12];
};

// USA: func_ov017_021ca2a0
ARM void EnqueueEventTag90_021ca2a0(int a, int b) {
    LocalEvt021ca2a0 buf;
    void* p = GetData02100044_0202ae24();
    buf.tag = 0x5a;
    buf.field4 = (unsigned short)a;
    buf.field6 = (unsigned short)b;
    func_0205e330(p, &buf, 0);
}
