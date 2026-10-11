#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

struct EntryManager020e2490;
extern "C" void _Z24InitEntryManager020e2490P20EntryManager020e2490iiPvP13SafeAllocatorih(struct EntryManager020e2490* obj, int arg1, int arg2, void* arg3, SafeAllocator* alloc, int count, unsigned char flag);
struct List0204af64;
extern "C" void _Z17ResetList0204af64P12List0204af64(struct List0204af64* obj);
extern "C" void func_0204c684(void*);
extern "C" void func_0207f84c(void*);
struct Struct0205a198;
extern "C" void _Z12Init0205a198P14Struct0205a198(struct Struct0205a198*);

struct CombatSubsystem0215376c {
    char pad0[4];
    void* field4;
    void* field8;
    void* fieldC;
    char pad10[0x59 - 0x10];
    signed char field59;
};
extern "C" void func_ov003_0215376c(struct CombatSubsystem0215376c* obj);
extern "C" void func_ov003_021536e0(struct CombatSubsystem0215376c* obj, SafeAllocator* alloc);

struct AllocatorSizes021544ec {
    unsigned int v[8];
};
extern AllocatorSizes021544ec data_ov003_0217f320;

struct Obj021544ec {
    SafeAllocator* allocators;
    struct CombatSubsystem0215376c* subsystem;
    char pad8[4];
    void* bufC;
    struct List0204af64* lists;
    char* buf14;
    void* buf18;
    struct EntryManager020e2490* entryManager;
    int* words;
    struct Struct0205a198* buf24;
    void* buf28;
    char pad2c[0x90 - 0x2c];
    char field90[0xfc - 0x90];
    char fieldFc[0x114 - 0xfc];
    char field114[1];
};

#if defined(jpn)
enum { kNotificationBufferSize = 0x68, kEntryCount = 3 };
#else
enum { kNotificationBufferSize = 0x80, kEntryCount = 4 };
#endif

// JPN: func_ov003_02155bd4
// USA: func_ov003_021544ec
extern "C" ARM void func_ov003_021544ec(struct Obj021544ec* obj, SafeAllocator* alloc) {
    if (alloc != 0) {
        obj->allocators = (SafeAllocator*)alloc->Allocate(0xa0);
        obj->subsystem = (struct CombatSubsystem0215376c*)alloc->Allocate(0x60);
        obj->bufC = alloc->Allocate(0x4c00);
        obj->lists = (struct List0204af64*)alloc->Allocate(0x40);
        obj->buf14 = (char*)alloc->Allocate(0x2a0);
        obj->buf18 = alloc->Allocate(kNotificationBufferSize);
        obj->words = (int*)alloc->Allocate(0x30);
        obj->buf24 = (struct Struct0205a198*)alloc->Allocate(0x190);
        obj->buf28 = alloc->Allocate(8);
        obj->entryManager = (struct EntryManager020e2490*)alloc->Allocate(0x24);
        _Z24InitEntryManager020e2490P20EntryManager020e2490iiPvP13SafeAllocatorih(obj->entryManager, 0, 1, obj->buf28, alloc, kEntryCount, 0x40);

        AllocatorSizes021544ec sizes = data_ov003_0217f320;
        for (unsigned char i = 0; i < 8; i++) {
            SafeAllocator* allocators = obj->allocators;
            unsigned int size = sizes.v[i];
            allocators[i].ResetAllocatorPointer();
            allocators[i].CreateTypeA(alloc->Allocate(size), size);
            allocators[i].Reset();
        }
        for (unsigned char i = 0; i < 2; i++) {
            _Z17ResetList0204af64P12List0204af64((struct List0204af64*)((char*)obj->lists + i * 0x20));
        }
        for (unsigned char i = 0; i < 3; i++) {
            func_0204c684(obj->buf14 + i * 0xe0);
        }
        func_0207f84c(obj->buf18);
        for (unsigned char i = 0; i < 12; i++) {
            obj->words[i] = 0;
        }
        for (unsigned char i = 0; i < 10; i++) {
            _Z12Init0205a198P14Struct0205a198((struct Struct0205a198*)((char*)obj->buf24 + i * 0x28));
        }
        GameState::GetInstance();
        struct CombatSubsystem0215376c* sub = obj->subsystem;
        func_ov003_0215376c(sub);
        func_ov003_021536e0(sub, alloc);
        sub->field8 = obj->field90;
        sub->field4 = obj->fieldFc;
        sub->fieldC = obj->field114;
        sub->field59 = -1;
    }
}
