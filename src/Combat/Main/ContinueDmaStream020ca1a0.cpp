#include <globaldefs.h>
#include "System/DMA.h"
#include "System/Interrupts.h"

void UpdateHwRegBitsAndFireCallback020ca24c(void);

struct DmaStreamState020ca1a0 {
    char pad0[4];
    int channel;
    unsigned int srcAddr;
    unsigned int remaining;
};
extern struct DmaStreamState020ca1a0 data_02111684;

// USA: func_020ca1a0  (semantic: ContinueDmaStream020ca1a0)
extern "C" ARM void func_020ca1a0(void) {
    unsigned int src;
    unsigned int chunk;
    if (data_02111684.remaining == 0) return;
    chunk = data_02111684.remaining;
    if (chunk >= 0x1d8) chunk = 0x1d8;
    src = data_02111684.srcAddr;
    unsigned int newRemaining = *(unsigned int*)&data_02111684.remaining - chunk;
    data_02111684.remaining = newRemaining;
    data_02111684.srcAddr = src + chunk;
    if (newRemaining == 0) {
        SetDMACompletionCallback(data_02111684.channel, (DMACompletionCallback)UpdateHwRegBitsAndFireCallback020ca24c, 0);
        ConfigureDMATransferAtomic(data_02111684.channel, src, 0x04000400, 0xc4400000 | (chunk >> 2));
        AcknowledgeSpecificInterrupts(0x200000);
    } else {
        ConfigureDMATransferAtomic(data_02111684.channel, src, 0x04000400, 0x84400000 | (chunk >> 2));
        AcknowledgeSpecificInterrupts(0x200000);
    }
}
