#include <globaldefs.h>

#if defined(jpn)
enum { kFlags = 0x962, kDialogueFlags = 0x6f0, kDisplayFlags = 0x717 };
#else
enum { kFlags = 0xae2, kDialogueFlags = 0x774, kDisplayFlags = 0x79b };
#endif

extern "C" void func_ov023_021dcd90(void* p, int x);
extern "C" void func_ov006_02155508(void* s);

struct AlchemyDialogue {
    unsigned char unknown0[kDialogueFlags];
    unsigned short flags;
    unsigned char unknownAfterFlags[kDisplayFlags - kDialogueFlags - 2];
    unsigned char displayFlags;
};

struct ClearFlag40_02157184Struct {
    unsigned char pad[kFlags];
    unsigned short flags;
    AlchemyDialogue dialogue;
};

// USA: func_ov006_02157184
ARM void ClearFlag40_02157184(struct ClearFlag40_02157184Struct* s) {
    s->flags &= ~0x40;
    func_ov023_021dcd90(&s->dialogue, 0);
    func_ov006_02155508(s);
}
