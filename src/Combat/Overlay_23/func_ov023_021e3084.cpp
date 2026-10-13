#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021e3084 func_ov023_021e33dc
#endif
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "System/Graphics.h"

int GetField4340_021bdbe4(unsigned char* base);
int GetField433c_021bdbd8(unsigned char* base);
extern "C" void func_ov023_021e5628(void* addr, void* pair);

struct Pair021e3084 { void* firstAttachment; void* secondAttachment; };

#if defined(jpn)
enum { PairCounterOffset = 0x130, PairFlagsOffset = 0x56c, PairDestinationOffset = 0x124 };
#else
enum { PairCounterOffset = 0x134, PairFlagsOffset = 0x634, PairDestinationOffset = 0x128 };
#endif

struct TimedDrawState {
    unsigned char unknown0[PairDestinationOffset];
    void* drawObject;
    unsigned char unknownAfterDrawObject[PairCounterOffset - PairDestinationOffset - sizeof(void*)];
    int remainingUpdates;
    unsigned char unknownAfterCounter[PairFlagsOffset - PairCounterOffset - sizeof(int)];
    unsigned short flags;
};

// USA: func_ov023_021e3084  (semantic: DecrementCounterAndDispatchPair_021e3084)
extern "C" ARM void func_ov023_021e3084(void* obj) {
    TimedDrawState* state = (TimedDrawState*)obj;
    GameState::GetInstance();

    if (state->remainingUpdates > 0) {
        if (--state->remainingUpdates == 0) {
            state->flags |= 8;
        }
    }

    if ((state->flags & 0x20) == 0) {
        return;
    }

    GameResources* resources = func_ov017_0218b5b0();
    Pair021e3084 attachments;
    if (resources == NULL) {
        attachments.secondAttachment = NULL;
        attachments.firstAttachment = NULL;
    } else {
        attachments.secondAttachment = (void*)GetField4340_021bdbe4((unsigned char*)resources);
        attachments.firstAttachment = (void*)GetField433c_021bdbd8((unsigned char*)resources);
    }

    if (state->drawObject != NULL) {
        GXFIFO_MATRIX_PUSH = 0;
        func_ov023_021e5628(state->drawObject, &attachments);
        GXFIFO_MATRIX_POP = 1;
    }
}
