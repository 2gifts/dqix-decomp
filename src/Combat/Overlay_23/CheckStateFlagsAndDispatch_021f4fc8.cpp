#include <globaldefs.h>

int GetGlobalField0x1c020421a0(void);

extern unsigned short data_02114e30;
extern char data_02114e54;

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern struct Obj0205eaa0 data_02108760;

// JPN: func_ov023_021f45a0
// USA: func_ov023_021f4fc8  (semantic: CheckStateFlagsAndDispatch_021f4fc8)
extern "C" ARM int func_ov023_021f4fc8(void) {
#if defined(jpn)
 enum {regionalOffset0=0x870, regionalOffset1=0x868};
#else
 enum {regionalOffset0=0x9a0, regionalOffset1=0x998};
#endif
    void* obj = (void*)GetGlobalField0x1c020421a0();
    int state = *(int*)((char*)obj + regionalOffset0);
    int flag = 0;
    if (state == 3 || state == 0) {
        if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x1)
            || TestFlag0SetAndFlag1Clear(&data_02114e30, 0x2)
            || TestFlag0SetAndFlag1Clear(&data_02114e30, 0x200)
            || TestFlag0SetAndFlag1Clear(&data_02114e30, 0x100)
            || TestFlag0SetAndFlag1Clear(&data_02114e30, 0x400)
            || TestFlag0SetAndFlag1Clear(&data_02114e30, 0x40)
            || TestFlag0SetAndFlag1Clear(&data_02114e30, 0x80)
            || TestFlag0SetAndFlag1Clear(&data_02114e30, 0x20)
            || TestFlag0SetAndFlag1Clear(&data_02114e30, 0x10)) {
            flag = 1;
        }
        if (*((unsigned char*)&data_02114e54 + 0x54)) flag = 1;
    }
    if (flag) {
        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        return 1;
    }
    int result = *(int*)((char*)obj + regionalOffset1) == 0;
    return result != 0;
}
