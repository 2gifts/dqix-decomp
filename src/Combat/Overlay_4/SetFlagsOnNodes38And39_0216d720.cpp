#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void** func_ov011_021849c8(void* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);
void SetFieldShortAt46_021f9c60(void* obj, unsigned short v);

class VNode0216d720 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16();
    virtual void Method44(int a);
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30();
    virtual void Method7c(int a);
    char pad[8];
    unsigned char fieldC;
};
extern "C" VNode0216d720* func_ov023_021f6880(void** list, int value);

// USA: func_ov004_0216d720  (semantic: SetFlagsOnNodes38And39_0216d720)
extern "C" ARM int func_ov004_0216d720(void* a0) {
    GameState::GetInstance();
    VNode0216d720* node = func_ov023_021f6880(func_ov011_021849c8(a0), 0x38);
    if (node) {
        node->Method44(0);
        node->Method7c(0);
        node->fieldC |= 0x50;
    }
    VNode0216d720* node2 = func_ov023_021f6880(func_ov011_021849c8(a0), 0x39);
    if (node2) {
        node2->Method44(0);
        node2->Method7c(0);
        node2->fieldC |= 0x50;
    }
    VNode0216d720* node3 = func_ov023_021f6880(func_ov011_021849c8(a0), 0x12d);
    if (node3) {
        SetFieldShortAt46_021f9c60(node3, 0);
    }
    func_ov011_021848a0(a0, 0x2bd);
    return 0;
}
