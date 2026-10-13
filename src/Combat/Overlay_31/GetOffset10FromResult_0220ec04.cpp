#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/WirelessScanDescriptor.h"

int GetData0224e53c_0220d60c(void);

// USA: func_ov031_0220ec04
ARM WirelessScanDescriptor* GetOffset10FromResult_0220ec04(int arg) {
    int state = DisableIRQInterrupts();
    int base = GetData0224e53c_0220d60c();
    if (base == 0) {
        SetIRQInterruptState(state);
        return 0;
    }
    WirelessScanNode* node = func_ov031_0220ee50(arg);
    if (node == 0) {
        SetIRQInterruptState(state);
        return 0;
    }
    SetIRQInterruptState(state);
    return &node->descriptor;
}
