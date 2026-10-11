#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/Memory.h"
#include "System/ProcessorContext.h"

struct Header02201a94 {
    unsigned char pad0[0xc];
    unsigned short f0c;
    unsigned short f0e;
};

#define SwapBytes16_02201a94(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_02201a94
extern "C" ARM void func_ov031_02201a94(Header02201a94* a, void* b, void* c) {
    unsigned char* entry;
    int priorState = DisableIRQInterrupts();
    ProcessorContext* context = data_02111304.firstContext;
    if (context != NULL) {
        do {
            entry = (unsigned char*)context->unknown_A4;
            if (entry != NULL && *(unsigned int*)entry != 0 && entry[8] == 0xb &&
                *(unsigned short*)((unsigned char*)b + 4) == (unsigned short)*(unsigned int*)entry &&
                *(unsigned short*)(entry + 0xa) == *(unsigned short*)((unsigned char*)b + 6) &&
                *(unsigned int*)(entry + 0x44) == 0) {
                unsigned int seq = ((unsigned int)SwapBytes16_02201a94(a->f0c) << 16) | SwapBytes16_02201a94(a->f0e);
                if (*(unsigned int*)(entry + 0x1c) == seq) {
                    unsigned int capacity = *(unsigned int*)(entry + 0x3c);
                    if ((unsigned int)c - 8 > capacity) {
                        *(unsigned int*)(entry + 0x44) = capacity;
                    } else {
                        *(unsigned int*)(entry + 0x44) = (unsigned int)c - 8;
                    }
                    VectorizedInvertedMemcpy((unsigned char*)b + 8, *(void**)(entry + 0x40), *(unsigned int*)(entry + 0x44));
                    if (*(unsigned int*)(entry + 4) == 3) {
                        *(unsigned int*)(entry + 4) = 0;
                        MarkContextReadyAndSwitch(*(ProcessorContext**)entry);
                    }
                    break;
                }
            }
            context = context->pNext;
        } while (context != NULL);
    }
    SetIRQInterruptState(priorState);
}
