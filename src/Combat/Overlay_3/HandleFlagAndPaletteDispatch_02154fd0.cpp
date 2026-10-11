#include <globaldefs.h>
#if defined(jpn)
enum { kRegion1f8 = 0x1f4 };
enum { kRegion204 = 0x200 };
#else
enum { kRegion1f8 = 0x1f8 };
enum { kRegion204 = 0x204 };
#endif

void CallDispatchIfFlagSet_021eb4f4(char* obj);

struct Cont0207fd88;
void CallFunc0204b088OverList0x2c(struct Cont0207fd88* obj);

struct SelfState020e2834;
void SetYesNoButtonPalette020e2834(struct SelfState020e2834* self);

// JPN: func_ov003_021566b8
// USA: func_ov003_02154fd0  (semantic: HandleFlagAndPaletteDispatch_02154fd0)
extern "C" ARM void func_ov003_02154fd0(char* obj) {
    if (*(unsigned char*)(obj + kRegion1f8) == 0) return;
    char* p204 = *(char**)(obj + kRegion204);
    if (p204 != 0) {
        CallDispatchIfFlagSet_021eb4f4(p204);
    } else {
        struct Cont0207fd88* p18 = *(struct Cont0207fd88**)(obj + 0x18);
        if (p18 != 0) {
            CallFunc0204b088OverList0x2c(p18);
        }
    }
    struct SelfState020e2834* p1c = *(struct SelfState020e2834**)(obj + 0x1c);
    if (p1c != 0) {
        SetYesNoButtonPalette020e2834(p1c);
    }
}
