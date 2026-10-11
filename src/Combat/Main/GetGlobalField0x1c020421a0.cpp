#include <globaldefs.h>

extern int data_02107800;

#if defined(jpn)
enum { GLOBAL_FIELD_OFFSET = 0x38 };
#else
enum { GLOBAL_FIELD_OFFSET = 0x1c };
#endif

// USA: func_020421a0
ARM int GetGlobalField0x1c020421a0() {
    return *(int*)((char*)&data_02107800 + GLOBAL_FIELD_OFFSET);
}
