#include <globaldefs.h>
#include "Graphics/Vector.h"

#if defined(jpn)
enum { X_OFFSET = 0x4c, Y_OFFSET = 0x4e, BUFFER_OFFSET = 0x24 };
#else
enum { X_OFFSET = 0x50, Y_OFFSET = 0x52, BUFFER_OFFSET = 0x28 };
#endif

struct Obj0204b5e8;
int DispatchViaTable0204b5e8(struct Obj0204b5e8*, int, int);

struct SrcPair_021f7d14 { fix32_t x; fix32_t y; };

struct PositionedElement_021f7d14 {
    unsigned char unknown0[BUFFER_OFFSET];
    unsigned char displayState[X_OFFSET - BUFFER_OFFSET];
    short x;
    short y;
};

// USA: func_ov023_021f7d14
ARM int SetShortsAndDispatch_021f7d14(char* element, struct SrcPair_021f7d14* position) {
    PositionedElement_021f7d14* display = (PositionedElement_021f7d14*)element;
    display->x = (short)(position->x >> 12);
    display->y = (short)(position->y >> 12);
    return DispatchViaTable0204b5e8((Obj0204b5e8*)display->displayState, display->x, display->y);
}
