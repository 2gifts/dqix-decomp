#include <globaldefs.h>
#if defined(jpn)
enum { kRegione4 = 0xe0 };
#else
enum { kRegione4 = 0xe4 };
#endif

extern unsigned short data_02114e30;
int TestFlag0SetAndFlag1Clear(unsigned short*, int);
extern "C" int func_0205d97c(void*);

// JPN: func_ov003_0216937c
// USA: func_ov003_02169554
ARM int CheckFlagOrThreshold_02169554(void* obj) {
    int a = TestFlag0SetAndFlag1Clear(&data_02114e30, 2);
    int b = func_0205d97c((char*)obj + kRegione4) == 2;
    return (a | b) != 0;
}
