#include <globaldefs.h>
#if defined(jpn)
enum { kRegion98 = 0xb0 };
#else
enum { kRegion98 = 0x98 };
#endif

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern "C" int func_0205d97c(void* obj);

extern unsigned short data_02114e30;

// JPN: func_ov003_0215f048
// USA: func_ov003_0215dd00
ARM int IsFlagStateOrField98Eq2_0215dd00(char* self) {
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2)) {
        return 1;
    }
    return func_0205d97c(self + kRegion98) == 2;
}
