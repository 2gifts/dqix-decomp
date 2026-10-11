#include <globaldefs.h>
#include "Graphics/OBJImage.h"
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" void* func_ov011_021849c8(void* ctx);
void* Find_021f6dd8(void* a, int b);
extern "C" void func_ov023_021f6d14(void* list, void* node);

struct Struct02076928;
void UpdateSelectedCell02076928(struct Struct02076928* s, int val);

extern "C" {
    void func_02076080(void* a, void* alloc, int p2, int p3);
}

// JPN: func_ov023_021fad48
// USA: func_ov023_021fb9c4  (semantic: BuildAndInsertRange_021fb9c4)
extern "C" ARM void func_ov023_021fb9c4(void* obj, void* ctx, int p2, int p3) {
    if (p2 == 0 || p3 == 0) return;

    void* base = func_ov011_021845f8(ctx, *(unsigned short*)((char*)obj + 0x8));
    if (base == NULL) return;

    int size = func_02076738((InitStruct02075cdcStruct*)((char*)obj + 0x20), (const unsigned char*)p2, p3);

    void* node = func_ov011_021849c8(ctx);
    void* found = Find_021f6dd8(node, size);
    *(int*)((char*)obj + 0x94) = (int)found;
    *(int*)((char*)obj + 0x98) = (int)((char*)found + size);
    func_ov023_021f6d14(node, (char*)obj + 0x94);

    *(void**)((char*)obj + 0x58) = found;

    SafeAllocator* alloc = (SafeAllocator*)((char*)base + 4);
    alloc->GetSizeWithLargestBlockRemoved();
    func_02076080((char*)obj + 0x20, (char*)base + 4, p2, p3);
    UpdateSelectedCell02076928((struct Struct02076928*)((char*)obj + 0x20), 1);
    alloc->GetSizeWithLargestBlockRemoved();
}
