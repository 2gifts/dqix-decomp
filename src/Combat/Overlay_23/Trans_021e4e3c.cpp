#include <globaldefs.h>

#if defined(jpn)
enum { kResetFlagOffset = 0x4e0, kFlagsOffset = 0x56c };
#else
enum { kResetFlagOffset = 0x4e4, kFlagsOffset = 0x634 };
#endif

struct FlaggedStateTransition {
    unsigned char unknown[kResetFlagOffset];
    unsigned char resetFlag;
    unsigned char unknownAfterReset;
    signed char state;
    signed char previousState;
    unsigned char unknownAfterState[kFlagsOffset - kResetFlagOffset - 4];
    unsigned short flags;
    unsigned char counter;
};

// USA: func_ov023_021e4e3c
extern "C" ARM FlaggedStateTransition* func_ov023_021e4e3c(FlaggedStateTransition* self) {
    if (!(self->flags & 0x1000)) {
        return self;
    }
    if (self->flags & 0x2000) {
        return self;
    }
    if (self->counter != 0) {
        return self;
    }
    self->previousState = self->state;
    self->state = 1;
    self->resetFlag = 0;
    ++self->counter;
    return self;
}
