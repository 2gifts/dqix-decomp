#include <globaldefs.h>

// USA: func_02068bac
ARM int IsFieldNotZeroOrOne_02068bac(int unused, char* obj) {
    int value = *(int*)(obj + 0x8b8);
    return value != 0 && value != 1;
}
