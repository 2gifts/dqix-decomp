#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void* state);

struct LocalEvt021ce400 {
    unsigned char tag;
    unsigned char pad0[3];
    short field4;
    short field6;
    unsigned char pad1[12];
};

// USA: func_ov017_021ce400  (semantic: EnqueueEventTag39_021ce400)
extern "C" ARM void func_ov017_021ce400(int a, int b) {
    void* p = GetData02100044_0202ae24();
    if (func_0202c508(func_0202ae18()) != 0 && a > 0) {
        LocalEvt021ce400 buf;
        buf.tag = 0x27;
        buf.field4 = a;
        buf.field6 = b;
        func_0205e330(p, &buf, 0);
    }
}
