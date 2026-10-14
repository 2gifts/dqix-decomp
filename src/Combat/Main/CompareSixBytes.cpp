#include <globaldefs.h>

struct SixBytes {
    unsigned char b[6];
};

// USA: func_02011fb4
ARM int CompareSixBytes_02011fb4(unsigned char* p, struct SixBytes s) {
    int i;
    for (i = 0; i < 6; i++) {
        if (s.b[i] != p[i]) {
            return 0;
        }
    }
    return 1;
}
