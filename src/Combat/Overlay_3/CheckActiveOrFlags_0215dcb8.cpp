#include <globaldefs.h>
#if defined(jpn)
enum { kRegion98 = 0xb0 };
#else
enum { kRegion98 = 0x98 };
#endif

struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
extern unsigned short data_02114e30;
int TestFlag0SetAndFlag1Clear(unsigned short*, int);

// USA: func_ov003_0215dcb8  (semantic: CheckActiveOrFlags_0215dcb8)
extern "C" ARM int func_ov003_0215dcb8(char* obj) {
    int a = IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(obj + kRegion98), 0x14);
    int b = TestFlag0SetAndFlag1Clear(&data_02114e30, 1);
    int c = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x400);
    return (a | (b | c)) != 0;
}
