#include <globaldefs.h>
#include "GameState/GameState.h"

int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
struct ListNode020378dc;
extern "C" void _ZN8Object3D6DetachEv(struct ListNode020378dc* node);
struct Node02037890;
extern "C" void _ZN8Object3D6AttachEPS_PKc(struct Node02037890* node, struct Node02037890* src, char* str);

struct In021e7324 {
    char pad[8];
    unsigned char idx1;
    unsigned char idx2;
    char pad2[2];
    char* label;
};

struct DispatchOut021e7324 {
    int id;
    char pad[0x2c];
};

// USA: func_ov025_021e7324
ARM int LinkCombatantsIfDispatched_021e7324(struct In021e7324* a, int b, int unused, void* obj) {
    struct DispatchOut021e7324 out1;
    struct DispatchOut021e7324 out2;
    int found1 = DispatchByIndex021820bc(obj, b, a->idx1, (int)&out1.id);
    int found2 = DispatchByIndex021820bc(obj, b, a->idx2, (int)&out2.id);
    if (!found1 || !found2) {
        return 1;
    }
    GameState* bs = GameState::GetInstance();
    GameObject* c1 = bs->GetGameObjectByIndex(out1.id);
    GameObject* c2 = bs->GetGameObjectByIndex(out2.id);
    if (!c1 || !c2) {
        return 1;
    }
    _ZN8Object3D6DetachEv((struct ListNode020378dc*)c1);
    _ZN8Object3D6AttachEPS_PKc((struct Node02037890*)c1, (struct Node02037890*)c2, a->label);
    return 1;
}
