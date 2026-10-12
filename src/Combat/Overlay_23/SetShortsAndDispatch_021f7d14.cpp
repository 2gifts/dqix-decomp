#include <globaldefs.h>

#if defined(jpn)
enum { X_OFFSET = 0x4c, Y_OFFSET = 0x4e, BUFFER_OFFSET = 0x24 };
#else
enum { X_OFFSET = 0x50, Y_OFFSET = 0x52, BUFFER_OFFSET = 0x28 };
#endif


#if defined(jpn)
#define SetShortsAndDispatch_021f7d14 func_ov023_021f720c
#endif

struct Obj0204b5e8;
int DispatchViaTable0204b5e8(struct Obj0204b5e8*, int, int);

struct SrcPair_021f7d14 { int a; int b; };

// USA: func_ov023_021f7d14
#if defined(jpn)
extern "C"
#endif
ARM int SetShortsAndDispatch_021f7d14(char* dest, struct SrcPair_021f7d14* src) {
    *(short*)(dest + X_OFFSET) = (short)(src->a >> 12);
    *(short*)(dest + Y_OFFSET) = (short)(src->b >> 12);
    return DispatchViaTable0204b5e8((struct Obj0204b5e8*)(dest + BUFFER_OFFSET), *(short*)(dest + X_OFFSET), *(short*)(dest + Y_OFFSET));
}
