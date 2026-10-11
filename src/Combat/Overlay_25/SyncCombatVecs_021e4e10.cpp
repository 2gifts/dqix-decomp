#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_02160f14(void* work);
extern "C" void func_ov000_0216d370(int a, int b, int c, int d);
void* GetActiveCombatWork(void);
int GetField0x3b0Value(GameState* battleStruct);
void SetField0x3b0Value(GameState* battleStruct, int value);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
void ApplyVec3Tail(void* obj, int* vec);

struct Inner021e4e10 {
    unsigned int v[3];
};

struct WorkStruct021e4e10 {
    char pad1[0x10];
    struct Inner021e4e10 vecA;
    char pad2[0x70 - 0x1c];
    struct Inner021e4e10 vecB;
};

// USA: func_ov025_021e4e10
ARM int SyncCombatVecs_021e4e10(void) {
    GameState* bs = GameState::GetInstance();
    void* work = GetActiveCombatWork();
    struct WorkStruct021e4e10* p = (struct WorkStruct021e4e10*)(int)GetField0x3b0Value(bs);
    struct Inner021e4e10 vecA = p->vecA;
    struct Inner021e4e10 vecB = p->vecB;
    int val = func_ov000_02160f14(work);
    SetField0x3b0Value(bs, val);
    func_ov000_0216d370(val, 1, 1, 1);
    struct WorkStruct021e4e10* p2 = (struct WorkStruct021e4e10*)(int)GetField0x3b0Value(bs);
    _ZN8Vector3iaSERKS_((int*)&p2->vecA, (int*)&vecA);
    ApplyVec3Tail(p2, (int*)&vecB);
    return 1;
}
