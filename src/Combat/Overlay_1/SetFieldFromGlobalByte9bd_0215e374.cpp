#include <globaldefs.h>
#include "Resource/MessageSystem.h"

int GetGlobalField0x1c020421a0();
extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov001_0215e374  (semantic: SetFieldFromGlobalByte9bd_0215e374)
// JPN: func_ov001_0215f9f0
extern "C" ARM int func_ov001_0215e374(void* self) {
    MessageSystem* messages = (MessageSystem*)GetGlobalField0x1c020421a0();
    func_ov017_021d6134(self, messages->b19bd);
    return 1;
}
