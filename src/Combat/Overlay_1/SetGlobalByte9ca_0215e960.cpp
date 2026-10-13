#include <globaldefs.h>
#include <Resource/MessageSystem.h>

int GetGlobalField0x1c020421a0();

// USA: func_ov001_0215e960  (semantic: SetGlobalByte9ca_0215e960)
extern "C" ARM int func_ov001_0215e960(void) {
    ((MessageSystem*)GetGlobalField0x1c020421a0())->b19ca = 0;
    return 1;
}
