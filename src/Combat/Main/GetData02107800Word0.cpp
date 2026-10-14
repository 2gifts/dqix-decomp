#include <globaldefs.h>

extern char data_02107800;

#if defined(jpn)
enum { GLOBAL_WORD_OFFSET = 0x30 };
#else
enum { GLOBAL_WORD_OFFSET = 0 };
#endif

// USA: func_020429d4
ARM int GetData02107800Word0_020429d4(void) {
    return *(int*)(&data_02107800 + GLOBAL_WORD_OFFSET);
}
