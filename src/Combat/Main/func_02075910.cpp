#include <globaldefs.h>
#include "System/Memory.h"

struct Flag02108dfc {
    unsigned char flag;
    unsigned char pad1;
    unsigned short value;
    char* field4;
};

extern struct Flag02108dfc data_02108dfc;
extern unsigned char data_020f0dc8;

void SelectBattleContextMode2(int mode);
int GetBattleSysInnerField4();
void PrepareAndCommit020d0050(int value);
int GetCardReadManagerSharedStatus();
int ForwardWaitForField0x114Bit4ClearIsNull020d0834();
void EmptyDestructor020758a0(void* obj);
extern "C" void func_020d05ec(int a, int b, int c, void* d, int e, int f, int g, int h, int i);

// USA: func_02075910
extern "C" ARM int func_02075910(int a1, int a2, int a3, int a4) {
    if (data_02108dfc.field4) {
        if (a1 >= 0x8000) {
            a1 -= 0x8000;
        }
        VectorizedInvertedMemcpy(data_02108dfc.field4 + a1, (void*)a2, (unsigned int)a3);
        return 1;
    }

    if (data_020f0dc8 == 0) {
        return 0;
    }

    data_02108dfc.flag = 0;
    int result = 1;
    SelectBattleContextMode2((int)data_02108dfc.value);

    int b = ((GetBattleSysInnerField4() & 0xff) == 1);
    if (b) {
        func_020d05ec(a1, a2, a3, EmptyDestructor020758a0, 0, 1, 6, 1, 0);
    } else {
        b = ((GetBattleSysInnerField4() & 0xff) == 2);
        if (b) {
            func_020d05ec(a1, a2, a3, EmptyDestructor020758a0, 0, 1, 6, 1, 0);
        } else {
            b = ((GetBattleSysInnerField4() & 0xff) == 3);
            if (b) {
                func_020d05ec(a1, a2, a3, EmptyDestructor020758a0, 0, 1, 6, 1, 0);
            }
        }
    }

    if (a4) {
        if (GetCardReadManagerSharedStatus()) {
            result = 0;
        }
    } else {
        ForwardWaitForField0x114Bit4ClearIsNull020d0834();
        if (GetCardReadManagerSharedStatus()) {
            result = 0;
        }
        PrepareAndCommit020d0050((int)data_02108dfc.value);
        data_02108dfc.flag = 1;
    }

    return result;
}
