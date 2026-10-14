#include <globaldefs.h>

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c*);

struct W12 {
    unsigned int a : 5;
    unsigned int b : 7;
    unsigned int c : 8;
    unsigned int d : 5;
    unsigned int e : 7;
};
union U12 { struct W12 b; unsigned int raw; unsigned int vraw; };
struct Record12 {
    unsigned short id : 11;
    unsigned short slot : 5;
    unsigned short f2;
    union U12 u;
    unsigned short f8;
    unsigned short fa;
};

struct RecordList0209a4f0;
void AppendRecord12Capped0209a4f0(struct RecordList0209a4f0* list, struct Record12* src);

extern struct RecordList0209a4f0* data_02109ba4;

static inline int PI(char* p, int off) { struct Variant02030b0c* q = (struct Variant02030b0c*)(p + off); int r = _ZNK6Script9Parameter5ToIntEv(q); return r; }

// USA: func_0209a104
extern "C" ARM int func_0209a104(char* v) {
    struct Record12 rec;
    unsigned int _t;

    rec.id = PI(v, 0);
    rec.u.b.a = PI(v, 8);
    rec.u.b.b = PI(v, 0x10);
    rec.f2 = PI(v, 0x18);
    rec.slot = PI(v, 0x20);
    _t = (unsigned int)PI(v, 0x28); _t <<= 24; rec.u.raw &= ~0xff000u; rec.u.raw |= _t >> 12;
    rec.f8 = PI(v, 0x30);
    rec.fa = PI(v, 0x38);
    _t = (unsigned int)PI(v, 0x40) << 27; rec.u.raw &= ~0x1f00000u; rec.u.raw |= _t >> 7;
    rec.u.vraw = rec.u.raw & 0x01ffffffu;

    AppendRecord12Capped0209a4f0(data_02109ba4, &rec);
    return 1;
}
