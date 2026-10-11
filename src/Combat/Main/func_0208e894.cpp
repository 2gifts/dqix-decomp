#include <globaldefs.h>

#if defined(jpn)
enum { PackedEntriesLow = 0x27c, PackedEntriesHigh = 0x5800 };
#else
enum { PackedEntriesLow = 0xdc, PackedEntriesHigh = 0x5c00 };
#endif

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c*);
extern "C" int _s32_div_f(int a, int b);
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void* func_0208e0a8(void);

extern int data_02108fe4;

struct Entry02108ff4 {
    unsigned short a;
    unsigned char b;
    unsigned char c;
};

struct Bits0208e894 {
    unsigned int f0 : 9;
    unsigned int f1 : 4;
    unsigned int f2 : 4;
    unsigned int f3 : 8;
    unsigned int f4 : 4;
    unsigned int f5 : 2;
    unsigned int f6 : 1;
};

// USA: func_0208e894
// JPN: func_0208e894
extern "C" ARM int func_0208e894(char* v) {
    struct Bits0208e894* w;
    struct Entry02108ff4* tbl;
    int idx = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)v);
    int p10 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(v + 0x10));
    int k = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(v + 0x20));
    int p28 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(v + 0x28));
    int p30 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(v + 0x30));
    int p38 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(v + 0x38));
    w = (struct Bits0208e894*)((char*)_ZN9GameState11GetInstanceEv() + PackedEntriesLow + PackedEntriesHigh);
    if (k == 8) {
        w[idx].f0 = 0;
        w[idx].f1 = p38;
        w[idx].f3 = 0;
        w[idx].f4 = _s32_div_f(p28, 30);
        w[idx].f2 = p30;
        w[idx].f5 = p10;
        w[idx].f6 = 1;
    } else {
        tbl = (struct Entry02108ff4*)((char*)func_0208e0a8() + 0x10);
        w[idx].f0 = 0;
        w[idx].f1 = tbl[k].c;
        w[idx].f3 = 0;
        w[idx].f4 = _s32_div_f(tbl[k].a, 30);
        w[idx].f2 = tbl[k].b;
        w[idx].f5 = p10;
        w[idx].f6 = 1;
    }
    return 1;
}
