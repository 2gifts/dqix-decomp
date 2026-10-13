#include <globaldefs.h>
#include "Resource/MessageSystem.h"

int GetGlobalField0x1c020421a0();
struct MessageOwner0215cab0 {
#if defined(jpn)
    char unknown0[0x406];
#else
    char unknown0[0x3ee];
#endif
    unsigned char messageState;
    unsigned char messageFlag;
};

// USA: func_ov003_0215cab0  (semantic: SetGlobalFieldsFromObj_0215cab0)
extern "C" ARM void func_ov003_0215cab0(MessageOwner0215cab0* owner, const char* text) {
    if (text == 0) return;
    MessageSystem* window = (MessageSystem*)GetGlobalField0x1c020421a0();
#if defined(jpn)
    func_0204500c(window, text, 0);
#else
    func_0204500c(window, text, 0, (void*)0xe3);
#endif
    window->b19b2 = owner->messageFlag;
    window->state = owner->messageState;
}
