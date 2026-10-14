#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021d1874 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned char a, b, c, d, e, f;
    unsigned char pad1[2];
    unsigned int g;
    unsigned char pad2[4];
};

// USA: func_ov017_021d1874  (semantic: EnqueueEventTag174_021d1874)
extern "C" ARM void func_ov017_021d1874(int a, int b, int c, int d, unsigned char e, unsigned char f, unsigned int g) {
    LocalEvt021d1874 buf;
    void* p = GetData02100044_0202ae24();
    unsigned char* tail = &buf.a;
    buf.tag = 0xae;
    tail[0] = a;
    tail[1] = b;
    tail[2] = c;
    tail[3] = d;
    tail[4] = e;
    tail[5] = f;
    *(unsigned int*)(tail + 8) = g;
    func_0205e330(p, &buf, 0);
}
