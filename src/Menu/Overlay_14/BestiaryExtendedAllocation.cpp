#if defined(jpn)
#define R(j,u) (j)
#define _Z27ConfigureSubsystem_021889f8P11Obj021889f8 func_ov008_0218973c
#define data_ov005_0215cd20 data_ov005_0215e100
#define data_ov014_021894b8 data_ov014_0218a2f8
#define data_ov015_02193cfc data_ov015_0219482c
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_02194129 data_ov015_02194c69
#define func_ov008_02188730 func_ov008_02189444
#define func_ov014_02185c90 func_ov014_02186d00
#else
#define R(j,u) (u)
#endif
#include "globaldefs.h"
#include "Memory/SafeAllocator.h"

struct BestiaryExtendedItem { char data[0x28]; };
struct BestiaryExtendedGroup { char data[0x20]; };
struct BestiaryExtendedObject { char data[0xe0]; };
struct BestiaryExtendedRecord {
    unsigned int index : 10;
    unsigned int flag : 1;
    unsigned int category : 7;
    unsigned int subtype : 7;
    unsigned int remaining : 7;
};
struct BestiaryExtendedAllocationState {
    char unknown[0xb4];
    SafeAllocator* allocators;
    char unknownb8[8];
    void* renderer;
    BestiaryExtendedGroup* groups;
    BestiaryExtendedObject* objects;
    void* resourceBuffer;
    void* unknownd0;
    BestiaryExtendedItem* items;
    void* list;
    BestiaryExtendedRecord* records;
};
struct BestiaryAllocationState;
extern "C" {
void _Z12Init0205a198P14Struct0205a198(void*);
void _Z23ClearField0And40205a234P19ClearTarget0205a234(void*);
void func_0207f84c(void*);
void _Z17ResetList0204af64P12List0204af64(void*);
void func_0204c684(void*);
void func_ov014_02184300(BestiaryAllocationState*, SafeAllocator*);
extern const unsigned int data_ov014_021894b8[5];
}

extern "C" ARM void func_ov014_021868b8(BestiaryExtendedAllocationState* state, SafeAllocator* allocator) {
    if (!allocator) return;
    state->resourceBuffer = allocator->Allocate(0x4000);
    state->items = (BestiaryExtendedItem*)allocator->Allocate(0x140);
    state->list = allocator->Allocate(8);
    state->allocators = (SafeAllocator*)allocator->Allocate(0x64);
    state->records = (BestiaryExtendedRecord*)allocator->Allocate(0x4d0);
    for (unsigned char i = 0; i < 8; ++i) _Z12Init0205a198P14Struct0205a198(&state->items[i]);
    _Z23ClearField0And40205a234P19ClearTarget0205a234(state->list);
    for (int i = 0; i < 5; ++i) {
        unsigned int size;
        unsigned int offset = i * sizeof(SafeAllocator);
        size = data_ov014_021894b8[i];
        void* buffer = allocator->Allocate(size);
        ((SafeAllocator*)((char*)state->allocators + offset))->CreateTypeA(buffer, size);
        ((SafeAllocator*)((char*)state->allocators + offset))->Reset();
    }
    for (unsigned short i = 0; i < 0x134; ++i) {
        BestiaryExtendedRecord* record = &state->records[i];
        record->index = 0;
        record->flag = 0;
        record->category = 0;
        record->subtype = 0;
    }
    state->renderer = allocator->Allocate(R(0x34,0x40));
    state->groups = (BestiaryExtendedGroup*)allocator->Allocate(0x40);
    state->objects = (BestiaryExtendedObject*)allocator->Allocate(0x380);
    func_0207f84c(state->renderer);
    for (unsigned char i = 0; i < 2; ++i) _Z17ResetList0204af64P12List0204af64(&state->groups[i]);
    for (unsigned char i = 0; i < 4; ++i) func_0204c684(&state->objects[i]);
    func_ov014_02184300((BestiaryAllocationState*)state, allocator);
}
