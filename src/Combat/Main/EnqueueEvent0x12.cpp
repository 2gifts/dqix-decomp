#include <globaldefs.h>

int RegisterCallbackEntry_020d2980(int, void(*)(int), int);
extern "C" int func_020d217c(int, int, int, int, int);

// USA: func_020d1f70
ARM int EnqueueEvent0x12_020d1f70(int a, int b, int c, int d, int e) {
    return func_020d217c(0x12, a, b, c, RegisterCallbackEntry_020d2980(a, (void(*)(int))d, e));
}
