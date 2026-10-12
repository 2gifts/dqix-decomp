#include <globaldefs.h>

#if defined(jpn)
enum { kElementListOffset = 0x90 };
#else
enum { kElementListOffset = 0xac };
#endif


#if defined(jpn)
#define TestFlagsAndActiveElement2_021e6e20 func_ov023_021e7184
#endif

extern unsigned short data_02114e30;

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern "C" int func_0205d97c(void*);

struct Obj021e6e20 { char pad[kElementListOffset]; };

// USA: func_ov023_021e6e20
#if defined(jpn)
extern "C"
#endif
ARM int TestFlagsAndActiveElement2_021e6e20(struct Obj021e6e20* obj) {
    int a = TestFlag0SetAndFlag1Clear(&data_02114e30, 2);
    int b = func_0205d97c((char*)obj + kElementListOffset) == 2;
    return (a | b) != 0;
}
