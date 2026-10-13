#include <globaldefs.h>
#include "System/Memory.h"

void ClearRegion02093980(char* storage);

struct NamedRequestRecord {
#if defined(jpn)
    char name[11];
    unsigned char unknownB;
#else
    char name[48];
#endif
    short requestId;
    signed char partySlot;
    unsigned char flags;
};

struct Ctx0209459c {
    NamedRequestRecord active[8];
    NamedRequestRecord saved[8];
#if defined(jpn)
    char unknown100[0x13b - 0x100];
#else
    char unknown340[0x3cb - 0x340];
#endif
    signed char count;
    signed char savedCount;
    unsigned char flags;
};

// JPN: func_02094ea0
// USA: func_020945ac  (semantic: SlideAndClearEntries_020945ac)
extern "C" ARM void func_020945ac(Ctx0209459c* queue) {
    if (queue->count <= 0) {
        return;
    }
    int last = queue->count - 1;
    for (int i = 0; i < last; i++) {
        VectorizedInvertedMemcpy(&queue->active[i + 1], &queue->active[i], sizeof(NamedRequestRecord));
    }
    for (int i = last; i < 8; i++) {
        ClearRegion02093980((char*)&queue->active[i]);
    }
    if (queue->count > 0) {
        queue->count = queue->count - 1;
    }
    if (queue->count > 0) {
        queue->flags = (queue->flags | 1) & ~4;
    } else {
        queue->flags = queue->flags & ~4;
    }
}
