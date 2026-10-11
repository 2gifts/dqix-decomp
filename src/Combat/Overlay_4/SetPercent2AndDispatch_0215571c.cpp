#if defined(jpn)
#define R(j,u) (j)
#define func_ov023_021f64a8 func_ov023_021f5a1c
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" int _s32_div_f(int a, int b);
extern char* data_ov004_021707c4;
extern "C" void func_ov023_021f64a8(void* a, int b, int c, int d);
int DispatchNodeIfState6_021f6680(void* obj, int id);

// USA: func_ov004_0215571c
ARM int SetPercent2AndDispatch_0215571c(void* a) {
    short cur = *(short*)(data_ov004_021707c4 + 0xe);
    short max = *(short*)(data_ov004_021707c4 + 0xc);
    int percent = _s32_div_f(cur * 100, max);
    percent = (short)percent;
    if (percent == 0 && cur == 0) percent = 0;
    if (percent == 0 && cur != 0) percent = 1;
    if (percent > 100) percent = 100;
    if (percent < 0) percent = 0;

    func_ov023_021f64a8(a, 0x13, percent, 0xf);
    func_ov023_021f64a8(a, 0x14, cur, 0xf);
    DispatchNodeIfState6_021f6680(a, 0x10);
    return 0;
}
