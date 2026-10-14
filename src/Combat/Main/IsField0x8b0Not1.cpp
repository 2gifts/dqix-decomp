#include <globaldefs.h>

// USA: func_02068768
ARM int IsField0x8b0Not1_02068768(int unused, char* obj) {
    return *(int*)(obj + 0x8b0) != 1;
}
