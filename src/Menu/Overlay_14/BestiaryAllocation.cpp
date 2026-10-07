#include "globaldefs.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

struct BestiaryListItem { char unknown[0x28]; };
struct BestiaryList {
    char unknown00[0x40];
    BestiaryListItem* items;
    char unknown44[8];
    short count;
    char unknown4e[2];
    unsigned char flags;
    char unknown51[3];
};
struct BestiaryAllocationState {
    void** entryBuffers;
    BestiaryList* list;
    BestiaryListItem* items;
    char unknown0c[0x30];
    SafeAllocator* allocators;
    Object3D* model;
    void* modelResource;
    char unknown48[0x10];
    void* labels;
    void* unknown5c;
    void* name;
    void* description;
    void* extra;
    char unknown6c[0x16];
    unsigned char unknownFlags : 2;
    unsigned char ownsModel : 1;
    unsigned char tailFlags : 5;
};
struct BestiaryAllocationSizes { unsigned int values[6]; };
extern "C" {
extern const BestiaryAllocationSizes data_ov014_02189498;
extern const unsigned int data_ov014_02189480[3];
void _Z12Init0205a198P14Struct0205a198(void*);
void _Z18InitStruct0205a444Pc(BestiaryList*);
}

extern "C" ARM void func_ov014_02184300(BestiaryAllocationState* state, SafeAllocator* allocator) {
    if (allocator) {
        BestiaryAllocationSizes sizes = data_ov014_02189498;
        state->allocators = (SafeAllocator*)allocator->Allocate(0x78);
        state->entryBuffers = (void**)allocator->Allocate(0xc);
        for (int i = 0; i < 3; ++i) {
            state->entryBuffers[i] = allocator->Allocate(data_ov014_02189480[i]);
        }
        state->model = (Object3D*)allocator->Allocate(0xac);
        state->modelResource = allocator->Allocate(0x2c8);
        state->labels = allocator->Allocate(0x4c);
        state->name = allocator->Allocate(0x48);
        state->description = allocator->Allocate(0x48);
        state->extra = allocator->Allocate(0x200);
        state->list = (BestiaryList*)allocator->Allocate(0x54);
        state->items = (BestiaryListItem*)allocator->Allocate(0x78);
        for (unsigned char i = 0; i < 3; ++i) _Z12Init0205a198P14Struct0205a198(&state->items[i]);
        _Z18InitStruct0205a444Pc(state->list);
        state->list->flags = 0;
        BestiaryList* list = state->list;
        list->items = state->items;
        list->count = 3;
        for (int i = 0; i < 6; ++i) {
            unsigned int size;
            unsigned int offset = i * sizeof(SafeAllocator);
            size = sizes.values[i];
            void* buffer = allocator->Allocate(size);
            ((SafeAllocator*)((char*)state->allocators + offset))->CreateTypeA(buffer, size);
            ((SafeAllocator*)((char*)state->allocators + offset))->Reset();
        }
        state->model->Initialize();
        state->model->EnableFlag(4);
        state->ownsModel = 1;
    }
}
