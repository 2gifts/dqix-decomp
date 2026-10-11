#if defined(jpn)
enum { RegionalSize = 0xe0 };
#else
enum { RegionalSize = 0xe4 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"

extern "C" void func_020a0cc4(unsigned int);
extern "C" void func_020a0c0c(void);
extern "C" int func_ov003_0217ce3c(void*);
extern "C" int func_ov017_021959b4(void);
extern "C" int func_ov003_0217daf0(void*);
extern "C" void func_ov003_0217cd24(void*, void*);
extern "C" void func_020dae08(void*);

struct Struct02012dd0;
unsigned int GetMaxAlloc02012dd0(struct Struct02012dd0* self);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion data_02114e20;

void SetBitsInField4(unsigned int* obj, unsigned int mask);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);
void ClearFlagBits(unsigned char* obj, int mask);
int GetFieldIfFlag4(char* obj);
void ClearIntAt0x23c(unsigned char* obj);
void SetField0x23cTrue(void* obj);
void SetByteField0x253(void* obj);
void PushInputLogA(int id);
void ClearCombatantEncounterState(void* obj);

struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);

struct EncounterState020dac94 {
    char pad0;
    unsigned char flag1;
    char pad2[0xa];
    void* field0xc;
    int state;
    SafeAllocator allocator;
};

// USA: func_020dac94
// JPN: func_020dac94
ARM void UpdateEncounterState020dac94(void* objIn) {
    struct EncounterState020dac94* obj = (struct EncounterState020dac94*)objIn;
    GameState* battle = GameState::GetInstance();
    int state = obj->state;
    if (state == 0) {
        SetBitsInField4((unsigned int*)func_ov017_0218b5b0(), 0xc0);
        unsigned int max = GetMaxAlloc02012dd0((struct Struct02012dd0*)&data_02114e20);
        if (max < 0x6000) {
            func_020a0cc4(0x6000);
        }
        void* buf = AllocateAligned4(&data_02114e20, 0x6000);
        if (buf == NULL) {
            func_020a0c0c();
            obj->flag1 = 1;
            return;
        }
        obj->allocator.CreateTypeA(buf, 0x6000);
        obj->allocator.Reset();
        void* mem = obj->allocator.Allocate(RegionalSize);
        obj->field0xc = mem;
        if (mem == NULL) {
            func_020a0c0c();
            obj->flag1 = 1;
            return;
        }
        PushInputLogA(3);
        func_ov003_0217daf0(obj->field0xc);
        func_ov003_0217cd24(obj->field0xc, &obj->allocator);
        GameObject* c = battle->GetUnknownGameObject();
        CancelPendingAction020397cc((struct Obj020397cc*)c, 1);
        int flagResult = GetFieldIfFlag4((char*)battle);
        ClearIntAt0x23c((unsigned char*)flagResult);
        obj->state = 1;
        return;
    }
    if (state == 1) {
        void* v = obj->field0xc;
        if (func_ov003_0217ce3c(v) == 0) {
            obj->state = 2;
        }
        if (func_ov017_021959b4() != 0) {
            ClearCombatantEncounterState(objIn);
            obj->state = 3;
        }
        return;
    }
    if (state != 2) {
        return;
    }
    func_020dae08(objIn);
    GameObject* c = battle->GetUnknownGameObject();
    SetByteField0x253(c);
    int flagResult = GetFieldIfFlag4((char*)battle);
    SetField0x23cTrue((void*)flagResult);
    ClearFlagBits((unsigned char*)flagResult, 2);
    ClearBitsInField4((unsigned int*)func_ov017_0218b5b0(), 0xc0);
    obj->state = -1;
}
