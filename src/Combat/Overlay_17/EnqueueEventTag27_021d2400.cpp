#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021d2400 {
    unsigned char tag;
    unsigned char pad[19];
};

// USA: func_ov017_021d2400  (semantic: EnqueueEventTag27_021d2400)
extern "C" ARM void func_ov017_021d2400(void) {
    LocalEvt021d2400 buf;
    void* p = GetData02100044_0202ae24();
    buf.tag = 0x1b;
    func_0205e330(p, &buf, 0);
}
