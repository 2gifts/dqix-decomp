#include <globaldefs.h>
#if defined(jpn)
enum { kRegion98 = 0xb0 };
#else
enum { kRegion98 = 0x98 };
#endif

struct Obj_0205da38;
extern int IsActiveElementFlag2Set0205da38(struct Obj_0205da38*);
typedef int (*Fn2_0215dcb8)(void*, int);
extern unsigned short data_02114e30;
int TestFlag0SetAndFlag1Clear(unsigned short*, int);

// JPN: func_ov003_0215f000
// USA: func_ov003_0215dcb8  (semantic: CheckActiveOrFlags_0215dcb8)
extern "C" ARM int func_ov003_0215dcb8(char* obj) {
    int a = ((Fn2_0215dcb8)(void*)&IsActiveElementFlag2Set0205da38)(obj + kRegion98, 0x14);
    int b = TestFlag0SetAndFlag1Clear(&data_02114e30, 1);
    int c = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x400);
    return (a | (b | c)) != 0;
}
