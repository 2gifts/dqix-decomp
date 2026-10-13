#include <globaldefs.h>
#include <Combat/Overlay31EntryLookup.h>
#include "System/Interrupts.h"

int GetData0224e53c_0220d60c(void);

// USA: func_ov031_0220ec04
ARM const void* GetOffset10FromResult_0220ec04(int arg) {
    int state = DisableIRQInterrupts();
    int base = GetData0224e53c_0220d60c();
    if (base == 0) {
        SetIRQInterruptState(state);
        return 0;
    }
    LookupNode_0220ee50* r = func_ov031_0220ee50(arg);
    if (r == 0) {
        SetIRQInterruptState(state);
        return 0;
    }
    SetIRQInterruptState(state);
    return r + 1;
}
