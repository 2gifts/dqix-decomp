#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021c9b20 {
    unsigned char tag;
    unsigned char pad[5];
    unsigned short field6;
    unsigned char pad2[2];
    unsigned char field0xa;
    unsigned char pad3[9];
};

// USA: func_ov017_021c9b20
ARM void EnqueueEventTag87_021c9b20(int a, int b) {
    LocalEvt021c9b20 buf;
    void* p = GetData02100044_0202ae24();
    buf.tag = 0x57;
    buf.field6 = (unsigned short)a;
    buf.field0xa = (unsigned char)b;
    func_0205e330(p, &buf, 0);
}
