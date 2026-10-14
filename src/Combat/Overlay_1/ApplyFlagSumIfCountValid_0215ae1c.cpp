#include <globaldefs.h>

int IsFlag0x800Set_0201241c(unsigned short* flags);
int IsFlag0x400Set_02012408(unsigned short* flags);
int IsFlag0x1Set_020123e0(unsigned short* flags);
int IsFlag0x2Set_020123f4(unsigned short* flags);

extern "C" void func_0201229c(unsigned short* flags);
extern "C" void func_ov017_021d6134(void* obj, int sum);

extern unsigned short data_02114e30;

// USA: func_ov001_0215ae1c
ARM int ApplyFlagSumIfCountValid_0215ae1c(void* obj, int count) {
    if (count < 1) return 0;
    func_0201229c(&data_02114e30);
    int f800 = IsFlag0x800Set_0201241c(&data_02114e30);
    int f400 = IsFlag0x400Set_02012408(&data_02114e30);
    int f1 = IsFlag0x1Set_020123e0(&data_02114e30);
    int f2 = IsFlag0x2Set_020123f4(&data_02114e30);
    func_ov017_021d6134(obj, f1 + f2 + f400 + f800);
    return 1;
}
