#include <globaldefs.h>

// USA: func_020687b8
ARM int IsField0x8c0NotOne_020687b8(int unused, char* obj) {
    int value = *(int*)(obj + 0x8c0);
    return value != 1;
}
