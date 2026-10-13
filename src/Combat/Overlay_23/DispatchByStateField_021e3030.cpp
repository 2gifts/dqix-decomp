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

extern "C" FlaggedStateTransition* func_ov023_021e4e3c(FlaggedStateTransition* obj);
extern "C" void func_ov023_021e33b4(void* obj);
extern "C" void func_ov023_021e3db0(void* obj);
extern "C" void func_ov023_021e3f34(void* obj);

// USA: func_ov023_021e3030  (semantic: DispatchByStateField_021e3030)
extern "C" ARM void func_ov023_021e3030(FlaggedStateTransition* obj) {
    func_ov023_021e4e3c(obj);
    switch (obj->state) {
    case 0:
        func_ov023_021e33b4(obj);
        break;
    case 3:
        func_ov023_021e3db0(obj);
        break;
    case 1:
        func_ov023_021e3f34(obj);
        break;
    }
}
