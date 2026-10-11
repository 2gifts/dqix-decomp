#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "System/OverlayId.h"


struct Actor0209c174;
struct Obj_0205e88c;

extern "C" void func_ov011_021848a0(void* self, int state);
extern "C" SafeAllocator* func_ov011_021845f8(void* self, int index);
extern "C" void func_020a1940(unsigned int id);
extern "C" int func_ov031_0221156c(void* data);
void ResetObjectState0205e8d4(void* obj);
void FreeAndReinit0203a950(void* obj);
int ProcessAndClassify_02212cbc(void* data);
int CompareField10PairOrZero_02211608(void* data);
void ResetActor0209c174(Actor0209c174* actor);
void Dispatch0203a974With0x57000(void* obj);
void InitDisplayState0205e88c(Obj_0205e88c* obj);
void SetupContextForMode0205ea20(void* obj, int mode);
extern char data_02108760;
extern char data_02109bf4;

struct Flags0216f634 {
    char pad0[0x30];
    unsigned char b30;
    char pad1;
    unsigned char b32;
    unsigned char b33;
    signed char b34;
};

struct Holder0216f634 {
    int f0;
    Flags0216f634* flags;
};

extern Holder0216f634 data_ov004_02171048;

struct Buffer6380 {
    int f0;
    char data[0x40];
};

// USA: func_ov004_0216f634
// JPN: func_ov004_0216fcc8
extern "C" ARM int func_ov004_0216f634(void* self) {
    if (data_ov004_02171048.flags->b30 == 0) {
        func_ov011_021848a0(self, 0xd3);
    } else {
        GameState* gs = GameState::GetInstance();
        ResetObjectState0205e8d4(&data_02108760);
        FreeAndReinit0203a950(&data_02109bf4);
        func_020a1940(OVERLAY_ID(31));
        SafeAllocator* allocator = func_ov011_021845f8(self, 0);
        if (allocator == NULL) {
            return 0;
        }
        data_ov004_02171048.flags->b34 = ProcessAndClassify_02212cbc(((SafeAllocator*)((char*)allocator + 4))->Allocate(0x700));
        char buf[0x40];
#if defined(jpn)
        memcpy(buf, &((Buffer6380*)((char*)gs + 0x6120))->data, 0x40);
#else
        memcpy(buf, &((Buffer6380*)((char*)gs + 0x6380))->data, 0x40);
#endif
        data_ov004_02171048.flags->b32 = func_ov031_0221156c(buf) != 0;
        data_ov004_02171048.flags->b33 = CompareField10PairOrZero_02211608(buf) != 0;
        func_020a1940(OVERLAY_ID(32));
        ResetActor0209c174((Actor0209c174*)&data_02109bf4);
        Dispatch0203a974With0x57000(&data_02109bf4);
        InitDisplayState0205e88c((Obj_0205e88c*)&data_02108760);
        SetupContextForMode0205ea20(&data_02108760, 100);
        if (data_ov004_02171048.flags->b34 == 3) {
            func_ov011_021848a0(self, 0xd4);
            return 0;
        }
        func_ov011_021848a0(self, 100);
    }
    return 0;
}
