#include <globaldefs.h>
#include <Resource/MessageSystem.h>

int GetGlobalField0x1c020421a0();

// KEEP-NAME
// USA: func_ov001_0215e920
// JPN: func_ov001_0215ff98
ARM int SetGlobalFieldByte19c1_0215e920() {
    ((MessageSystem*)GetGlobalField0x1c020421a0())->b19c1 = 1;
    return 1;
}
