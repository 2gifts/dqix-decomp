#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021d3ec8 {
    unsigned char tag;
    unsigned char pad[0x13];
};

// USA: func_ov017_021d3ec8
ARM void EnqueueEventTag167_021d3ec8(void) {
    LocalEvt021d3ec8 buf;
    void* p = GetData02100044_0202ae24();
    buf.tag = 0xa7;
    func_0205e330(p, &buf, 0);
}
