#include <globaldefs.h>
#include "System/DMA.h"
#include "System/Interrupts.h"

void RunAndClearCallback(void);

struct DmaAsyncState020ca2ac {
    int flag;                       // 0x0
    int channel;                    // 0x4
    char pad8[8];                   // 0x8..0xf
    DMACompletionCallback callback; // 0x10
    int userdata;                   // 0x14
};
extern struct DmaAsyncState020ca2ac data_02111684;

// USA: func_020ca2ac  (semantic: DmaTransferToFifoAsync020ca2ac)
extern "C" ARM void func_020ca2ac(int channel, unsigned int src, unsigned int len, DMACompletionCallback callback, int userdata) {
    if (len == 0) {
        if (callback != 0) {
            callback(userdata);
        }
        return;
    }

    while (*(volatile int*)&data_02111684.flag != 0) ;

    *(volatile int*)&data_02111684.flag = 1;
    *(int*)&data_02111684.channel = channel;
    data_02111684.callback = callback;
    data_02111684.userdata = userdata;

    VerifyDMATimingChangePermitted_020c9fd0(channel, 0x38000000);
    VerifyDMASource(channel, src, len, 0);
    AwaitDMACompletion(channel);
    SetDMACompletionCallback(channel, (DMACompletionCallback)RunAndClearCallback, 0);
    ConfigureDMATransferAtomic(channel, src, 0x4000400, 0xfc400000 | (len >> 2));
}
