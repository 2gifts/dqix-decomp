#include <globaldefs.h>

int GetCharBlock_020b01a4(void*, void**);

// USA: func_0205a1f0
ARM int ValidateResourceLookup0205a1f0(void* a, void* b, int c) {
    if (a == NULL) return 1;
    if (b == NULL) return 1;
    if (c == 0) return 1;
    if (GetCharBlock_020b01a4(b, (void**)a) == 0) return 1;
    return 0;
}
