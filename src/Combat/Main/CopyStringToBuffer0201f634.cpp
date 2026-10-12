#include <globaldefs.h>

#if defined(jpn)
enum { FIELD_OFFSET = 0xc };
#else
enum { FIELD_OFFSET = 0x10 };
#endif
#include "std_library_functions.h"

struct Struct02030b7c;
extern "C" void* _ZNK6Script9Parameter8ToStringEv(Struct02030b7c* s);
extern int data_020fdc4c;

#if defined(jpn)
#define CopyStringToBuffer0201f634 func_0201f3c0
extern "C" ARM int func_0201f3c0(Struct02030b7c* s);
#endif

// USA: func_0201f634
ARM int CopyStringToBuffer0201f634(Struct02030b7c* s) {
    strcpy(*(char**)((char*)&data_020fdc4c + FIELD_OFFSET) + 0x548, (char*)_ZNK6Script9Parameter8ToStringEv(s));
    return 1;
}
