#include <globaldefs.h>

// USA: func_02068bc4
ARM int IsField0x8bcNotZeroOrOne_02068bc4(int unused, char* obj) {
    int value = *(int*)(obj + 0x8bc);
    return value != 0 && value != 1;
}
