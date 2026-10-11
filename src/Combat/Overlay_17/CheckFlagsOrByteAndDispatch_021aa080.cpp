// JPN: func_ov017_021aa8f0
#if defined(jpn)
enum { RegionOffset9a0 = 0x870 };
#else
enum { RegionOffset9a0 = 0x9a0 };
#endif

#include <globaldefs.h>

extern int data_02107800;
extern unsigned short data_02114e30;
extern unsigned char data_02114e54;
struct Obj0205eaa0;
extern struct Obj0205eaa0 data_02108760;

int GetGlobalField0x1c020421a0();
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);

// USA: func_ov017_021aa080  (semantic: CheckFlagsOrByteAndDispatch_021aa080)
extern "C" ARM int func_ov017_021aa080() {
    int base = GetGlobalField0x1c020421a0();
    int field = *(int*)(base + RegionOffset9a0);
    int flag = 0;
    if (field == 3 || field == 0) {
        if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x1) ||
            TestFlag0SetAndFlag1Clear(&data_02114e30, 0x200) ||
            TestFlag0SetAndFlag1Clear(&data_02114e30, 0x100) ||
            TestFlag0SetAndFlag1Clear(&data_02114e30, 0x40) ||
            TestFlag0SetAndFlag1Clear(&data_02114e30, 0x80) ||
            TestFlag0SetAndFlag1Clear(&data_02114e30, 0x20) ||
            TestFlag0SetAndFlag1Clear(&data_02114e30, 0x10)) {
            flag = 1;
        }
        if (*(unsigned char*)(&data_02114e54 + 0x54) != 0) {
            flag = 1;
        }
    }
    if (flag == 0) {
        return 0;
    }
    DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
    return 1;
}
