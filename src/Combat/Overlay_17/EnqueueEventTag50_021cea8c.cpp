#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021cea8c {
    unsigned char tag;
    unsigned char pad[0x13];
};

// USA: func_ov017_021cea8c
ARM void EnqueueEventTag50_021cea8c(void) {
    LocalEvt021cea8c buf;
    void* p = GetData02100044_0202ae24();
    buf.tag = 0x32;
    func_0205e330(p, &buf, 0);
}
