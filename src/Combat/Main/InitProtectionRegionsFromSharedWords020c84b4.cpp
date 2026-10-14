#include <globaldefs.h>

extern "C" int func_020c8548(int);
extern "C" int func_020c862c(int);
void SetSharedWordDc4_020c86d4(int index, int value);
void SetSharedWordDa0_020c86e8(int index, int value);
unsigned int SetData020f2284_020c7dcc();
void SetProtectionRegion1_020c8a2c(unsigned int value);
void SetProtectionRegion2_020c8a34(unsigned int value);

extern int data_0211155c;

// USA: func_020c84b4  (semantic: InitProtectionRegionsFromSharedWords020c84b4)
extern "C" ARM void func_020c84b4(void) {
    int v1 = func_020c8548(2);
    SetSharedWordDc4_020c86d4(2, v1);
    int v2 = func_020c862c(2);
    SetSharedWordDa0_020c86e8(2, v2);

    int flag = *(int*)((char*)&data_0211155c + 0x4);
    if (flag != 0) {
        unsigned int r = SetData020f2284_020c7dcc();
        if ((r & 0x3) != 0x1) {
            return;
        }
    }
    SetProtectionRegion1_020c8a2c(0x200002b);
    SetProtectionRegion2_020c8a34(0x23e0021);
}
