#include <globaldefs.h>

extern "C" int func_020d5fd0(int, int, int);
void SetField0x48UnlessState9Or10_0202c848(int arg);
extern int data_02102be0;
extern int data_02101980;

// USA: func_0202dcd4
ARM int CheckDispatchAndUpdateField0x48_0202dcd4(int arg) {
    int r = func_020d5fd0((int)&data_02102be0, arg, (int)&data_02101980);
    if (r == 7) return 1;
    if (r == 5) {
        SetField0x48UnlessState9Or10_0202c848(r);
        return 0;
    }
    if (r == 0) return 1;
    SetField0x48UnlessState9Or10_0202c848(r);
    return 0;
}
