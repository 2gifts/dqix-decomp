#include <globaldefs.h>
#if defined(jpn)
enum { kRegione4 = 0xe0 };
#else
enum { kRegione4 = 0xe4 };
#endif

struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern unsigned short data_02114e30;

// USA: func_ov003_0216950c  (semantic: CheckFlagsAndActiveElement_0216950c)
extern "C" ARM int func_ov003_0216950c(void* objRaw) {
    char* obj = (char*)objRaw;
    int a = IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(obj + kRegione4), 0x14);
    int b = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x1);
    int c = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x400);
    if ((b | c | a) != 0) {
        return 1;
    }
    return 0;
}
