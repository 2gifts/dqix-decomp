#include <globaldefs.h>

#if defined(jpn)
#define CallIfFlag_021571cc_021571cc func_ov006_021587d4
enum { kDialogue = 0x964, kDialogueFlags = 0x6f0, kDisplayFlags = 0x717 };
#else
enum { kDialogue = 0xae4, kDialogueFlags = 0x774, kDisplayFlags = 0x79b };
#endif



extern "C" void func_ov023_021dd344(void* p);

struct AlchemyDialogue {
    unsigned char unknown0[kDialogueFlags];
    unsigned short flags;
    unsigned char unknownAfterFlags[kDisplayFlags - kDialogueFlags - 2];
    unsigned char displayFlags;
};

struct CallIfFlag0x800_021571ccStruct {
    unsigned char unknown0[kDialogue];
    AlchemyDialogue dialogue;
};

// USA: func_ov006_021571cc
#if defined(jpn)
extern "C"
#endif
ARM void CallIfFlag_021571cc_021571cc(struct CallIfFlag0x800_021571ccStruct* s) {
    int enabled = (s->dialogue.flags & 0x800) != 0;
    if (enabled) {
        func_ov023_021dd344(&s->dialogue);
    }
}
