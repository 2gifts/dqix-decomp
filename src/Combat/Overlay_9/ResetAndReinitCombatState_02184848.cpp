#if defined(jpn)
#define R(j,u) (j)
#define _Z25ResetBattleObject0203c4c4Pc func_0203c628
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void* _Z27GetDataPtr02114e04_020d6c00v(void);
struct FlagWord020466f4;
extern "C" void _Z18ClearFlags020466f4P16FlagWord020466f4j(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void _Z25DestroyTenAndOne_021e4f18Pv(void* obj);
extern "C" int _Z26GetGlobalField0x1c020421a0v();
struct CombatSlots02045cac;
extern "C" void _Z23InitCombatSlots02045cacP19CombatSlots02045cac(struct CombatSlots02045cac* obj);
extern "C" void _Z24ReinitController02043204Pc(char* obj);
extern "C" void func_02043124(char* obj);
extern "C" void _Z23EmptyDestructor0205a494Pv(void* obj);
void* GetGlobalPtr02105244();
extern "C" void _Z25ResetBattleObject0203c4c4Pc(char* obj);
struct Obj0204b010;
extern "C" void _Z19ClearBuffer0204b010P11Obj0204b010Pv(Obj0204b010* obj, void* p);
extern "C" void func_0204b04c(void* p, int flag);
extern "C" void func_0204b088(void* p, int flag);
struct List0204afb4;
extern "C" void _Z23ResetRecordList0204afb4P12List0204afb4(struct List0204afb4* obj);
struct Obj0205d048;
extern "C" void func_0205d048(struct Obj0205d048* obj);
extern "C" void* __clear(void* dst, int count);

// USA: func_ov009_02184848  (semantic: ResetAndReinitCombatState_02184848)
extern "C" ARM void func_ov009_02184848(char* obj) {
    if (*(unsigned char*)(obj + R(0xd59,0xd95)) == 1) {
        _Z18ClearFlags020466f4P16FlagWord020466f4j((struct FlagWord020466f4*)_Z27GetDataPtr02114e04_020d6c00v(), 0xf);
    }

    _Z25DestroyTenAndOne_021e4f18Pv(*(void**)(obj + R(0x7b4,0x7f0)));
    _Z25DestroyTenAndOne_021e4f18Pv(*(void**)(obj + R(0x7b8,0x7f4)));

    void* g = (void*)_Z26GetGlobalField0x1c020421a0v();
    _Z23InitCombatSlots02045cacP19CombatSlots02045cac((struct CombatSlots02045cac*)g);
    _Z24ReinitController02043204Pc((char*)g);
    func_02043124((char*)g);

    if (*(void**)(obj + R(0x79c,0x7d8)) != 0) {
        _Z23EmptyDestructor0205a494Pv(*(void**)(obj + R(0x79c,0x7d8)));
    }
    if (*(void**)(obj + R(0x7a8,0x7e4)) != 0) {
        _Z23EmptyDestructor0205a494Pv(*(void**)(obj + R(0x7a8,0x7e4)));
    }
    _Z25ResetBattleObject0203c4c4Pc((char*)GetGlobalPtr02105244());

    {
        void* arr[6];
        arr[0] = obj + R(0xfc,0x138);
        arr[1] = obj + R(0x11c,0x158);
        arr[2] = obj + R(0x13c,0x178);
        arr[3] = obj + R(0x15c,0x198);
        arr[4] = obj + R(0x17c,0x1b8);
        arr[5] = obj + R(0x19c,0x1d8);
        for (int i = 0; i < 6; i++) {
            void* p = arr[i];
            _Z19ClearBuffer0204b010P11Obj0204b010Pv((Obj0204b010*)p, 0);
            func_0204b04c(p, 0);
            func_0204b088(p, 0);
            _Z23ResetRecordList0204afb4P12List0204afb4((struct List0204afb4*)p);
        }
    }

    func_0205d048((struct Obj0205d048*)(obj + R(0x1bc,0x1f8)));
    func_0205d048((struct Obj0205d048*)(obj + R(0x278,0x2b4)));
    *(int*)(obj + R(0xd8,0xf8)) = 0;
    *(int*)(obj + R(0x794,0x7d0)) = 0;
    *(int*)(obj + R(0x798,0x7d4)) = 0;

    if (*(void**)(obj + R(0xa4,0xb8)) != 0) {
        ((SafeAllocator*)(*(void**)(obj + R(0xa4,0xb8))))->Destroy();
        ((SafeAllocator*)((char*)(*(void**)(obj + R(0xa4,0xb8))) + 0x14))->Destroy();
    }
    if (*(void**)(obj + R(0xa0,0xb4)) != 0) {
        ((SafeAllocator*)(*(void**)(obj + R(0xa0,0xb4))))->Destroy();
    }

    SafeAllocator* arr2[R(9,10)];
    __clear(arr2, R(0x24,0x28));
#if defined(jpn)
    arr2[0] = (SafeAllocator*)(obj + 0x8c);
    arr2[1] = (SafeAllocator*)(obj + 0x78);
    arr2[2] = (SafeAllocator*)(obj + 0x64);
    arr2[3] = (SafeAllocator*)(obj + 0x50);
    arr2[4] = (SafeAllocator*)(obj + 0x3c);
    arr2[5] = (SafeAllocator*)(obj + 0x28);
    arr2[6] = (SafeAllocator*)(obj + 0x14);
    arr2[7] = (SafeAllocator*)obj;
#else
    arr2[0] = (SafeAllocator*)(obj + 0xa0);
    arr2[1] = (SafeAllocator*)(obj + 0x8c);
    arr2[2] = (SafeAllocator*)(obj + 0x78);
    arr2[3] = (SafeAllocator*)(obj + 0x64);
    arr2[4] = (SafeAllocator*)(obj + 0x50);
    arr2[5] = (SafeAllocator*)(obj + 0x3c);
    arr2[6] = (SafeAllocator*)(obj + 0x28);
    arr2[7] = (SafeAllocator*)(obj + 0x14);
    arr2[8] = (SafeAllocator*)obj;
#endif

    int i = 0;
    while (arr2[i] != 0) {
        if (arr2[i]->GetSignedAllocator() != 0) {
            arr2[i]->Destroy();
        }
        i++;
    }
}
