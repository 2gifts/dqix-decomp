#include <globaldefs.h>

#if defined(jpn)
enum { kFirstHalfwordOffset = 0x3a };
#else
enum { kFirstHalfwordOffset = 0x3c };
#endif


#if defined(jpn)
#define SetThreeFields_021fb23c func_ov023_021fa5dc
#endif

struct Obj021fb23c {
    char pad[kFirstHalfwordOffset];
    short a;
    short b;
    short c;
};

// USA: func_ov023_021fb23c
#if defined(jpn)
extern "C"
#endif
ARM void SetThreeFields_021fb23c(struct Obj021fb23c *obj, short a, short b, short c) {
    obj->a = a;
    obj->b = b;
    obj->c = c;
}
