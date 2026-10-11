#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

extern "C" void* func_02012fe4(void);
extern "C" int func_ov017_021d60f4(void* obj);
extern "C" void* func_ov017_021d612c(void* obj);
void* GetFieldPtrAt0x5ca4(void* obj);
void* GetPtrField0x468(void* obj);
struct List0209998c;
struct Elem0209998c;
Elem0209998c* FindElementByName0209998c(List0209998c* list, const char* name);
void InitStruct02013718(char* obj, int a, int b);
extern "C" void _ZN6Zone3D10SwitchZoneEt(void* g, int val, int flag);

struct GlobalBlock_02163b14 {
#if defined(jpn)
    char pad[0x6c];
#else
    char pad[0x4c];
#endif
    SafeAllocator* allocator;
    int field50;
};

// USA: func_ov001_02163b14  (semantic: AllocateAndInitEntryFromKey_02163b14)
extern "C" ARM int func_ov001_02163b14(void* obj) {
    GameState* battle = GameState::GetInstance();
    struct GlobalBlock_02163b14* g = (struct GlobalBlock_02163b14*)func_02012fe4();
    void* fieldPtr = GetFieldPtrAt0x5ca4(battle);
    int type = *(int*)obj;
    int key = -1;
    if (type == 0) {
        key = func_ov017_021d60f4(obj);
    } else if (type == 2) {
        key = (int)func_ov017_021d612c(obj);
        if (key == 0) return 0;
        void* table = GetPtrField0x468(battle);
        struct Elem0209998c* entry = FindElementByName0209998c((struct List0209998c*)table, (const char*)key);
        if (entry == 0) return 0;
        key = *(unsigned short*)entry;
    }
    if (key < 0) return 0;

    SafeAllocator* allocator = g->allocator;
    int extra = g->field50;

#if defined(jpn)
    void* p1 = allocator->Allocate(0x2864);
#else
    void* p1 = allocator->Allocate(0x2824);
#endif
    if (p1 == 0) return 0;

    SafeAllocator* p2 = (SafeAllocator*)allocator->Allocate(0x14);
    unsigned int maxAlloc = allocator->GetMaxPossibleAllocation();
    void* p3 = allocator->Allocate(maxAlloc);
    p2->CreateTypeA(p3, maxAlloc);

    InitStruct02013718((char*)p1, (int)p2, extra);
    _ZN6Zone3D10SwitchZoneEt(p1, key, 0);

    *(void**)fieldPtr = p1;
    return 1;
}
