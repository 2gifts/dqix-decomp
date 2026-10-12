#include <globaldefs.h>

#if defined(jpn)
#define func_ov003_02174890 func_ov003_021739b8
#define FLAG_OFFSET_02174890 0xfba
#define CONTAINER_OFFSET_02174890 0x818
#else
#define FLAG_OFFSET_02174890 (0x1000 + 0x3e)
#define CONTAINER_OFFSET_02174890 0x89c
#endif

struct Cont0207fd88;
void CallFunc0204b088OverList0x2c(struct Cont0207fd88* obj);
struct SelfState020e2834;
void SetYesNoButtonPalette020e2834(struct SelfState020e2834* self);

// USA: func_ov003_02174890  (semantic: RefreshPaletteIfFlagSet_02174890)
extern "C" ARM void func_ov003_02174890(char* obj) {
    if (*(unsigned char*)(obj + FLAG_OFFSET_02174890) == 0) return;
    struct Cont0207fd88* p = *(struct Cont0207fd88**)(obj + CONTAINER_OFFSET_02174890);
    CallFunc0204b088OverList0x2c(p);
    struct SelfState020e2834* self = *(struct SelfState020e2834**)obj;
    if (self == NULL) return;
    SetYesNoButtonPalette020e2834(self);
}
