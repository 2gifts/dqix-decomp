#include <globaldefs.h>

extern int data_02109400;

#if defined(jpn)
enum { GLOBAL_WORD_OFFSET = 4 };
#else
enum { GLOBAL_WORD_OFFSET = 0 };
#endif

// USA: func_02094a00
ARM int GetGlobal02109400(void) {
    return *(int*)((char*)&data_02109400 + GLOBAL_WORD_OFFSET);
}
