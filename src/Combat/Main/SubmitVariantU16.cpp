#include <globaldefs.h>

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

extern "C" void func_020724f4(int a, int b, int c);

struct Data02108da8 {
    int f0;
    int f4;
};

extern struct Data02108da8 data_02108da8;

#if defined(jpn)
#define SubmitVariantU16 func_020733d8
extern "C" ARM int func_020733d8(struct Variant02030b0c* p);
#endif

// USA: func_0207236c
ARM int SubmitVariantU16(struct Variant02030b0c* p) {
    func_020724f4(data_02108da8.f4, data_02108da8.f0, (unsigned short)_ZNK6Script9Parameter5ToIntEv(p));
    return 1;
}
