#include <globaldefs.h>
#include "System/Memory.h"
#include "System/Mutex.h"

struct Pending10050 { int field_0xa04; int field_0xa08; };
struct State10050 {
    int serviceState;
    int runStatus;
    Mutex mutex;
    char pad_0x20[8];
    int initializationArgumentA;
    int initializationArgumentB;
    int field_0x30;
    int field_0x34;
    char name[8];
    int field_0x40;
    char pad_0x44[0x174];
    int connectionHandle;
    Mutex mutex_0x1bc;
    char pad_0x1d4[0x800];
    int field_0x9d4;
    char pad_0x9d8[0xc];
    void (*callback)(unsigned int);
    int* field_0x9e8;
    int field_0x9ec;
    char pad_0x9f0[0x14];
    Pending10050 pending;
    int field_0xa0c;
    ProcessorContext context;
    char stack[0x800];
};
extern State10050* data_ov031_0224e588;
extern char data_ov031_022499f4[];
extern int data_ov031_02249928;
extern int data_ov031_0224992c;
void CopyStringBounded020d2f28(char*, const char*, int);
void ClearBit15_02211018(unsigned int);
extern "C" void func_ov031_02210674();

static inline Pending10050* GetPending10050(State10050* state) {
    return &state->pending;
}

// USA: func_ov031_02210050
extern "C" ARM void func_ov031_02210050(State10050* state, int initializationArgumentA, int initializationArgumentB) {
    data_ov031_0224e588 = state;
    VectorizedMemset(state, 0, 0x12d0);
    data_ov031_0224e588->serviceState = 0;
    data_ov031_0224e588->runStatus = 0;
    ZeroInitializeMutex(&data_ov031_0224e588->mutex);
    data_ov031_0224e588->initializationArgumentA = initializationArgumentA;
    data_ov031_0224e588->initializationArgumentB = initializationArgumentB;
    CopyStringBounded020d2f28(data_ov031_0224e588->name, data_ov031_022499f4, 5);
    State10050* reset = data_ov031_0224e588;
    reset->field_0x34 = 0;
    data_ov031_0224e588->field_0x40 = 0;
    data_ov031_0224e588->connectionHandle = -59;
    data_ov031_0224e588->field_0x9d4 = data_ov031_02249928;
    data_ov031_0224e588->field_0x9e8 = &data_ov031_0224992c;
    data_ov031_0224e588->field_0x9ec = 1;
    data_ov031_0224e588->callback = ClearBit15_02211018;
    ZeroInitializeMutex(&data_ov031_0224e588->mutex_0x1bc);
    State10050* pending = data_ov031_0224e588;
    Pending10050* fields = GetPending10050(pending);
    pending->pending.field_0xa04 = fields->field_0xa08 = 0;
    State10050* current = data_ov031_0224e588;
    unsigned int priority = GetContextPriority(data_02111304.activeContext);
    PopulateContext(&current->context, (unsigned int)func_ov031_02210674, 0, (unsigned int)(current->stack + sizeof(current->stack)), 0x800, priority);
    MarkContextStackTopUnknownSubspace(&data_ov031_0224e588->context, 0x80);
}
