#include <globaldefs.h>
#if defined(jpn)
enum { kRegion12c0 = 0x1150 };
enum { kRegion12c4 = 0x1154 };
enum { kRegion12d4 = 0x1164 };
enum { kRegion13ea = 0x127a };
#else
enum { kRegion12c0 = 0x12c0 };
enum { kRegion12c4 = 0x12c4 };
enum { kRegion12d4 = 0x12d4 };
enum { kRegion13ea = 0x13ea };
#endif
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

struct Scene_0216af14 {
    unsigned char pad0[0x4];
    short state;
    unsigned char pad6[0x10 - 0x6];
    int field_0x10;
    unsigned char field_0x14[kRegion12c0 - 0x14];
    void* field_0x12c0;
    unsigned char pad12c4[kRegion12d4 - kRegion12c4];
    SafeAllocator allocator;
    unsigned char pad12d4[kRegion13ea - kRegion12d4 - sizeof(SafeAllocator)];
    unsigned char field_0x13ea;
    unsigned char pad13eb;
    unsigned char flags;
};

struct Pair0216af14 { unsigned int a; unsigned int b; };
extern struct Pair0216af14 data_020e6d5c;

struct DispatchEntry0216af14 { unsigned int fn; unsigned int locator; };
struct Table0216af14 { struct DispatchEntry0216af14 entries[8]; };
extern struct Table0216af14 data_ov003_0217f578;

extern AllocatorUnion data_02114e20;

extern "C" int func_ov003_0215c924(void* p, int scale);
extern "C" void func_ov003_0215c800(void* p);
extern "C" void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion* alloc, void* data);
extern "C" void _Z30ResetGlobalsAndReinit_0216d818Pc(char* obj);
extern "C" void func_ov003_0216d84c(void* p);
extern "C" int func_0205d0e0(void* p, unsigned int tick);

// JPN: func_ov003_0216aab4
// USA: func_ov003_0216af14
extern "C" ARM int func_ov003_0216af14(Scene_0216af14* scene) {
    GameState* gs = GameState::GetInstance();
    if (scene->flags & 2) {
        if (scene->state == 3) {
            if (func_ov003_0215c924(scene->field_0x14, 1) != 1) return 1;
            func_ov003_0215c800(scene->field_0x14);
            void* p = scene->allocator.GetSignedAllocator();
            if (p != 0) {
                scene->allocator.Destroy();
                _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, p);
            }
        }
        _Z30ResetGlobalsAndReinit_0216d818Pc((char*)scene);
        return 0;
    }
    if (scene->field_0x13ea != 0) {
        func_ov003_0216d84c(scene);
        if (scene->flags & 1) return 1;
    }
    unsigned int tick = gs->GetTickCount();
    if (scene->field_0x12c0 != 0 && scene->state == 2) {
        scene->field_0x10 = func_0205d0e0(scene->field_0x12c0, tick);
    }

    struct Table0216af14 buf;
    buf = data_ov003_0217f578;
    unsigned int locator = data_020e6d5c.b;
    unsigned int fn = data_020e6d5c.a;
    buf.entries[7].locator = locator;
    buf.entries[7].fn = fn;

    if (buf.entries[scene->state].fn == 0) return 0;
    struct DispatchEntry0216af14* d = &buf.entries[scene->state];
    void* base = (char*)scene + ((int)d->locator >> 1);
    void* callback;
    if (d->locator & 1) {
        callback = *(void**)((char*)*(void**)base + d->fn);
    } else {
        callback = (void*)d->fn;
    }
    ((void(*)(void*))callback)(base);
    return 1;
}
