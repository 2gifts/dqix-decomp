#include <globaldefs.h>

struct Variant02030b0c {
    int tag;
    union { int i; float f; } u;
};
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
extern "C" void func_02027910(void*, int, int, int, int);

struct Global020fdc4c_f5a8 {
    int pad0;
    int pad4;
    void* field8;

#if !defined(jpn)
    int padc;
#endif
    void* field10;
};
extern struct Global020fdc4c_f5a8 data_020fdc4c;

struct Vec4Variant0201f5a8 {
    struct Variant02030b0c v0;
    struct Variant02030b0c v1;
    struct Variant02030b0c v2;
    struct Variant02030b0c v3;
};

// USA: func_0201f5a8
ARM int SetDecodedIntEntry0201f5a8(struct Vec4Variant0201f5a8* arg0) {
    int a = _ZNK6Script9Parameter5ToIntEv(&arg0->v0);
    int b = _ZNK6Script9Parameter5ToIntEv(&arg0->v1);
    int c = _ZNK6Script9Parameter5ToIntEv(&arg0->v2);
    int d = _ZNK6Script9Parameter5ToIntEv(&arg0->v3);
    func_02027910((void*)data_020fdc4c.field10, a, b, c, d);
    return 1;
}
