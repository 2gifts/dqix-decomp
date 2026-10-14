#include <globaldefs.h>

extern int data_020e9200[][4];

// USA: func_020b11ac
ARM int LookupWord2D_020b11ac(unsigned char *p) {
    return data_020e9200[p[1]][p[0]];
}
