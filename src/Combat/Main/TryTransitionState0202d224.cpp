#include <globaldefs.h>

extern char data_021015a0;
extern char data_021016e0;
extern char data_02101614;

extern "C" void func_0202d2a4();
extern "C" int func_020d54d0(void* fn, void* a, void* b, int c, unsigned short flag);
void SetField0x48UnlessState9Or10_0202c848(int arg);

// USA: func_0202d224
ARM int TryTransitionState0202d224(void) {
    int state = *(int*)(&data_021015a0 + 0x10);
    if (!(state != 4 && state != 6 && state != 5))
        return 1;
    *(int*)(&data_021015a0 + 0x10) = 3;
    int flag = (*(int*)(&data_021015a0 + 0x30) != 0);
    int r = func_020d54d0((void*)func_0202d2a4, &data_021016e0, &data_02101614, 1, flag);
    if (r == 2)
        return 1;
    SetField0x48UnlessState9Or10_0202c848(r);
    return 0;
}
