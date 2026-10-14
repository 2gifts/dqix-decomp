#include <globaldefs.h>
#include "System/Memory.h"

void SelectBattleContextMode2(int mode);
int GetBattleSysInnerField4();
void PrepareAndCommit020d0050(int value);
void EmptyDestructor020758a4(void* obj);
int GetCardReadManagerSharedStatus();
int ForwardWaitForField0x114Bit4ClearIsNull020d0834();
extern "C" void func_020d05ec(const void* src, int offset, unsigned int length, void (*proc)(void*), int a4, int a5, int a6, int a7, int a8);

struct Flag02108dfc {
    unsigned char flag;
    unsigned char pad1;
    unsigned short value;
    void* base;
};

extern struct Flag02108dfc data_02108dfc;
extern unsigned char data_020f0dc8;

// USA: func_02075acc
extern "C" ARM int func_02075acc(int offset, void* src, unsigned int length, int arg3) {
    int result;
    int isOne;
    int isTwo;
    int isThree;

    if (data_02108dfc.base != 0) {
        if (offset >= 0x8000) {
            offset -= 0x8000;
        }
        VectorizedInvertedMemcpy(src, (void*)((unsigned char*)data_02108dfc.base + offset), length);
        return 1;
    }

    if (data_020f0dc8 == 0) {
        return 0;
    }

    data_02108dfc.flag = 0;
    result = 1;
    SelectBattleContextMode2((int)data_02108dfc.value);

    isOne = (GetBattleSysInnerField4() & 0xff) == 1;
    if (isOne) {
        func_020d05ec(src, offset, length, EmptyDestructor020758a4, 0, 1, 8, 10, 2);
    } else {
        isTwo = (GetBattleSysInnerField4() & 0xff) == 2;
        if (isTwo) {
            func_020d05ec(src, offset, length, EmptyDestructor020758a4, 0, 1, 7, 10, 2);
        } else {
            isThree = (GetBattleSysInnerField4() & 0xff) == 3;
            if (isThree) {
                func_020d05ec(src, offset, length, EmptyDestructor020758a4, 0, 1, 8, 10, 2);
            }
        }
    }

    if (arg3 != 0) {
        if (GetCardReadManagerSharedStatus() != 0) {
            result = 0;
        }
    } else {
        ForwardWaitForField0x114Bit4ClearIsNull020d0834();
        if (GetCardReadManagerSharedStatus() != 0) {
            result = 0;
        }
        PrepareAndCommit020d0050((int)data_02108dfc.value);
        data_02108dfc.flag = 1;
    }

    return result;
}
