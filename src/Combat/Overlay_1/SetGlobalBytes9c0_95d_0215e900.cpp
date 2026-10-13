#include <globaldefs.h>
#include <Resource/MessageSystem.h>

int GetGlobalField0x1c020421a0();

// USA: func_ov001_0215e900  (semantic: SetGlobalBytes9c0_95d_0215e900)
extern "C" ARM int func_ov001_0215e900(void) {
    MessageSystem* messages = (MessageSystem*)GetGlobalField0x1c020421a0();
    messages->b19c0 = 1;
    messages->b195d = 30;
    return 1;
}
