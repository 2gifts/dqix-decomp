#include <globaldefs.h>

// USA: func_0202e7d4
ARM void ReadFields0x70To0x78_0202e7d4(unsigned char* obj, int* a, int* b, int* c) {
    *a = *(int*)(obj + 0x70);
    *b = *(int*)(obj + 0x74);
    *c = *(int*)(obj + 0x78);
}
