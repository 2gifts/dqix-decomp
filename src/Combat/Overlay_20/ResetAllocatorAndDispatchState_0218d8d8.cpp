#include <globaldefs.h>

#if defined(jpn)
enum { kAllocatorOffset = 0x400 };
#else
enum { kAllocatorOffset = 0x470 };
#endif

#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

void TailForward02012da4(AllocatorUnion* alloc, void* data);
unsigned char GetByte0x4(char* obj);

struct Actor0209c678;
void DispatchContextByState0209c678(struct Actor0209c678* actor, int arg);

struct Actor0209c20c;
void InitActorContext0209c20c(struct Actor0209c20c* actor);

struct Obj_0205e8ec;
void RefreshDisplayState0205e8ec(struct Obj_0205e8ec* a);

extern AllocatorUnion data_02114e20;
extern char data_02109bf4;
extern char data_02108760;

struct AllocGroup0218d8d8 {
    char pad[kAllocatorOffset];
    SafeAllocator allocator;
};

// USA: func_ov020_0218d8d8
ARM void ResetAllocatorAndDispatchState_0218d8d8(struct AllocGroup0218d8d8* obj) {
    GameState* battleStruct = GameState::GetInstance();
    SignedAllocatorHeader* header = obj->allocator.GetSignedAllocator();
    obj->allocator.Destroy();
    TailForward02012da4(&data_02114e20, header);
    if (GetByte0x4((char*)battleStruct) == 2) {
        return;
    }
    DispatchContextByState0209c678((struct Actor0209c678*)&data_02109bf4, 0);
    InitActorContext0209c20c((struct Actor0209c20c*)&data_02109bf4);
    RefreshDisplayState0205e8ec((struct Obj_0205e8ec*)&data_02108760);
}
