#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021cc68c {
    unsigned char tag;
    unsigned char pad[3];
    unsigned char field4;
    unsigned char field5;
    unsigned char pad2[14];
};

// USA: func_ov017_021cc68c
ARM void EnqueueEventTag9_021cc68c(int a) {
    LocalEvt021cc68c buf;
    void* p = GetData02100044_0202ae24();
    buf.tag = 9;
    buf.field5 = (unsigned char)a;
    buf.field4 = 1;
    func_0205e330(p, &buf, 0);
}
