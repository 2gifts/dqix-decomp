#include <globaldefs.h>

// USA: func_02053604
ARM int GetIndexedEntryField0x178_02053604(signed char* obj) {
#if defined(jpn)
    signed char a = obj[0x170];
#else
    signed char a = obj[0x17c];
#endif
    if (a == 0) return -1;
#if defined(jpn)
    signed char b = obj[0x171];
#else
    signed char b = obj[0x17d];
#endif
    if (b >= 4) return -1;
    signed char* q = obj + b;
#if defined(jpn)
    return q[0x16c];
#else
    return q[0x178];
#endif
}
