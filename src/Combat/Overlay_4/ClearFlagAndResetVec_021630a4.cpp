#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3_021630a4 { unsigned int v[3]; };

class Node021630a4 {
    char pad4[8];
public:
    unsigned char field0xc;
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void SetVal0x1c(const Vec3_021630a4& v);
    virtual Vec3_021630a4 GetVal0x20();
};

extern "C" Node021630a4* func_ov004_0215e47c(void* a, int key);
void SetField0x3b0Value(GameState* battleStruct, int value);

extern int data_ov004_021707e8;

// USA: func_ov004_021630a4  (semantic: ClearFlagAndResetVec_021630a4)
extern "C" ARM int func_ov004_021630a4(void* a) {
#if defined(jpn)
    enum { stateFieldOffset = 0x18 };
#else
    enum { stateFieldOffset = 0x10 };
#endif
    Node021630a4* node = func_ov004_0215e47c(a, 9);
    node->field0xc &= ~0x80;
    Vec3_021630a4 v2;
    const Vec3_021630a4& v = node->GetVal0x20();
    v2 = v;
    v2.v[0] = 0;
    v2.v[1] = 0;
    v2.v[2] = 0;
    node->SetVal0x1c(v2);
    SetField0x3b0Value(GameState::GetInstance(), *(int*)((char*)&data_ov004_021707e8 + stateFieldOffset));
    return 0;
}
