#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "System/Cache.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"

void* GetWord0x0(int*);
struct GameResources;
void SetBrightness(GameResources*, int, int);

struct Obj02097b34;
extern "C" void func_02097b34(struct Obj02097b34* obj);

struct Struct02074bd0;
void ClearFlag0x10IfSet(struct Struct02074bd0* obj);

extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);

void TailCallInit_021d98d4(void* obj);
extern "C" void func_ov028_021d8b90(void* obj);

void ClearBitsInWord(unsigned int* obj, unsigned int mask);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);
void ClearBitsInField8(unsigned int* obj, unsigned int mask);
void SetBitsInWord(unsigned int* obj, unsigned int mask);
void SetBitsInField4(unsigned int* obj, unsigned int mask);
void SetBitsInField8(unsigned int* obj, unsigned int mask);

// USA: func_ov028_021d8c20  (semantic: ResetStateAndCounters_021d8c20)  (semantic: ResetStateAndCounters_021d8c20)
extern "C" ARM void func_ov028_021d8c20(char* self) {
    void* battle = GameState::GetInstance();
    void* word = GetWord0x0((int*)battle);
    SetBrightness((GameResources*)word, -16, 0);

    *(int*)0x4000014 = 0;
    *(int*)0x4001014 = 0;

    if (((SafeAllocator*)(self + 0x44))->GetSignedAllocator() != 0) {
        ((SafeAllocator*)(self + 0x44))->Destroy();
    }
    func_02097b34((struct Obj02097b34*)(self + 0x20));
    ClearFlag0x10IfSet((struct Struct02074bd0*)(self + 0xc));

    void* buf = *(void**)(self + 0x40);
    if (buf != 0) {
        memset(buf, 0, 0x20);
        buf = *(void**)(self + 0x40);
        CleanInvalidateCacheRange(buf, 0x20);
        buf = *(void**)(self + 0x40);
        LoadToMainBG1CharacterData((int)buf, 0, 0x20);
    }

    TailCallInit_021d98d4(self);

    unsigned int* word32 = (unsigned int*)word;
    ClearBitsInWord(word32, ~0u);
    ClearBitsInField4(word32, ~0u);
    ClearBitsInField8(word32, ~0u);
    SetBitsInWord(word32, *(unsigned int*)(self + 0x74));
    SetBitsInField4(word32, *(unsigned int*)(self + 0x78));
    SetBitsInField8(word32, *(unsigned int*)(self + 0x7c));

    unsigned int* reg0 = (unsigned int*)0x4000000;
    *reg0 = (*reg0 & ~0x1f00) | (*(unsigned int*)(self + 0x58) << 8);
    unsigned int* reg1 = (unsigned int*)0x4001000;
    *reg1 = (*reg1 & ~0x1f00) | (*(unsigned int*)(self + 0x5c) << 8);

    func_ov028_021d8b90(self);
}
