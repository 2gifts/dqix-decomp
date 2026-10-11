#include <globaldefs.h>

#if defined(jpn)
enum { tableOffset = 0x78fa, counterOffset = 0x57c8, stateOffset = 0xe28, resetOffset = 0x78fc };
#else
enum { tableOffset = 0x770a, counterOffset = 0x55d8, stateOffset = 0xeac, resetOffset = 0x770c };
#endif

// USA: func_ov025_021def30
ARM void IncrementCounterAndReset_021def30(unsigned char* obj) {
    if (*(unsigned short*)(obj+tableOffset) == 0) {
        *(int*)(obj+counterOffset) += 1;
    }
    *(int*)(obj+stateOffset) = 1;
    *(int*)(obj+resetOffset) = 0;
}
