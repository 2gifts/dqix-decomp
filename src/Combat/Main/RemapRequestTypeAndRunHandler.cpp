#include <globaldefs.h>

extern "C" int func_020ce4e8(int a, int b, int c, void* callback, int* out);

// USA: func_020ce5b0
ARM int RemapRequestTypeAndRunHandler_020ce5b0(int a, void (*callback)(void), int* out) {
    int mapped;
    switch (a) {
        case 1: mapped = 1; break;
        case 3: mapped = 2; break;
        case 2: mapped = 3; break;
        default: mapped = 0; break;
    }
    if (mapped == 0) {
        return 0xffff;
    }
    return func_020ce4e8(mapped, 0, 0, (void*)callback, out);
}
