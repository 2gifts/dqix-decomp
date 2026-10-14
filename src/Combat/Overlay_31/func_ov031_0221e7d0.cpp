#include <globaldefs.h>
#include "System/Interrupts.h"

struct InitData020c7de4 {
    char padding0[0x20];
};
struct Handlers0221e7d0 {
    void* (*allocate)(void*);
    char padding4[4];
    void* context;
    void (*completion)(void*);
};
void InitStruct020c7de4(InitData020c7de4* queue, int buffer, int capacity);
extern "C" int func_ov031_0221f26c(int (*handler)(int), void* context, int size);
extern "C" int func_ov031_0221e7a8(int message);
extern "C" int func_020c7ea0(InitData020c7de4* queue, int* message, int blocking);
extern InitData020c7de4 data_ov031_0224f4e0;
extern int data_ov031_0224f4d0[4];
extern Handlers0221e7d0 data_ov031_0224f4c0;

// USA: func_ov031_0221e7d0
extern "C" THUMB int func_ov031_0221e7d0(void* (*allocate)(void*), void (*completion)(void*)) {
    int running = 1;
    InitStruct020c7de4(&data_ov031_0224f4e0, (int)data_ov031_0224f4d0, 4);
    if (allocate == NULL || completion == NULL) return -1;
    int interruptState = DisableIRQInterrupts();
    data_ov031_0224f4c0.allocate = allocate;
    data_ov031_0224f4c0.completion = completion;
    SetIRQInterruptState(interruptState);
    void* context = data_ov031_0224f4c0.allocate((void*)0x5890);
    data_ov031_0224f4c0.context = context;
    if (context == NULL) return -1;
    if (func_ov031_0221f26c(func_ov031_0221e7a8, context, 0x5890) == 0) running = 0;
    if (running != 0) {
        do {
            int message;
            func_020c7ea0(&data_ov031_0224f4e0, &message, 1);
            switch (message) {
            case 4: case 5: break;
            case 6: return 0;
            case 0: case 1: case 2: case 3:
            case 7: case 8: case 9: case 10: case 11:
            case 12: case 13: case 14: case 15:
            default: running = 0; break;
            }
        } while (running != 0);
    }
    data_ov031_0224f4c0.completion(data_ov031_0224f4c0.context);
    return -1;
}
