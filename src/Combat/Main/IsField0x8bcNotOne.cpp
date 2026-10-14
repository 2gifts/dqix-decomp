#include <globaldefs.h>

// USA: func_020687a4
ARM int IsField0x8bcNotOne_020687a4(int unused, char* obj) {
    int value = *(int*)(obj + 0x8bc);
    return value != 1;
}
