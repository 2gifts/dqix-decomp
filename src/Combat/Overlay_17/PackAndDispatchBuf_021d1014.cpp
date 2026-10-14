#include <globaldefs.h>

void* GetData02100044_0202ae24();
extern "C" void func_0205e330(void* p, void* buf, int flag);

struct SubField4_021d1014 {
    unsigned char low7 : 7;
    unsigned char bit7 : 1;
    unsigned char b5;
};

struct LocalBuf021d1014 {
    unsigned char b0;
    unsigned char pad1[3];
    struct SubField4_021d1014 sub;
    unsigned char pad2[0x14 - 6];
};

// USA: func_ov017_021d1014  (semantic: PackAndDispatchBuf_021d1014)
extern "C" ARM void func_ov017_021d1014(int arg0, unsigned char arg1, int arg2) {
    void* g = GetData02100044_0202ae24();
    struct LocalBuf021d1014 buf;
    struct SubField4_021d1014* sub = &buf.sub;
    sub->low7 = arg0;
    buf.b0 = 0x19;
    sub->bit7 = arg1;
    sub->b5 = arg2;
    func_0205e330(g, &buf, 0);
}
