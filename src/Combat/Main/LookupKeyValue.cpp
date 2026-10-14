#include <globaldefs.h>

extern short data_020e6dc2;
extern signed char data_020e6dc0;

// USA: func_02012f24
ARM int LookupKeyValue_02012f24(int key) {
    short* keys = &data_020e6dc2;
    signed char* vals = &data_020e6dc0;
    unsigned int i;
    for (i = 0; i < 1; i++, keys++, vals++) {
        if (*keys == key) return *vals;
    }
    return -1;
}
