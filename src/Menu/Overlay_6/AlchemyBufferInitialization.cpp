#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct AlchemyBufferInitializationView {
    char unknown00[0x180];
    SafeAllocator* allocators;
    SafeAllocator* activeAllocator;
    SafeAllocator* loadingAllocator;
    char unknown18c[0x38];
    unsigned char* byteBuffer;
    void* menuBuffer;
    char (*pairBuffer)[0x20];
    char (*singleBuffer)[0xe0];
    void* extraBuffer;
    char unknown1d8[8];
    char (*entryBuffer)[0x28];
    char unknown1e4[0x8a0];
    SafeAllocator additionalAllocators[4];
    char unknownad4[0x10];
    char widget[0x79c];
    SafeAllocator* widgetAllocator;
    SafeAllocator* smallAllocator;
};
extern "C" {
extern unsigned int data_ov006_0215ff7c[];
void func_ov023_021dbfd0(void*, SafeAllocator*);
void _Z23SetFlagAndData_021dbfa8P11Obj021dbfa8i(void*, void*);
void _Z20ClearFields_021e20c0Pv(void*);
void _Z17ResetList0204af64P12List0204af64(void*);
void func_0204c684(void*);
void func_0207f84c(void*);
void _Z12Init0205a198P14Struct0205a198(void*);
}
extern "C" ARM void func_ov006_02154348(AlchemyBufferInitializationView* state, SafeAllocator* allocator, void* context)
{
    state->allocators = (SafeAllocator*)allocator->Allocate(0x78);
    state->activeAllocator = (SafeAllocator*)allocator->Allocate(0x14);
    state->loadingAllocator = (SafeAllocator*)allocator->Allocate(0x14);
    state->byteBuffer = (unsigned char*)allocator->Allocate(0x80);
    state->menuBuffer = allocator->Allocate(0x4c);
    state->pairBuffer = (char (*)[0x20])allocator->Allocate(0x40);
    state->singleBuffer = (char (*)[0xe0])allocator->Allocate(0xe0);
    state->extraBuffer = allocator->Allocate(0x40);
    state->entryBuffer = (char (*)[0x28])allocator->Allocate(0x2a8);
    state->activeAllocator->CreateTypeA(allocator->Allocate(0x258), 0x258);
    state->loadingAllocator->CreateTypeA(allocator->Allocate(0x258), 0x258);
    state->activeAllocator->Reset();
    state->loadingAllocator->Reset();
    state->widgetAllocator = (SafeAllocator*)allocator->Allocate(0x14);
    state->smallAllocator = (SafeAllocator*)allocator->Allocate(0x14);
    state->widgetAllocator->CreateTypeA(allocator->Allocate(0x1e00), 0x1e00);
    state->widgetAllocator->Reset();
    state->smallAllocator->CreateTypeA(allocator->Allocate(0x80), 0x80);
    state->smallAllocator->Reset();
    func_ov023_021dbfd0(state->widget, state->widgetAllocator);
    _Z23SetFlagAndData_021dbfa8P11Obj021dbfa8i(state->widget, context);
    for (unsigned char index = 0; index < 6; index++) {
        unsigned int size = data_ov006_0215ff7c[index];
        state->allocators[index].CreateTypeA(allocator->Allocate(size), size);
        state->allocators[index].Reset();
    }
    for (unsigned char index = 0; index < 4; index++) {
        state->additionalAllocators[index].CreateTypeA(allocator->Allocate(0x280), 0x280);
        state->additionalAllocators[index].Reset();
    }
    state->byteBuffer[0] = 0;
    _Z20ClearFields_021e20c0Pv(state->menuBuffer);
    for (unsigned char index = 0; index < 2; index++) _Z17ResetList0204af64P12List0204af64(state->pairBuffer[index]);
    for (unsigned char index = 0; index < 1; index++) func_0204c684(state->singleBuffer[index]);
    func_0207f84c(state->extraBuffer);
    for (unsigned char index = 0; index < 17; index++) _Z12Init0205a198P14Struct0205a198(state->entryBuffer[index]);
}
