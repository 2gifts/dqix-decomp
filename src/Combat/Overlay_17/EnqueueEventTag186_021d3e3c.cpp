#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* p);
void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021d3e3c {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned char id;
    unsigned char pad1[14];
};

// USA: func_ov017_021d3e3c
ARM void EnqueueEventTag186_021d3e3c(unsigned char id) {
    if (func_0202c540(func_0202ae18())) return;
    LocalEvt021d3e3c buf;
    void* p = GetData02100044_0202ae24();
    buf.tag = 0xba;
    buf.id = id;
    func_0205e330(p, &buf, 0);
}
