#include <globaldefs.h>
#if defined(jpn)
enum { kRegion72c = 0x628 };
#else
enum { kRegion72c = 0x72c };
#endif

#if defined(jpn)
extern "C" void func_ov003_021714f0(void*);
#endif
#include "GameState/GameState.h"

struct SearchStruct;
struct SearchStruct0202c1a4;
struct Obj_02172518;

extern "C" void* func_0202ae18(void);
extern "C" void func_0202b0f4(void* p);
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
void SetSearchFlagBitAt0xc(struct SearchStruct* obj, int value);
extern "C" void func_0202c288(void* obj);
void LoopCallOv017_02172518(struct Obj_02172518* obj, int flag);

struct Obj02171af0 {
    unsigned char field0;
    char pad1[0x199 - 1];
    unsigned char field199;
    char pad2[0x1b1 - 0x19a];
    unsigned char pad1b1lo : 6;
    unsigned char flag1b1 : 1;
    unsigned char pad1b1hi : 1;
    char pad3[kRegion72c - 0x1b2];
    unsigned int field72c;
};

// JPN: func_ov003_02170dc0
// USA: func_ov003_02171af0  (semantic: UpdateSearchAndDispatch_02171af0)
extern "C" ARM void func_ov003_02171af0(struct Obj02171af0* obj) {
    GameState* battle = GameState::GetInstance();
    void* ptr = func_0202ae18();

    obj->field72c += battle->GetEffectiveDeltaTime();
    if (obj->field72c > 0xbb8) {
        func_0202b0f4(ptr);
        obj->field72c = 0;
        obj->field0 = 0;
    }

    if (GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)ptr) <= 0) {
        return;
    }

    signed char entry = GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)ptr);
    SetSearchFlagBitAt0xc((struct SearchStruct*)ptr, entry);
    SetSearchFlagBitAt0xc((struct SearchStruct*)ptr, obj->field199);
    func_0202c288(ptr);

#if defined(jpn)
    func_ov003_021714f0(obj);
#else
    int flag = obj->flag1b1 ? 1 : 0;
    LoopCallOv017_02172518((struct Obj_02172518*)obj, flag);
#endif
    obj->field0 = 7;
}
