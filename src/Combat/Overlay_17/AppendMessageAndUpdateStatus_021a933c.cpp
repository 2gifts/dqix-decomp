#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

#if defined(jpn)
enum { kMessagesOffset = 0x208, kFlagOffset = 0x17e2, kModeOffset = 0x86c };
#else
enum { kMessagesOffset = 0x278, kFlagOffset = 0x19b2, kModeOffset = 0x99c };
#endif

struct MessageSelection {
    char unknown0[0x14];
    int alternateSet;
    char unknown18[kMessagesOffset - 0x18];
    Container020e0310 messages;
};

struct MessageSelectionController {
    char unknown0[kModeOffset];
    int mode;
    char unknownAfterMode[kFlagOffset - kModeOffset - sizeof(int)];
    unsigned char messageFlag;
};

MessageSelectionController* GetGlobalField0x1c020421a0(void);
int GetFieldByKey020e0434(struct Container020e0310*, int);
#if !defined(jpn)
extern "C" void func_0204500c(void*, const char*, int, int);
#endif
#if defined(jpn)
extern "C" void func_0204500c(void*, const char*, int);
#endif

// USA: func_ov017_021a933c  (semantic: AppendMessageAndUpdateStatus_021a933c)
extern "C" ARM void func_ov017_021a933c(MessageSelection* selection, int key) {
    MessageSelectionController* controller = GetGlobalField0x1c020421a0();
    if (key <= 0xc7 && key >= 0x64) {
        if (selection->alternateSet == 1) key += 0x64;
    }
#if defined(jpn)
    func_0204500c(controller, (const char*)GetFieldByKey020e0434(&selection->messages, (short)key), 0);
#else
    func_0204500c(controller, (const char*)GetFieldByKey020e0434(&selection->messages, (short)key), 0, 0xe3);
#endif

    if (key <= 0x12b && key >= 0x64) {
        controller->messageFlag = 1;
    } else {
        controller->messageFlag = 0;
    }
    if (key > 0x12b || key < 0x64) return;
    if (selection->alternateSet == 0) {
        controller->mode = 2;
    } else {
        controller->mode = 1;
    }
}
