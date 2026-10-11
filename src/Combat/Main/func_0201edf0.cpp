#include <globaldefs.h>

struct Arg0201edf0 { int type; union { int i; float f; } value; };

extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Arg0201edf0*);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(struct Arg0201edf0*);
extern "C" void* _ZNK6Script9Parameter8ToStringEv(struct Arg0201edf0*);

struct Inner3_0201f214 { unsigned int v[3]; };

struct Element0201f214 {
    short s0;
    short s2;
    short s4;
    unsigned short h6;
    struct Inner3_0201f214 mid8;
    unsigned short h14;
    unsigned short h16;
    unsigned short h18;
    unsigned short h1a;
    unsigned short h1c;
    unsigned short h1e;
};

struct List0201f214;

extern "C" void _Z27AppendCappedElement0201f214P12List0201f214P15Element0201f214(struct List0201f214*, struct Element0201f214*);

struct Alloc0201edf0;
struct Container0201edf0 {
    int f0;
    struct Alloc0201edf0* alloc;
    struct List0201f214* list;
    char pad[16];
};
extern struct Container0201edf0 data_020fdc40;

// USA: func_0201edf0
extern "C" ARM int func_0201edf0(struct Arg0201edf0* p, int n) {
    struct Element0201f214 e;
    float v2;
    float v3;
    float v4;
    float v7;
    float v8;
    float v10;
    float v9;
    float v11;
    float v12;
    unsigned char h6;
    int a0;
    int a1;
    int a4;

    a0 = _ZNK6Script9Parameter5ToIntEv(&p[0]);
    a1 = _ZNK6Script9Parameter5ToIntEv(&p[1]);
    v2 = _ZNK6Script9Parameter7ToFloatEv(&p[2]);
    v3 = _ZNK6Script9Parameter7ToFloatEv(&p[3]);
    v4 = _ZNK6Script9Parameter7ToFloatEv(&p[4]);
    a4 = _ZNK6Script9Parameter5ToIntEv(&p[5]);
    struct Arg0201edf0* a6 = &p[6];
    p += 7;
    (void)_ZNK6Script9Parameter8ToStringEv(a6);
    v7 = 1.0f;
    v8 = 1.0f;
    v9 = 1.0f;
    if (n > 10) {
        v7 = _ZNK6Script9Parameter7ToFloatEv(&p[0]);
        v8 = _ZNK6Script9Parameter7ToFloatEv(&p[1]);
        struct Arg0201edf0* z = &p[2];
        p += 3;
        v9 = _ZNK6Script9Parameter7ToFloatEv(z);
    }
    v10 = 0.0f;
    v11 = 0.0f;
    v12 = 0.0f;
    if (n > 7) {
        v10 = _ZNK6Script9Parameter7ToFloatEv(&p[0]);
        v11 = _ZNK6Script9Parameter7ToFloatEv(&p[1]);
        struct Arg0201edf0* z = &p[2];
        p += 3;
        v12 = _ZNK6Script9Parameter7ToFloatEv(z);
    }
    h6 = 0xf;
    if (n > 13) {
        h6 = _ZNK6Script9Parameter5ToIntEv(&p[0]) & 0xff;
        if (h6 & 0x10) {
            h6 &= ~0x10;
        } else {
            h6 |= 0x10;
        }
        if (h6 & 0x20)
            h6 = h6 & ~0x20;
        else
            h6 = h6 | 0x20;
    }
    e.s0 = a0;
    e.s2 = a1;
    e.s4 = a4;
    e.mid8.v[0] = (int)(4096.0f * v2);
    e.mid8.v[1] = (int)(4096.0f * v3);
    e.mid8.v[2] = (int)(4096.0f * v4);
    e.h14 = (int)(4096.0f * v10);
    e.h16 = (int)(4096.0f * v11);
    e.h18 = (int)(4096.0f * v12);
    e.h1a = (int)(4096.0f * v7);
    e.h1c = (int)(4096.0f * v8);
    e.h1e = (int)(4096.0f * v9);
    e.h6 = h6;
    _Z27AppendCappedElement0201f214P12List0201f214P15Element0201f214(data_020fdc40.list, &e);
    return 1;
}
