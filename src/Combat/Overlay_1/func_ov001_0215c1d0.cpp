#include <globaldefs.h>

extern "C" float func_ov017_021d6110(void*);
extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_ov001_0215ab20(int);

struct Payload12_0215a480 {
    unsigned int w0;
    unsigned int w1;
    unsigned int w2;
};

extern "C" void _Z26EnqueueEventType8_0215a480Pv18Payload12_0215a480jj(void* ctx, struct Payload12_0215a480 payload, unsigned int a, unsigned int b);

// USA: func_ov001_0215c1d0
extern "C" ARM int func_ov001_0215c1d0(void* self, int mode) {
    int b;
    int id = func_ov017_021d60f4(self);
    Payload12_0215a480 v;
    v.w0 = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x8));
    v.w1 = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x10));
    v.w2 = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x18));
    int a = func_ov017_021d60f4((char*)self + 0x20);
    b = 0;
    if (mode >= 6) {
        b = func_ov017_021d60f4((char*)self + 0x28);
    }
    void* node = func_ov001_0215ab20(id);
    if (node == NULL) {
        return 0;
    }
    _Z26EnqueueEventType8_0215a480Pv18Payload12_0215a480jj(node, v, a, b);
    return 1;
}
