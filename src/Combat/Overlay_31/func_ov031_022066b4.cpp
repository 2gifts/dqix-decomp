#include <globaldefs.h>
#include <System/Interrupts.h>
#include <System/ProcessorContext.h>

struct TransferLimit {
    unsigned char unknown_0x00[0x2c];
    unsigned short requested;
    unsigned short available;
};

struct TransferSettings {
    unsigned char unknown_0x00[0x24];
    int limit;
};

extern TransferSettings data_ov031_0224e1d0;

// USA: func_ov031_022066b4
extern "C" ARM int func_ov031_022066b4(int value) {
    TransferLimit* limits = reinterpret_cast<TransferLimit*>(data_02111304.activeContext->unknown_A4);
    int oldIRQ = DisableIRQInterrupts();
    int quantum;
    if (limits != 0) {
        int available = limits->available;
        if (available != 0 && limits->requested != 0) {
            int requested = limits->requested;
            int maximum = data_ov031_0224e1d0.limit;
            if (available > requested) {
                available = requested;
            }
            if (available > maximum) {
                available = maximum;
            }
            quantum = available * 2;
        } else {
            quantum = data_ov031_0224e1d0.limit * 2;
        }
    } else {
        quantum = data_ov031_0224e1d0.limit * 2;
    }
    SetIRQInterruptState(oldIRQ);
    if (quantum > 0) {
        int quotient = value / quantum;
        if (quotient > 0) {
            return quantum * quotient;
        }
    }
    return value;
}
