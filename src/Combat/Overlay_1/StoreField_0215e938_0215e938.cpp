#include <globaldefs.h>
#include <Resource/MessageSystem.h>

int GetGlobalField0x1c020421a0();
extern "C" int func_ov017_021d60f4(void*);

// KEEP-NAME
// USA: func_ov001_0215e938
// JPN: func_ov001_0215ffb0
ARM int StoreField_0215e938_0215e938(void* obj) {
    MessageSystem* messages = (MessageSystem*)GetGlobalField0x1c020421a0();
    messages->b19ae = func_ov017_021d60f4(obj);
    return 1;
}
