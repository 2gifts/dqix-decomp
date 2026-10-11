// JPN: func_ov017_021b754c
#if defined(jpn)
enum { RegionOffset4400 = 0x4100, RegionOffsetae = 0xfe, RegionOffset6fc = 0x4ec, RegionOffsetb5c = 0x93c };
#else
enum { RegionOffset4400 = 0x4400, RegionOffsetae = 0xae, RegionOffset6fc = 0x6fc, RegionOffsetb5c = 0xb5c };
#endif

#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "GameState/GameState.h"

extern "C" void func_ov000_021604f0(void);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
void PopStack0AndTrigger(int flag);
void PopStack1AndTrigger(int flag);
void SetByteField0x253(void* obj);
struct Obj02053f7c;
void SetField0x1b2IfMatchOrFlag02053f7c(Obj02053f7c* obj, short a, int b);
ARM void EnqueueEventTag127ForParty_021c3f70(unsigned short tag);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);
extern "C" void func_020a0c0c(void);
struct ListHead02046b60;
int ListContainsId(ListHead02046b60* list, int id);
extern "C" void* func_02012fe4(void);
void SetFlagBytes02017d68(void* obj);
void* GetDataPtr02114e04_020d6c00(void);
struct FlagWord020466f4;
void ClearFlags020466f4(FlagWord020466f4* word, unsigned int mask);
struct ResetState020a3578Struct;
void ResetState020a3578(ResetState020a3578Struct* s);

extern AllocatorUnion data_02114e20;

// USA: func_ov017_021b6f9c  (semantic: ResetCombatStateAndFlags_021b6f9c)
extern "C" ARM void func_ov017_021b6f9c(char* self) {
    char* ov = (char*)func_ov017_0218b5b0();
    unsigned short f6b6 = *(unsigned short*)(self + 0x600 + 0xb6);
    int f28 = *(int*)(self + 0x28);
    unsigned int flag2000 = f6b6 & 0x2000;

    unsigned short val44ae = *(unsigned short*)(ov + RegionOffset4400 + RegionOffsetae);
    unsigned short* addr44ae = (unsigned short*)(ov + RegionOffsetae + RegionOffset4400);
    if (val44ae == *(unsigned short*)(self + 0x24)) {
        addr44ae[0] = 0;
        addr44ae[1] = 0;
    }

    if (*(int*)(self + 0x6ac) != 0) {
        func_ov000_021604f0();
    }

    SafeAllocator* alloc = (SafeAllocator*)(self + 0x8);
    void* p = alloc->GetSignedAllocator();
    if (p) {
        alloc->Destroy();
        TailForward02012da4(&data_02114e20, p);
    }

    if (*(unsigned short*)(self + 0x600 + 0xb6) & 0x800) {
        PopStack0AndTrigger(1);
        PopStack1AndTrigger(1);
    }

    GameObject* combatant = GameState::GetInstance()->GetUnknownGameObject();
    SetByteField0x253(combatant);
    SetField0x1b2IfMatchOrFlag02053f7c((Obj02053f7c*)combatant, 0, 0);
    EnqueueEventTag127ForParty_021c3f70(0);

    alloc->ResetAllocatorPointer();
    ResetState020a3578((ResetState020a3578Struct*)(self + 0x1c));

    *(int*)(self + 0x6ac) = 0;
    *(int*)(self + 0x6b0) = 0;
    *(unsigned short*)(self + 0x600 + 0xb4) = 1;
    *(unsigned short*)(self + 0x600 + 0xb6) = 0;
    *(int*)(self + 0x6b8) = 0;

    ClearBitsInWord((unsigned int*)ov, 0x800);
    func_020a0c0c();

    int* p36fc = *(int**)(ov + 0x3000 + RegionOffset6fc);
    char* p3b5c = *(char**)(ov + 0x3000 + RegionOffsetb5c);
    int useDefault;
    if (f28 < 0 || ListContainsId((ListHead02046b60*)p36fc, 4) == 0) {
        useDefault = 1;
    } else {
        useDefault = 0;
    }

    void* ret = func_02012fe4();
    if (useDefault != 0 && flag2000 == 0 && *(unsigned char*)(p3b5c + 8) != 0) {
        SetFlagBytes02017d68(ret);
    }

    ClearFlags020466f4((FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0x40000);
}
