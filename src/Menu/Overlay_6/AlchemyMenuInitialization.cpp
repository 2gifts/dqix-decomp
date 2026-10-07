#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct AlchemyBufferInitializationView;
struct AlchemyInitializedBuffersView {
    char unknown00[0x1a4];
    void* data;
    char unknown1a8[4];
    void* ownerData;
    void* otherOwnerData;
};
struct AlchemyRecipeStatusView {
    short item;
    unsigned short selected : 1;
    unsigned short updated : 1;
    unsigned short unknownFlags : 14;
};
struct AlchemyMenuListView {
    char unknown00[0x3e];
    unsigned char flag;
    inline unsigned char Enable() { return flag = 1; }
};
struct AlchemyMenuListOwnerView {
    char unknown00[0xc];
    AlchemyMenuListView* list;
};
struct AlchemyMenuInitializationView {
    char unknown00[4];
    unsigned char** byteTables;
    void* data;
    SafeAllocator* allocators;
    AlchemyBufferInitializationView* buffers;
    void* extraBuffer;
    AlchemyMenuListOwnerView* listOwner;
    char (*pairBuffer)[0x20];
    char (*sevenBuffer)[0xe0];
    char (*entryBuffer)[0x28];
    void* listData;
    char unknown2c[0xc];
    AlchemyRecipeStatusView* recipeStatus;
    char unknown3c[0xc];
    short** ingredientTables;
    unsigned char** quantityTables;
    unsigned short* entryCounts;
    char unknown54[0x104];
    char otherOwnerData[0x18];
    char ownerData[0x224];
    unsigned short flags;
};
extern "C" {
extern unsigned short data_ov006_0215fffe[];
extern unsigned int data_ov006_02160054[];
void* memcpy(void*, const void*, unsigned int);
void* memset(void*, int, unsigned int);
void _Z24InitEntryManager020e2490P20EntryManager020e2490iiPvP13SafeAllocatorih(void*, int, int, void*, SafeAllocator*, int, int);
void func_0207f84c(void*);
void _Z17ResetList0204af64P12List0204af64(void*);
void func_0204c684(void*);
void _Z12Init0205a198P14Struct0205a198(void*);
void func_ov006_02154614(void*);
void func_ov006_02154348(AlchemyBufferInitializationView*, SafeAllocator*, void*);
void _Z17SetFlag8_021553a8Pv(void*);
void func_020ac234(AlchemyRecipeStatusView*);
}
extern "C" ARM void func_ov006_021576a0(AlchemyMenuInitializationView* state, SafeAllocator* allocator, void* context)
{
    unsigned short sizes[9];
    memcpy(sizes, data_ov006_0215fffe, 0x12);
    state->ingredientTables = (short**)allocator->Allocate(0x24);
    state->quantityTables = (unsigned char**)allocator->Allocate(0x24);
    state->entryCounts = (unsigned short*)allocator->Allocate(0x12);
    for (unsigned char index = 0; index < 9; index++) {
        unsigned int size = sizes[index];
        state->ingredientTables[index] = (short*)allocator->Allocate(size * 2);
        state->quantityTables[index] = (unsigned char*)allocator->Allocate(size);
        memset(state->ingredientTables[index], -1, size * 2);
        memset(state->quantityTables[index], 0, size);
        state->entryCounts[index] = 0;
    }
    state->data = allocator->Allocate(0x4000);
    state->allocators = (SafeAllocator*)allocator->Allocate(0xc8);
    state->extraBuffer = allocator->Allocate(0x40);
    state->pairBuffer = (char (*)[0x20])allocator->Allocate(0x40);
    state->sevenBuffer = (char (*)[0xe0])allocator->Allocate(0x620);
    state->entryBuffer = (char (*)[0x28])allocator->Allocate(0x488);
    state->listData = allocator->Allocate(8);
    state->buffers = (AlchemyBufferInitializationView*)allocator->Allocate(0x12c0);
    state->recipeStatus = (AlchemyRecipeStatusView*)allocator->Allocate(0x75c);
    state->listOwner = (AlchemyMenuListOwnerView*)allocator->Allocate(0x24);
    _Z24InitEntryManager020e2490P20EntryManager020e2490iiPvP13SafeAllocatorih(state->listOwner, 1, 1, state->listData, allocator, 4, 0x40);
    AlchemyMenuListView* list = state->listOwner->list;
    list->Enable();
    for (unsigned char index = 0; index < 10; index++) {
        state->allocators[index].ResetAllocatorPointer();
        unsigned int size = data_ov006_02160054[index];
        state->allocators[index].CreateTypeA(allocator->Allocate(size), size);
        state->allocators[index].Reset();
    }
    func_0207f84c(state->extraBuffer);
    for (unsigned char index = 0; index < 2; index++) _Z17ResetList0204af64P12List0204af64(state->pairBuffer[index]);
    for (unsigned char index = 0; index < 7; index++) func_0204c684(state->sevenBuffer[index]);
    for (unsigned char index = 0; index < 29; index++) _Z12Init0205a198P14Struct0205a198(state->entryBuffer[index]);
    for (unsigned short index = 0; index < 471; index++) {
        AlchemyRecipeStatusView* record = &state->recipeStatus[index];
        record->item = -1;
        record->selected = 0;
        record->updated = 0;
        record->unknownFlags = 0;
    }
    func_ov006_02154614(state->buffers);
    func_ov006_02154348(state->buffers, allocator, context);
    ((AlchemyInitializedBuffersView*)state->buffers)->data = state->data;
    ((AlchemyInitializedBuffersView*)state->buffers)->ownerData = state->ownerData;
    ((AlchemyInitializedBuffersView*)state->buffers)->otherOwnerData = state->otherOwnerData;
    if (state->flags & 2) _Z17SetFlag8_021553a8Pv(state->buffers);
    func_020ac234(state->recipeStatus);
    state->byteTables = (unsigned char**)allocator->Allocate(0x40);
    for (int index = 0; index < 16; index++) {
        state->byteTables[index] = (unsigned char*)allocator->Allocate(0x80);
        memset(state->byteTables[index], 0, 0x80);
    }
}
