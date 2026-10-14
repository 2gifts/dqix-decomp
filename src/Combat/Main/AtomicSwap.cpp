#include <globaldefs.h>

// USA: _Z19AtomicSwap_020ca7e0iPi
ARM int AtomicSwap_020ca7e0(int value, int* addr) {
    asm {
        swp value, value, [addr]
    }
    return value;
}
