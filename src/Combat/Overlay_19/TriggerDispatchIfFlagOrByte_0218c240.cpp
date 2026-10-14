#include <globaldefs.h>

extern int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);

struct Obj0205eaa0;
extern void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);

extern unsigned short data_02114e30;
extern char data_02114e54;
extern struct Obj0205eaa0 data_02108760;

// USA: func_ov019_0218c240
ARM int TriggerDispatchIfFlagOrByte_0218c240(void) {
    if (!TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x7f3)) {
        unsigned char v = *((unsigned char*)&data_02114e54 + 0x55);
        if (v == 0) return 0;
    }
    DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
    return 1;
}
