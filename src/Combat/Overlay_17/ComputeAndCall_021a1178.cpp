#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Obj020542b4;
struct ResourcePairTableStorage {
    unsigned char data[0x70];
};

extern "C" void func_020542b4(Obj020542b4* entry, SafeAllocator* allocator, char* pairTables);

// USA: func_ov017_021a1178
ARM void ComputeAndCall_021a1178(char* resourceStorage, int slot) {
    GameResources* resources = (GameResources*)resourceStorage;
    GameResources::Substruct_12C8* entry = &resources->substruct_array_12c8[slot];
    int allocatorIndex = slot + 1;
    SafeAllocator* allocator = &resources->allocator_array_38[allocatorIndex];
    ResourcePairTableStorage* pairTables = (ResourcePairTableStorage*)resources->unknown_2cc;
    func_020542b4((Obj020542b4*)entry, allocator, (char*)&pairTables[allocatorIndex]);
}
