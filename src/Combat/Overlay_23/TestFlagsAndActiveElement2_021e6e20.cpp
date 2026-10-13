#include <globaldefs.h>

#if defined(jpn)
#define TestFlagsAndActiveElement2_021e6e20 func_ov023_021e7184
#endif

extern unsigned short data_02114e30;
int TestFlag0SetAndFlag1Clear(unsigned short* input, int mask);

struct Struct_0205d81c {
    char unknown_000[0xb0];
    unsigned char selected;
};

extern "C" int func_0205d97c(Struct_0205d81c* elements);

struct Obj021e6e20 {
#if defined(jpn)
    char unknown_000[0x90];
#else
    char unknown_000[0xac];
#endif
    Struct_0205d81c elements;
};

#if defined(jpn)
extern "C"
#endif
ARM int TestFlagsAndActiveElement2_021e6e20(Obj021e6e20* selection) {
    int inputTriggered = TestFlag0SetAndFlag1Clear(&data_02114e30, 2);
    int touchOutsideSelection = func_0205d97c(&selection->elements) == 2;
    return (inputTriggered | touchOutsideSelection) != 0;
}
