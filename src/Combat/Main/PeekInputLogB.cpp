#include <globaldefs.h>

extern unsigned char data_02109da4[];
extern signed char data_02109da6[];

// USA: func_020a1fa8
ARM int PeekInputLogB(void) {
    const unsigned char* counts = data_02109da4;
    if (counts[1] != 0) {
        return data_02109da6[data_02109da4[1] - 1];
    }
    return -1;
}
