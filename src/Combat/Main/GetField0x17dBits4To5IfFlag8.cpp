#include <globaldefs.h>

// USA: func_020795cc
ARM int GetField0x17dBits4To5IfFlag8_020795cc(unsigned char* obj) {
    int v = obj[0x17d];
    if (v & 8) {
        return (unsigned char)(v >> 4) & 3;
    }
    return -1;
}
