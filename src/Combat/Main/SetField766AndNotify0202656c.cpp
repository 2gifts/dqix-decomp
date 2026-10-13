#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
#define data_020ef6d0 data_020ef5c0
#endif
extern char data_020ef6d0;

struct Obj0202656c;

// KEEP-NAME
// USA: func_0202656c
// JPN: func_02025ed4
ARM void SetField766AndNotify0202656c(struct Obj0202656c* p, int val) {
#if defined(jpn)
    enum { ValueOffset = 0x6ba, TextOffset = 0x680 };
#else
    enum { ValueOffset = 0x766, TextOffset = 0x6ec };
#endif
    unsigned char* obj = (unsigned char*)p;
    *(unsigned short*)(obj + ValueOffset) = val;
    if (*(unsigned short*)(obj + ValueOffset) == 0) return;
    if (*(unsigned short*)(obj + ValueOffset) >= 1000) return;
    sprintf((char*)(obj + TextOffset), &data_020ef6d0, val);
}
