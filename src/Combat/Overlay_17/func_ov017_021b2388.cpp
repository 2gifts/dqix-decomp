// JPN: func_ov017_021b2aa0
#if defined(jpn)
enum { RegionOffset3700 = 0x34f0 };
#else
enum { RegionOffset3700 = 0x3700 };
#endif

#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "std_library_functions.h"

int GetFieldIfFlag4(char* obj);
unsigned int GetField4(unsigned int* obj);
struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);
void SetFlagsAt0x244(unsigned char* obj, unsigned char mask);
void ClearIntAt0x23c(unsigned char* obj);
int IsField0Null(void** obj);
void SetBitsInWord(unsigned int* obj, unsigned int mask);
extern "C" void func_020a0cc4(unsigned int);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_020c9be0(void);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void* obj, int value, int frames);
struct ResetObj020d7a5c;
struct ResetObj020d7a5c* GetGlobalResetObj020d7a50();
struct Obj020d7aa0;
void TeardownAndResetState020d7aa0(struct Obj020d7aa0* obj);

extern int data_02114e20;
extern char data_ov017_021d7a28;

struct Flags38_021b2388 {
    unsigned int lowBits : 4;
    unsigned int bit4 : 1;
    unsigned int rest : 27;
};

struct Obj021b2388 {
    char pad0[0x8];
    int field8;
    int fieldc;
    SafeAllocator allocator;   // 0x10
    char name[0x14];           // 0x24
    struct Flags38_021b2388 field38;  // 0x38
    char pad2[0x2];
    unsigned char field3e;     // 0x3e
    unsigned int field40;      // 0x40
    void* field44;             // 0x44
};

// USA: func_ov017_021b2388  (semantic: InitMenuAllocatorAndLoadData_021b2388)
extern "C" ARM int func_ov017_021b2388(struct Obj021b2388* ctx) {
    GameState* battle = (GameState*)GameState::GetInstance();
    int base = ((int)func_ov017_0218b5b0());
    unsigned char* fieldPtr;
    GameObject* combatant = battle->GetUnknownGameObject();
    fieldPtr = (unsigned char*)GetFieldIfFlag4((char*)battle);
    int loadedList = (int)BackgroundLoader::GetInstance();
    void** entry = *(void***)((char*)base + RegionOffset3700);
    unsigned int val40 = GetField4((unsigned int*)base);
    ctx->field40 = val40;

    if (combatant) {
        CancelPendingAction020397cc((struct Obj020397cc*)combatant, 1);
    }

    if (fieldPtr) {
        ctx->field3e = (fieldPtr[0x244] & 2) != 0;
        SetFlagsAt0x244(fieldPtr, 2);
        ClearIntAt0x23c(fieldPtr);
        ctx->field44 = fieldPtr;
    }

    if (!IsField0Null(entry)) {
        return ctx->field8;
    }

    SetBitsInWord((unsigned int*)base, 0x10);
    func_020a0cc4(0x2f800);
    void* buf = AllocateAligned4((AllocatorUnion*)&data_02114e20, 0x2f800);
    if (!buf) {
        func_020c9be0();
    }
    ctx->allocator.CreateTypeA(buf, 0x2f800);

    char tmp[0x50];
    sprintf(tmp, &data_ov017_021d7a28, ctx->name);
    ctx->fieldc = ((BackgroundLoader*)(loadedList))->QueueLoadFile((const char*)((int)tmp), (SafeAllocator*)((int)&ctx->allocator));

    if (!ctx->field38.bit4) {
        _Z13SetBrightnessP13GameResourcesii((void*)base, -16, 30);
    }

    TeardownAndResetState020d7aa0((struct Obj020d7aa0*)GetGlobalResetObj020d7a50());
    return 1;
}
