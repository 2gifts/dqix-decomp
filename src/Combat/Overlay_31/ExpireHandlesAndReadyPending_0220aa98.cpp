#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/ProcessorContext.h"

struct HandleSlotEntry_0220aa98 {
    char pad[0x50];
    unsigned int field50;
    char pad1[0x5a - 0x54];
    unsigned char field5a;
    char pad2[0x5c - 0x5b];
};

extern HandleSlotEntry_0220aa98 data_ov031_0224e3b8[4];

struct PendingRequest_0220aa98 {
    void* context;
    int type;
    unsigned char status;
    unsigned char flags;
    char* ctx;
    unsigned int timestamp;
};

void MarkContextReadyAndSwitch(struct ProcessorContext*);

// USA: func_ov031_0220aa98  (semantic: ExpireHandlesAndReadyPending_0220aa98)
extern "C" ARM void func_ov031_0220aa98(unsigned int now) {
    int oldIRQ = DisableIRQInterrupts();
    int i = 0;
    HandleSlotEntry_0220aa98* entry = data_ov031_0224e3b8;
    do {
        if (entry->field5a != 0 && (int)(now - entry->field50) > 0x3bd) {
            entry->field5a = 0;
        }
        i++;
        entry++;
    } while (i < 4);
    SetIRQInterruptState(oldIRQ);

    ProcessorContext* ctx = data_02111304.firstContext;
    if (ctx == 0) {
        return;
    }
    do {
        PendingRequest_0220aa98* p = (PendingRequest_0220aa98*)ctx->unknown_A4;
        if (p != 0 && p->context != 0 && p->flags != 0 && p->status == 4 &&
            (unsigned char)p->ctx[0x455] < 8 && (int)(now - p->timestamp) > 0xef && p->type == 2) {
            p->status = 0;
            p->type = 0;
            MarkContextReadyAndSwitch((ProcessorContext*)p->context);
        }
        ctx = ctx->pNext;
    } while (ctx != 0);
}
