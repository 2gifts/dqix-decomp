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

// USA: func_ov023_021e338c
ARM void SetFlagt_021e338c_021e338c(char* stateStorage) {
    FlaggedStateTransition* transition = (FlaggedStateTransition*)stateStorage;
    transition->flags |= 0x1000;
}
