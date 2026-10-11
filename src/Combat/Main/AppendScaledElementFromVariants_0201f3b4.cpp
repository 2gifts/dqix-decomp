#if defined(jpn)
enum { RegionalPad = 0xc };
#else
enum { RegionalPad = 0x10 };
#endif

#include <globaldefs.h>

struct Variant02030b0c {
    int tag;
    union { int i; float f; } u;
};
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct TaggedValue02030b44 {
    int type;
    union { int i; float f; } value;
};
extern "C" float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);

struct Container02027b5c;
void AppendCappedElement02027b5c(struct Container02027b5c* c, unsigned short h, unsigned char b, int w4, int w8);

extern "C" void func_02012fe4(void);

struct Global020fdc4c_f3b4 {
    char pad[RegionalPad];
    void* field10;
};
extern struct Global020fdc4c_f3b4 data_020fdc4c;

struct QuadArg0201f3b4 {
    struct Variant02030b0c v0;
    struct Variant02030b0c v1;
    struct TaggedValue02030b44 v2;
    struct TaggedValue02030b44 v3;
};

// USA: func_0201f3b4  (semantic: AppendScaledElementFromVariants_0201f3b4)
// JPN: func_0201f3b4  (semantic: AppendScaledElementFromVariants_0201f3b4)
extern "C" ARM int func_0201f3b4(struct QuadArg0201f3b4* arg0) {
    float c;
    int a = _ZNK6Script9Parameter5ToIntEv(&arg0->v0);
    int b = _ZNK6Script9Parameter5ToIntEv(&arg0->v1);
    c = _ZNK6Script9Parameter7ToFloatEv(&arg0->v2);
    float d = _ZNK6Script9Parameter7ToFloatEv(&arg0->v3);
    func_02012fe4();
    if (b == 0) return 1;
    float roundedD;
    if (d > 0.0f) {
        roundedD = 4096.0f * d + 0.5f;
    } else {
        roundedD = 4096.0f * d - 0.5f;
    }
    float roundedC;
    if (c > 0.0f) {
        roundedC = 4096.0f * c + 0.5f;
    } else {
        roundedC = 4096.0f * c - 0.5f;
    }
    AppendCappedElement02027b5c((struct Container02027b5c*)data_020fdc4c.field10, (unsigned short)(a / 100), (unsigned char)b, (int)roundedC, (int)roundedD);
    return 1;
}
