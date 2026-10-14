#include <globaldefs.h>

// USA: func_02083be8
ARM int IsAnyByteSetInArray0x910_02083be8(unsigned char* obj) {
    int i;
    for (i = 0; i < 9; i++) {
#if defined(jpn)
        if ((obj + i)[0x878] != 0) {
#else
        if ((obj + i)[0x910] != 0) {
#endif
            return 1;
        }
    }
    return 0;
}
