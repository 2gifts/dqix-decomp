#include <globaldefs.h>

extern "C" int func_020c8548(int);
extern "C" int func_020c862c(int);
void SetSharedWordDc4_020c86d4(int index, int value);
void SetSharedWordDa0_020c86e8(int index, int value);

extern int data_0211155c;

// USA: func_020c83b0  (semantic: InitSharedWordsForAllSlots_020c83b0)
extern "C" ARM void func_020c83b0(void) {
    if (data_0211155c != 0) {
        return;
    }
    data_0211155c = 1;

    int v0a = func_020c8548(0);
    SetSharedWordDc4_020c86d4(0, v0a);
    int v0b = func_020c862c(0);
    SetSharedWordDa0_020c86e8(0, v0b);

    SetSharedWordDa0_020c86e8(2, 0);
    SetSharedWordDc4_020c86d4(2, 0);

    int v3a = func_020c8548(3);
    SetSharedWordDc4_020c86d4(3, v3a);
    int v3b = func_020c862c(3);
    SetSharedWordDa0_020c86e8(3, v3b);

    int v4a = func_020c8548(4);
    SetSharedWordDc4_020c86d4(4, v4a);
    int v4b = func_020c862c(4);
    SetSharedWordDa0_020c86e8(4, v4b);

    int v5a = func_020c8548(5);
    SetSharedWordDc4_020c86d4(5, v5a);
    int v5b = func_020c862c(5);
    SetSharedWordDa0_020c86e8(5, v5b);

    int v6a = func_020c8548(6);
    SetSharedWordDc4_020c86d4(6, v6a);
    int v6b = func_020c862c(6);
    SetSharedWordDa0_020c86e8(6, v6b);
}
