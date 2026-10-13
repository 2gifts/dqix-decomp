#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021e6de4 func_ov023_021e7148
#endif

struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
extern unsigned short data_02114e30;
int TestFlag0SetAndFlag1Clear(unsigned short*, int);

// USA: func_ov023_021e6de4  (semantic: CheckFlagOrActiveElement_021e6de4)
extern "C" ARM int func_ov023_021e6de4(char* obj) {
    int a = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
    int b = IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(obj +
#if defined(jpn)
        0x90
#else
        0xac
#endif
        ), 0x14);
    return (a | b) != 0;
}
