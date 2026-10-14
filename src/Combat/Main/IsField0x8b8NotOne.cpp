#include <globaldefs.h>

// USA: func_02068790
ARM int IsField0x8b8NotOne_02068790(int unused, char* obj) {
    int value = *(int*)(obj + 0x8b8);
    return value != 1;
}
